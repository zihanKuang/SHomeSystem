// api.c - 通信接口类的实现

#include "api.h" // 包含通信接口类的头文件

const int MAX_REQUEST_SIZE = 1024;

// 处理网络连接测试请求
void handleNetworkConnectionTest(struct MHD_Connection* connection) {
    const char* response = "Network connection is available.\n";
    struct MHD_Response* mhdResponse = MHD_create_response_from_buffer(strlen(response),
        (void*)response,
        MHD_RESPMEM_MUST_COPY); // 使用 MHD_RESPMEM_MUST_COPY 来复制响应数据
    MHD_add_response_header(mhdResponse, "Content-Type", "text/plain");
    MHD_queue_response(connection, MHD_HTTP_OK, mhdResponse);
    MHD_destroy_response(mhdResponse);
}

// 验证用户身份是否合法
bool validateUser(const char* username, const char* password)
{
    // 从数据库中获取用户信息
    char db_pass[32];
    bool userExists = getUserData(db,username, db_pass);

    if (userExists && strncmp(db_pass, password, 32) == 0)
    {
        printf("validateUser 2222");
        // 用户存在且密码匹配，验证通过
        return true;
    }

    // 验证失败，返回false
    return false;
}

// 将对象数据序列化为JSON格式
const char* serializeToJson(const void* object)
{
    // 实现将对象数据序列化为JSON格式的逻辑
    // 返回JSON格式的字符串
    return "{}";
}

// 将JSON反序列化为对象
void* deserializeFromJson(const char* json, size_t size)
{
    // 实现将JSON反序列化为对象的逻辑
    // 返回对象指针
    return NULL;
}

// 处理网络错误等异常情况
void handleException(const char* message)
{
    // 处理网络错误等异常情况的逻辑
    printf("Exception occurred: %s\n", message);
}

// 处理用户注册请求与信息验证
void handleUserRegister(const char* request, struct MHD_Connection* connection) 
{
    // 从请求中获取用户名和密码
    const char* username = MHD_lookup_connection_value(connection, MHD_GET_ARGUMENT_KIND, "username");
    const char* password = MHD_lookup_connection_value(connection, MHD_GET_ARGUMENT_KIND, "password");

    //printf("Received username: %s\n", username);
    //printf("Received password: %s\n", password);

    if (username && password) {
        // 保存到数据库
        if (saveUser(db,username, password)) {

            // 返回响应
            cJSON* resp = cJSON_CreateObject();
            cJSON_AddBoolToObject(resp, "success", 1);
            cJSON_AddStringToObject(resp, "message", "注册成功"); // 添加注册成功的消息
            printf("注册成功");
            char* response_str = cJSON_Print(resp);

            // 发送HTTP响应
            struct MHD_Response* http_response = MHD_create_response_from_buffer(strlen(response_str),
                (void*)response_str,
                MHD_RESPMEM_MUST_COPY);
            MHD_add_response_header(http_response, "Content-Type", "application/json");
            int ret = MHD_queue_response(connection, MHD_HTTP_OK, http_response);

            cJSON_Delete(resp);
            free(response_str);
        }
        else {
            handleException("Error saving user");
        }
    }
    else {
        handleException("Missing username or password");
    }
}


// 处理用户登录请求与验证
void handleUserLogin(const char* request, struct MHD_Connection* connection)
{
    // 从请求中获取用户名和密码
    const char* username = MHD_lookup_connection_value(connection, MHD_GET_ARGUMENT_KIND, "username");
    const char* password = MHD_lookup_connection_value(connection, MHD_GET_ARGUMENT_KIND, "password");

    printf("Received username: %s\n", username);
    printf("Received password: %s\n", password);

    if (username && password) {
        // 验证用户
        bool isValidUser = validateUser(username, password);

        // 创建响应 JSON 对象
        cJSON* response = cJSON_CreateObject();
        if (isValidUser) {
            cJSON_AddBoolToObject(response, "success", 1);
        }
        else {
            cJSON_AddBoolToObject(response, "success", 0);
        }

        // 将响应 JSON 对象转换为字符串
        char* response_str = cJSON_Print(response);

        // 发送HTTP响应
        struct MHD_Response* http_response = MHD_create_response_from_buffer(strlen(response_str),
            (void*)response_str,
            MHD_RESPMEM_MUST_COPY);
        MHD_add_response_header(http_response, "Content-Type", "application/json");
        int ret = MHD_queue_response(connection, MHD_HTTP_OK, http_response);
        
        // 清理资源
        cJSON_Delete(response);
        free(response_str);
        MHD_destroy_response(http_response); // 销毁响应对象
    }
    else {
        handleException("Missing username or password");
    }
}


//// 分析用户数据,生成统计报告
//void analyzeSensorData() {
//
//  // 1. 从数据库获取温湿度数据
//  char* sql = "SELECT * FROM EnvironmentData";
//  queryDataFromDB(sql);
//
//  // 2. 统计分析,生成温湿度折线图数据
//  double temp_data[100];
//  double humid_data[100];
//
//  // 3. 生成柱状图数据
//  int energy_data[5];
//  int runtime_data[5];
//
//  // 4. 将统计结果序列化为JSON
//  cJSON* analysis = generateResultJson(temp_data, humid_data, energy_data, runtime_data);
//
//  // 5. 返回给客户端 
//  sendHttpResp(200, "application/json", analysis);
//
//}

// 定义回调函数来处理接收到的响应数据
size_t writeCallback(void* contents, size_t size, size_t nmemb, void* userp) 
{
    size_t totalSize = size * nmemb;
    char* response = (char*)userp;

    // 将响应数据复制到用户指定的缓冲区
    memcpy(response, contents, totalSize);

    return totalSize;
}

// 获取天气数据
const char* fetchWeatherData() {
    // 使用网络库获取天气数据，可以调用外部 API
    // 使用高德地图天气API获取天气数据
    const char* url = "https://restapi.amap.com/v3/weather/weatherInfo";
    const char* key = "f8129a5e0cac5b3982285cbc817f9a91";
    const char* city = "武汉"; // 需要查询的城市

        // 构建请求URL
    char requestUrl[1024];
    snprintf(requestUrl, sizeof(requestUrl), "%s?city=%s&key=%s", url, city, key);

    // 初始化libcurl
    CURL* curl = curl_easy_init();
    if (!curl) {
        fprintf(stderr, "Failed to initialize libcurl\n");
        return NULL;
    }

    // 设置请求URL
    curl_easy_setopt(curl, CURLOPT_URL, requestUrl);

    // 设置写回调函数
    char responseBuffer[4096]; // 假设响应数据不超过 4096 字节
    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, writeCallback);
    curl_easy_setopt(curl, CURLOPT_WRITEDATA, responseBuffer);

    // 执行HTTP GET请求
    CURLcode res = curl_easy_perform(curl);
    if (res != CURLE_OK) {
        fprintf(stderr, "Failed to perform GET request: %s\n", curl_easy_strerror(res));
        curl_easy_cleanup(curl);
        return NULL;
    }

    // 分配堆上的内存来存储响应数据
    char* weatherData = strdup(responseBuffer);

    curl_easy_cleanup(curl);

    return weatherData;
}

// 处理获取天气数据请求
void handleWeatherRequest(struct MHD_Connection* connection) {

    const char* weather_data = fetchWeatherData();

    // 构造JSON响应
    cJSON* jsonResponse = cJSON_CreateObject();
    cJSON_AddStringToObject(jsonResponse, "weather", weather_data);
    const char* responseStr = cJSON_Print(jsonResponse);

    // 设置响应头
    struct MHD_Response* response = MHD_create_response_from_buffer(strlen(responseStr),
        (void*)responseStr, MHD_RESPMEM_MUST_COPY);
    MHD_add_response_header(response, "Content-Type", "application/json");

    // 发送响应
    int ret = MHD_queue_response(connection, MHD_HTTP_OK, response);

    // 释放资源
    MHD_destroy_response(response);
    cJSON_Delete(jsonResponse);
}

// 处理空调设备日总耗电分析请求
void analyzeDataAirTotalPower(struct MHD_Connection* connection, const char* request) 
{
    // 解析请求，获取设备名称
    const char* deviceName = MHD_lookup_connection_value(connection, MHD_GET_ARGUMENT_KIND, "deviceName");

    printf("deviceName: %s\n", deviceName);

    if (deviceName != NULL) {
        // 获取设备ID
        int deviceID = getDeviceID(db, deviceName);

        printf("deviceID:%d\n",deviceID);

        if (deviceID != -1) {
            // 获取设备信息
            struct Device airDevice;
            if (getDevice(db, deviceName, &airDevice)) {

                // 输出设备信息
            printf("Device ID: %d\n", airDevice.DeviceID);
            printf("Device Name: %s\n", airDevice.DeviceName);
            printf("Device Type: %s\n", airDevice.Type);
            printf("User ID: %d\n", airDevice.UserID);

                // 计算总耗电量
                    double totalPower = calculateAirTotalPower(&airDevice);
                    printf("totalPower:%f\n",totalPower);

                    // 构建JSON响应
                    cJSON* jsonResponse = cJSON_CreateObject();
                    cJSON_AddNumberToObject(jsonResponse, "totalPower", totalPower);

                    // 将 JSON 响应转换为字符串
                    char* responseStr = cJSON_Print(jsonResponse);

                    // 创建 MHD_Response 对象
                    struct MHD_Response* response = MHD_create_response_from_buffer(strlen(responseStr),
                        (void*)responseStr,
                        MHD_RESPMEM_MUST_COPY);

                    // 设置 HTTP 响应头
                    MHD_add_response_header(response, "Content-Type", "application/json");

                    // 发送 HTTP 响应给客户端
                    MHD_queue_response(connection, MHD_HTTP_OK, response);

                    // 释放 MHD_Response 和 cJSON 对象
                    MHD_destroy_response(response);
                    cJSON_Delete(jsonResponse);
            }
            else {
                printf("Failed to retrieve device information.\n");
            }
        }
        else {
            printf("Device not found.\n");
        }
    }
    else {
        printf("Invalid request.\n");
    }
}


// 处理 灯 设备 日 总耗电分析请求
void analyzeDataLightTotalPower(struct MHD_Connection* connection, const char* request)
{
    // 解析请求，获取设备名称
    const char* deviceName = MHD_lookup_connection_value(connection, MHD_GET_ARGUMENT_KIND, "deviceName");

    printf("deviceName: %s\n", deviceName);

    if (deviceName != NULL) {

        // 获取设备ID
        int deviceID = getDeviceID(db, deviceName);

        printf("deviceID:%d\n",deviceID);

        if (deviceID != -1) {
            // 获取设备信息
            struct Device lightDevice;

            if (getDevice(db,deviceName, &lightDevice)) {
                
                 // 输出设备信息
            printf("Device ID: %d\n", lightDevice.DeviceID);
            printf("Device Name: %s\n", lightDevice.DeviceName);
            printf("Device Type: %s\n", lightDevice.Type);
            printf("User ID: %d\n", lightDevice.UserID);

                    // 计算总耗电量
                    double totalPower = calculateLightTotalPower(&lightDevice);
                    printf("totalPower:%f\n",totalPower);

                    // 构建JSON响应
                    cJSON* jsonResponse = cJSON_CreateObject();
                    cJSON_AddNumberToObject(jsonResponse, "totalPower", totalPower);

                    // 将 JSON 响应转换为字符串
                    char* responseStr = cJSON_Print(jsonResponse);

                    // 构建 HTTP 响应
                    struct MHD_Response* response = MHD_create_response_from_buffer(strlen(responseStr),
                        (void*)responseStr,
                        MHD_RESPMEM_MUST_COPY);

                    // 设置 HTTP 响应头
                    MHD_add_response_header(response, "Content-Type", "application/json");

                    // 发送 HTTP 响应给客户端
                    MHD_queue_response(connection, MHD_HTTP_OK, response);

                    // 释放 MHD_Response
                    MHD_destroy_response(response);
            }
            else {
                printf("Failed to open database.\n");
            }
        }
        else
        {
            // 设备数据不存在，返回错误信息
            printf("Device data not found.\n");
        }
    }
    else
    {
        // 请求中没有包含必要的信息，返回错误信息
        printf("Invalid request.\n");
        }
}


// 处理 加湿器 设备 日 总耗电分析请求
void analyzeDataHumidityTotalPower(struct MHD_Connection* connection, const char* request)
{
    // 解析请求，获取设备名称
    const char* deviceName = MHD_lookup_connection_value(connection, MHD_GET_ARGUMENT_KIND, "deviceName");

    printf("deviceName: %s\n", deviceName);

    if (deviceName != NULL) 
    {
        // 获取设备ID
        int deviceID = getDeviceID(db, deviceName);
        printf("deviceID:%d\n", deviceID);

        if (deviceID != -1) 
        {
            // 获取设备信息
            struct Device humidityDevice;
            if (getDevice(db, deviceName, &humidityDevice)) 
            {
                // 输出设备信息
                printf("Device ID: %d\n", humidityDevice.DeviceID);
                printf("Device Name: %s\n", humidityDevice.DeviceName);
                printf("Device Type: %s\n", humidityDevice.Type);
                printf("User ID: %d\n", humidityDevice.UserID);

                // 计算总耗电量
                double totalPower = calculateHumidityTotalPower(&humidityDevice);

                // 构建JSON响应
                cJSON* jsonResponse = cJSON_CreateObject();
                cJSON_AddNumberToObject(jsonResponse, "totalPower", totalPower);

                // 将 JSON 响应转换为字符串
                char* responseStr = cJSON_Print(jsonResponse);

                // 构建 HTTP 响应
                struct MHD_Response* response = MHD_create_response_from_buffer(strlen(responseStr),
                    (void*)responseStr,
                    MHD_RESPMEM_MUST_COPY);

                // 设置 HTTP 响应头
                MHD_add_response_header(response, "Content-Type", "application/json");

                // 发送 HTTP 响应给客户端
                MHD_queue_response(connection, MHD_HTTP_OK, response);

                // 释放 MHD_Response
                MHD_destroy_response(response);
            }
            else 
            {
                printf("Failed to open database.\n");
            }
        }
        else 
        {
            printf("Device not found.\n");
        }
    }
    else 
    {
        printf("Invalid request.\n");
    }
}


// // 处理设备日使用时长分析请求
// void analyzeDataTime(struct MHD_Connection* connection, const char* request)
// {
//     // 解析请求，获取设备ID等信息，假设这里使用了JSON格式
//     cJSON* jsonRequest = cJSON_Parse(request);
//     cJSON* jsonDeviceID;

//     if (jsonRequest != NULL && cJSON_HasObjectItem(jsonRequest, "deviceID"))
//     {
//         jsonDeviceID = cJSON_GetObjectItem(jsonRequest, "deviceID");
//         int deviceID = jsonDeviceID->valueint;

//         // 从数据库中查询设备的使用时长
//         double totalUsageTime = calculateDeviceTotalUsageTime(deviceID);

//         // 构建JSON响应
//         cJSON* jsonResponse = cJSON_CreateObject();
//         cJSON_AddNumberToObject(jsonResponse, "totalUsageTime", totalUsageTime);

//         // 将 JSON 响应转换为字符串
//         char* responseStr = cJSON_Print(jsonResponse);

//         // 创建 MHD_Response 对象
//         struct MHD_Response* response = MHD_create_response_from_buffer(strlen(responseStr),
//             (void*)responseStr,
//             MHD_RESPMEM_MUST_COPY);

//         // 设置 HTTP 响应头
//         MHD_add_response_header(response, "Content-Type", "application/json");

//         // 发送 HTTP 响应给客户端
//         MHD_queue_response(connection, MHD_HTTP_OK, response);

//         // 释放 MHD_Response 和 cJSON 对象
//         MHD_destroy_response(response);
//         cJSON_Delete(jsonResponse);
//     }
//     else
//     {
//         // 请求中没有包含必要的信息，返回错误信息
//         printf("Invalid request.\n");
//     }

//     // 释放 cJSON 对象
//     cJSON_Delete(jsonRequest);
// }

// 更新空调设备信息到数据库
void updateAirDeviceStatus(struct MHD_Connection* connection, const char* request, sqlite3* db)
{
    // 解析请求，获取设备信息
    const char* deviceNameParam = MHD_lookup_connection_value(connection, MHD_GET_ARGUMENT_KIND, "deviceName");
    const char* statusValueParam = MHD_lookup_connection_value(connection, MHD_GET_ARGUMENT_KIND, "statusValue");
    const char* modeParam = MHD_lookup_connection_value(connection, MHD_GET_ARGUMENT_KIND, "mode");
    const char* featureParam = MHD_lookup_connection_value(connection, MHD_GET_ARGUMENT_KIND, "feature");
    const char* timeParam = MHD_lookup_connection_value(connection, MHD_GET_ARGUMENT_KIND, "timestamp");

    printf("deviceNameParam: %s\n", deviceNameParam);
    printf("statusValueParam: %s\n", statusValueParam);
    printf("modeParam: %s\n", modeParam);
    printf("featureParam: %s\n", featureParam);
    printf("timeParam: %s\n", timeParam);

    if (deviceNameParam && statusValueParam && modeParam && featureParam) {
        const char* deviceName = deviceNameParam;
        int statusValue = atoi(statusValueParam);
        int mode = atoi(modeParam);
        double feature = atof(featureParam);
        const char* timestamp = timeParam;

        // 使用 SQLite 更新语句将数据更新到数据库
        char sql[256];
        snprintf(sql, sizeof(sql), "INSERT INTO DeviceData (DeviceName, Timestamp, StatusValue, Mode, Feature) VALUES ('%s', '%s', %d, %d, %lf);", deviceName, timestamp, statusValue, mode, feature);
        printf("Generated SQL query: %s\n", sql);

        // 执行更新语句
        char* errmsg = NULL;
        int rc = sqlite3_exec(db, sql, NULL, 0, &errmsg);
        if (rc != SQLITE_OK) {
            // 更新失败，打印错误信息
            printf("Error updating data: %s\n", errmsg);
            sqlite3_free(errmsg);

            // 构建 JSON 响应
            cJSON* jsonResponse = cJSON_CreateObject();
            cJSON_AddBoolToObject(jsonResponse, "success", 0);
            const char* responseStr = cJSON_Print(jsonResponse);

            // 发送 HTTP 响应给客户端
            struct MHD_Response* response = MHD_create_response_from_buffer(strlen(responseStr),
                (void*)responseStr,
                MHD_RESPMEM_MUST_COPY);
            MHD_add_response_header(response, "Content-Type", "application/json");
            MHD_queue_response(connection, MHD_HTTP_BAD_REQUEST, response); // 使用 HTTP 400 状态码
            MHD_destroy_response(response);

            cJSON_Delete(jsonResponse);
        } else {
            // 更新成功，构建 JSON 响应
            cJSON* jsonResponse = cJSON_CreateObject();
            cJSON_AddItemToObject(jsonResponse, "success", cJSON_CreateTrue());
            const char* responseStr = cJSON_PrintUnformatted(jsonResponse);

            // 发送 HTTP 响应给客户端
            struct MHD_Response* response = MHD_create_response_from_buffer(strlen(responseStr),
                (void*)responseStr,
                MHD_RESPMEM_MUST_COPY);
            MHD_add_response_header(response, "Content-Type", "application/json");
            MHD_queue_response(connection, MHD_HTTP_OK, response); // 使用 HTTP 200 状态码
            MHD_destroy_response(response);

            cJSON_Delete(jsonResponse);
        }
    } else {
        // 无效请求，构建 JSON 响应
        cJSON* jsonResponse = cJSON_CreateObject();
        cJSON_AddItemToObject(jsonResponse, "success", cJSON_CreateFalse());
        const char* responseStr = cJSON_PrintUnformatted(jsonResponse);

        // 发送 HTTP 响应给客户端
        struct MHD_Response* response = MHD_create_response_from_buffer(strlen(responseStr),
            (void*)responseStr,
            MHD_RESPMEM_MUST_COPY);
        MHD_add_response_header(response, "Content-Type", "application/json");
        MHD_queue_response(connection, MHD_HTTP_BAD_REQUEST, response); // 使用 HTTP 400 状态码
        MHD_destroy_response(response);

        cJSON_Delete(jsonResponse);
    }
}


// 更新灯设备信息到数据库
void updateLightDeviceStatus(struct MHD_Connection* connection, const char* request, sqlite3* db)
{
    // 解析请求，获取设备信息
    const char* deviceNameParam = MHD_lookup_connection_value(connection, MHD_GET_ARGUMENT_KIND, "deviceName");
    const char* statusValueParam = MHD_lookup_connection_value(connection, MHD_GET_ARGUMENT_KIND, "statusValue");
    const char* modeParam = MHD_lookup_connection_value(connection, MHD_GET_ARGUMENT_KIND, "mode");
    const char* timeParam = MHD_lookup_connection_value(connection, MHD_GET_ARGUMENT_KIND, "timestamp");

    printf("deviceNameParam: %s\n", deviceNameParam);
    printf("statusValueParam: %s\n", statusValueParam);
    printf("modeParam: %s\n", modeParam);
    printf("timeParam: %s\n", timeParam);

   if (deviceNameParam && statusValueParam && modeParam) {
        const char* deviceName = deviceNameParam;
        int statusValue = atoi(statusValueParam);
        int mode = atoi(modeParam);
        const char* timestamp = timeParam;

        // 使用 SQLite 更新语句将数据更新到数据库
        char sql[256];
        snprintf(sql, sizeof(sql), "INSERT INTO DeviceData (DeviceName, Timestamp, StatusValue, Mode) VALUES ('%s', '%s', %d, %d);", deviceName, timestamp, statusValue, mode);
        printf("Generated SQL query: %s\n", sql);

         // 执行更新语句
        char* errmsg = NULL;
        int rc = sqlite3_exec(db, sql, NULL, 0, &errmsg);
        if (rc != SQLITE_OK)
        {
            // 更新失败，打印错误信息
            printf("Error updating data: %s\n", errmsg);
            sqlite3_free(errmsg);

            // 构建 JSON 响应
            cJSON* jsonResponse = cJSON_CreateObject();
            cJSON_AddBoolToObject(jsonResponse, "success", 0);
            const char* responseStr = cJSON_Print(jsonResponse);

            // 发送 HTTP 响应给客户端
            struct MHD_Response* response = MHD_create_response_from_buffer(strlen(responseStr),
                (void*)responseStr,
                MHD_RESPMEM_MUST_COPY);
            MHD_add_response_header(response, "Content-Type", "application/json");
            MHD_queue_response(connection, MHD_HTTP_BAD_REQUEST, response); // 使用 HTTP 400 状态码
            MHD_destroy_response(response);

            cJSON_Delete(jsonResponse);
        }
        else
        {
            // 更新成功，构建 JSON 响应
            cJSON* jsonResponse = cJSON_CreateObject();
            cJSON_AddItemToObject(jsonResponse, "success", cJSON_CreateTrue());
            const char* responseStr = cJSON_PrintUnformatted(jsonResponse);

            // 发送 HTTP 响应给客户端
            struct MHD_Response* response = MHD_create_response_from_buffer(strlen(responseStr),
                (void*)responseStr,
                MHD_RESPMEM_MUST_COPY);
            MHD_add_response_header(response, "Content-Type", "application/json");
            MHD_queue_response(connection, MHD_HTTP_OK, response); // 使用 HTTP 200 状态码
            MHD_destroy_response(response);

            cJSON_Delete(jsonResponse);
        }
    }
    else
    {
        // 无效请求，构建 JSON 响应
        cJSON* jsonResponse = cJSON_CreateObject();
        cJSON_AddItemToObject(jsonResponse, "success", cJSON_CreateFalse());
        const char* responseStr = cJSON_PrintUnformatted(jsonResponse);

        // 发送 HTTP 响应给客户端
        struct MHD_Response* response = MHD_create_response_from_buffer(strlen(responseStr),
            (void*)responseStr,
            MHD_RESPMEM_MUST_COPY);
        MHD_add_response_header(response, "Content-Type", "application/json");
        MHD_queue_response(connection, MHD_HTTP_BAD_REQUEST, response); // 使用 HTTP 400 状态码
        MHD_destroy_response(response);

        cJSON_Delete(jsonResponse);
    }
}

// 更新加湿器设备信息到数据库
void updateHumidityDeviceStatus(struct MHD_Connection* connection, const char* request, sqlite3* db)
{
    // 解析请求，获取设备信息
    const char* deviceNameParam = MHD_lookup_connection_value(connection, MHD_GET_ARGUMENT_KIND, "deviceName");
    const char* statusValueParam = MHD_lookup_connection_value(connection, MHD_GET_ARGUMENT_KIND, "statusValue");
    const char* featureParam = MHD_lookup_connection_value(connection, MHD_GET_ARGUMENT_KIND, "feature");
    const char* timeParam = MHD_lookup_connection_value(connection, MHD_GET_ARGUMENT_KIND, "timestamp");

    printf("deviceNameParam: %s\n", deviceNameParam);
    printf("statusValueParam: %s\n", statusValueParam);
    printf("featureParam: %s\n", featureParam);
    printf("timeParam: %s\n", timeParam);

    if (deviceNameParam && statusValueParam && featureParam) {
        const char* deviceName = deviceNameParam;
        int statusValue = atoi(statusValueParam);
        double feature = atof(featureParam);
        const char* timestamp = timeParam;

        // 使用 SQLite 更新语句将数据更新到数据库
        char sql[256];
        snprintf(sql, sizeof(sql), "INSERT INTO DeviceData (DeviceName, Timestamp, StatusValue, Mode, Feature) VALUES ('%s', '%s', %d, %d, %lf);", deviceName, timestamp, statusValue, 0, feature);
        printf("Generated SQL query: %s\n", sql);

        // 执行更新语句
        char* errmsg = NULL;
        int rc = sqlite3_exec(db, sql, NULL, 0, &errmsg);
        if (rc != SQLITE_OK)
        {
            // 更新失败，打印错误信息
            printf("Error updating data: %s\n", errmsg);
            sqlite3_free(errmsg);

            // 构建 JSON 响应
            cJSON* jsonResponse = cJSON_CreateObject();
            cJSON_AddBoolToObject(jsonResponse, "success", 0);
            const char* responseStr = cJSON_Print(jsonResponse);

            // 发送 HTTP 响应给客户端
            struct MHD_Response* response = MHD_create_response_from_buffer(strlen(responseStr),
                (void*)responseStr,
                MHD_RESPMEM_MUST_COPY);
            MHD_add_response_header(response, "Content-Type", "application/json");
            MHD_queue_response(connection, MHD_HTTP_BAD_REQUEST, response); // 使用 HTTP 400 状态码
            MHD_destroy_response(response);

            cJSON_Delete(jsonResponse);
        }
        else
        {
            // 更新成功，构建 JSON 响应
            cJSON* jsonResponse = cJSON_CreateObject();
            cJSON_AddBoolToObject(jsonResponse, "success", 1);
            const char* responseStr = cJSON_Print(jsonResponse);

            // 发送 HTTP 响应给客户端
            struct MHD_Response* response = MHD_create_response_from_buffer(strlen(responseStr),
                (void*)responseStr,
                MHD_RESPMEM_MUST_COPY);
            MHD_add_response_header(response, "Content-Type", "application/json");
            MHD_queue_response(connection, MHD_HTTP_OK, response); // 使用 HTTP 200 状态码
            MHD_destroy_response(response);

            cJSON_Delete(jsonResponse);
        }
    }
    else
    {
        // 无效请求，构建 JSON 响应
        cJSON* jsonResponse = cJSON_CreateObject();
        cJSON_AddBoolToObject(jsonResponse, "success", 0);
        const char* responseStr = cJSON_Print(jsonResponse);

        // 发送 HTTP 响应给客户端
        struct MHD_Response* response = MHD_create_response_from_buffer(strlen(responseStr),
            (void*)responseStr,
            MHD_RESPMEM_MUST_COPY);
        MHD_add_response_header(response, "Content-Type", "application/json");
        MHD_queue_response(connection, MHD_HTTP_BAD_REQUEST, response); // 使用 HTTP 400 状态码
        MHD_destroy_response(response);

        cJSON_Delete(jsonResponse);
    }

}



