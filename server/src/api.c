// api.c - 通信接口类的实现

#include "api.h" // 包含通信接口类的头文件
#include "db.h"  // 包含数据惯例模块的头文件
#include <stdio.h>
#include <string.h>
#include "cJSON.h"
#include <microhttpd.h> // 使用 microhttpd 或其他适合的 HTTP 服务器库

const int MAX_REQUEST_SIZE = 1024;

// 验证用户身份是否合法
bool validateUser(const char* username, const char* password)
{
    // 从数据库中获取用户信息
    char db_pass[32];
    bool userExists = getUserData(username, db_pass);

    if (userExists && strcmp(db_pass, password) == 0)
    {
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

/// 处理用户注册请求与信息验证
void handleUserRegister(char* request) {

  // 从请求JSON解析用户名密码
  cJSON* json = cJSON_Parse(request);
  
  char* username = cJSON_GetObjectItem(json, "username")->valuestring;
  char* password = cJSON_GetObjectItem(json, "password")->valuestring;

  // 保存到数据库
  saveUser(username, password);
  
  // 返回响应
  cJSON* resp = cJSON_CreateObject();
  cJSON_AddBoolToObject(resp, "success", 1);
  char* resp_str = cJSON_Print(resp);

  sendHttpResp(200, "application/json", resp_str);
  
  cJSON_Delete(resp); // 清除object
        free(resp_str);
        cJSON_Delete(json);
    } else {
        handleException("JSON parsing error");
    }
}

// 处理用户登录请求与验证
void handleUserLogin(const char* request)
{
	cJSON* json = cJSON_Parse(request);
	
     if (json) {
        char* username = cJSON_GetObjectItem(json, "username")->valuestring;
        char* password = cJSON_GetObjectItem(json, "password")->valuestring;

        bool isValidUser = validateUser(username, password);

        cJSON* response = cJSON_CreateObject();

        if (isValidUser) {
            cJSON_AddBoolToObject(response, "success", 1);
            // Add other relevant data to the response JSON
        } else {
            cJSON_AddBoolToObject(response, "success", 0);
            // Add other relevant data to the response JSON
        }

        char* response_str = cJSON_Print(response);

        sendHttpResp(200, "application/json", response_str);

        cJSON_Delete(response);
        free(response_str);
        cJSON_Delete(json);
    } else {
        // Handle JSON parsing error
        handleException("JSON parsing error");
    }
}

// 处理设备控制请求,生成控制指令
void handleDeviceControl(const char* request)
{
    // 解析客户端请求，获取设备控制信息
    // 从request中提取设备ID和控制指令等字段

    // 生成设备控制指令

    // 发送设备控制指令给设备

    // 返回控制结果响应
    // 返回客户端JSON格式的设备控制结果响应
}

// 分析用户数据,生成统计报告
void analyzeSensorData() {

  // 1. 从数据库获取温湿度数据
  char* sql = "SELECT * FROM EnvironmentData";
  queryDataFromDB(sql);

  // 2. 统计分析,生成温湿度折线图数据
  double temp_data[100];
  double humid_data[100];

  // 3. 生成柱状图数据
  int energy_data[5];
  int runtime_data[5];

  // 4. 将统计结果序列化为JSON
  cJSON* analysis = generateResultJson(temp_data, humid_data, energy_data, runtime_data);

  // 5. 返回给客户端 
  sendHttpResp(200, "application/json", analysis);

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

    // 使用网络库发送GET请求，获取天气数据

    // 示例数据
    const char* weatherData = "{\"temperature\": 25, \"humidity\": 60}";

    return weatherData;
}

// 处理获取天气数据请求
void handleWeatherRequest(evhttp_request* req, void* arg) {
    const char* weather_data = fetchWeatherData();

    // 构造响应
    struct evbuffer* buf = evbuffer_new();

    if (!buf) {
        sendHttpError(req, 500);
        return;
    }

    evbuffer_add_printf(buf, "%s", weather_data);

    // 设置响应代码和类型
    struct evkeyvalq* headers = evhttp_request_get_output_headers(req);
    evhttp_add_header(headers, "Content-Type", "application/json");
    evhttp_send_reply(req, HTTP_OK, "OK", buf);

    // 清理
    evbuffer_free(buf);
}

void handleNetworkConnectionTest(const char* request)
{
    const char* response = "Network connection is available.\n";
    sendHttpResp(200, "text/plain", response);
}

// 发送HTTP错误响应
void sendHttpError(evhttp_request* req, int error_code) {
    const char* error_message = get_error_message(error_code);

    struct evbuffer* buf = evbuffer_new();

    if (!buf) {
        // 处理 allocation failure
        return;
    }

    evbuffer_add_printf(buf, "%s", error_message);

    struct evkeyvalq* headers = evhttp_request_get_output_headers(req);
    evhttp_add_header(headers, "Content-Type", "text/plain");
    evhttp_send_reply(req, error_code, error_message, buf);

    evbuffer_free(buf);
}

// 处理 空调 设备 日 总耗电分析请求
void analyzeDataAirTotalPower(const char* request)
{
    // 解析请求，获取设备ID等信息，假设这里使用了JSON格式
    json_object* jsonRequest = json_tokener_parse(request);
    json_object* jsonDeviceID = NULL;

    if (json_object_object_get_ex(jsonRequest, "deviceID", &jsonDeviceID))
    {
        int deviceID = json_object_get_int(jsonDeviceID);

        // 从数据库中查询空调设备的相关数据
        struct DeviceData airDeviceData;
        if (getDeviceData(deviceID, &airDeviceData))
        {
            // 计算总耗电量
            double totalPower = calculateAirTotalPower(&airDeviceData);

            // 构建JSON响应
            json_object* jsonResponse = json_object_new_object();
            json_object_object_add(jsonResponse, "totalPower", json_object_new_double(totalPower));

			// 将 JSON 响应转换为字符串
            const char* responseStr = json_object_to_json_string(jsonResponse);

            // 构建 HTTP 响应
            struct MHD_Response* response = MHD_create_response_from_buffer(strlen(responseStr),
                                                                           (void*)responseStr,
                                                                           MHD_RESPMEM_MUST_COPY);

            // 设置 HTTP 响应头
            MHD_add_response_header(response, "Content-Type", "application/json");

            // 发送 HTTP 响应给客户端
            MHD_queue_response(connection, MHD_HTTP_OK, response);

            // 释放 MHD_Response 和 JSON 对象
            MHD_destroy_response(response);
            json_object_put(jsonResponse);
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

    json_object_put(jsonRequest);
}

// 处理 灯 设备 日 总耗电分析请求
void analyzeDataLightTotalPower(const char* request)
{
    // 解析请求，获取设备ID等信息，使用JSON格式
    json_object* jsonRequest = json_tokener_parse(request);
    json_object* jsonDeviceID;

    if (json_object_object_get_ex(jsonRequest, "deviceID", &jsonDeviceID))
    {
        int deviceID = json_object_get_int(jsonDeviceID);

        // 从数据库中查询灯光设备的相关数据
        struct DeviceData lightDeviceData;
        if (getDeviceData(deviceID, &lightDeviceData))
        {
            // 计算总耗电量
            double totalPower = calculateLightTotalPower(&lightDeviceData);

            // 构建JSON响应
            json_object* jsonResponse = json_object_new_object();
            json_object_object_add(jsonResponse, "totalPower", json_object_new_double(totalPower));

            // 将 JSON 响应转换为字符串
            const char* responseStr = json_object_to_json_string(jsonResponse);

            // 构建 HTTP 响应
            struct MHD_Response* response = MHD_create_response_from_buffer(strlen(responseStr),
                                                                           (void*)responseStr,
                                                                           MHD_RESPMEM_MUST_COPY);

            // 设置 HTTP 响应头
            MHD_add_response_header(response, "Content-Type", "application/json");

            // 发送 HTTP 响应给客户端
            MHD_queue_response(connection, MHD_HTTP_OK, response);

            // 释放 MHD_Response 和 JSON 对象
            MHD_destroy_response(response);
            json_object_put(jsonResponse);
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

    // 释放 JSON 对象
    json_object_put(jsonRequest);
}

// 处理 加湿器 设备 日 总耗电分析请求
void analyzeDataHumidityTotalPower(const char* request)
{
    // 解析请求，获取设备ID等信息，假设这里使用了JSON格式
    json_object* jsonRequest = json_tokener_parse(request);
    json_object* jsonDeviceID;

    if (json_object_object_get_ex(jsonRequest, "deviceID", &jsonDeviceID))
    {
        int deviceID = json_object_get_int(jsonDeviceID);

        // 从数据库中查询加湿器设备的相关数据
        struct DeviceData humidityDeviceData;
        if (getDeviceData(deviceID, &humidityDeviceData))
        {
            // 计算总耗电量
            double totalPower = calculateHumidityTotalPower(&humidityDeviceData);

            // 构建JSON响应
            json_object* jsonResponse = json_object_new_object();
            json_object_object_add(jsonResponse, "totalPower", json_object_new_double(totalPower));

            // 将 JSON 响应转换为字符串
            const char* responseStr = json_object_to_json_string(jsonResponse);

            // 构建 HTTP 响应
            struct MHD_Response* response = MHD_create_response_from_buffer(strlen(responseStr),
                                                                           (void*)responseStr,
                                                                           MHD_RESPMEM_MUST_COPY);

            // 设置 HTTP 响应头
            MHD_add_response_header(response, "Content-Type", "application/json");

            // 发送 HTTP 响应给客户端
            MHD_queue_response(connection, MHD_HTTP_OK, response);

            // 释放 MHD_Response 和 JSON 对象
            MHD_destroy_response(response);
            json_object_put(jsonResponse);
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

    // 释放JSON对象
    json_object_put(jsonRequest);

}

// 处理设备 日 使用时长分析请求
void analyzeDataTime(const char* request)
{
    // 解析请求，获取设备ID等信息，假设这里使用了JSON格式
    json_object* jsonRequest = json_tokener_parse(request);
    json_object* jsonDeviceID;

    if (json_object_object_get_ex(jsonRequest, "deviceID", &jsonDeviceID))
    {
        int deviceID = json_object_get_int(jsonDeviceID);

        // 从数据库中查询设备的使用时长
        double totalUsageTime = calculateDeviceTotalUsageTime(deviceID);

        // 构建JSON响应
        json_object* jsonResponse = json_object_new_object();
        json_object_object_add(jsonResponse, "totalUsageTime", json_object_new_double(totalUsageTime));

        // 将 JSON 响应转换为字符串
            const char* responseStr = json_object_to_json_string(jsonResponse);

        // 构建 HTTP 响应
        struct MHD_Response* response = MHD_create_response_from_buffer(strlen(responseStr),
                                                                           (void*)responseStr,
                                                                           MHD_RESPMEM_MUST_COPY);

        // 设置 HTTP 响应头
        MHD_add_response_header(response, "Content-Type", "application/json");

        // 发送 HTTP 响应给客户端
        MHD_queue_response(connection, MHD_HTTP_OK, response);

        // 释放 MHD_Response 和 JSON 对象
        MHD_destroy_response(response);
        json_object_put(jsonResponse);
    }
    else
    {
        // 请求中没有包含必要的信息，返回错误信息
        printf("Invalid request.\n");
    }

    // 释放JSON对象
    json_object_put(jsonRequest);
}

// 更新空调设备信息到数据库
void updateAirDeviceStatus(const char* request)
{
    // 解析请求，获取设备信息
    json_object* jsonRequest = json_tokener_parse(request);
    json_object* jsonDeviceID;
    json_object* jsonStatusValue;
    json_object* jsonMode;
    json_object* jsonFeature;

    if (json_object_object_get_ex(jsonRequest, "deviceID", &jsonDeviceID) &&
        json_object_object_get_ex(jsonRequest, "statusValue", &jsonStatusValue) &&
        json_object_object_get_ex(jsonRequest, "mode", &jsonMode) &&
        json_object_object_get_ex(jsonRequest, "feature", &jsonFeature))
    {
        int deviceID = json_object_get_int(jsonDeviceID);
        int statusValue = json_object_get_int(jsonStatusValue);
        int mode = json_object_get_int(jsonMode);
        double feature = json_object_get_double(jsonFeature); // 温度

        // 使用 SQLite 更新语句将数据更新到数据库
        char sql[256];
        snprintf(sql, sizeof(sql), "UPDATE DeviceData SET StatusValue = %d, Mode = %d, Feature = %lf WHERE DeviceID = %d;", statusValue, mode, feature, deviceID);

         // 执行更新语句
        char* errmsg = NULL;
        int rc = sqlite3_exec(db, sql, NULL, 0, &errmsg);
        if (rc != SQLITE_OK)
        {
            // 更新失败，打印错误信息
            printf("Error updating data: %s\n", errmsg);
            sqlite3_free(errmsg);

            // 构建 JSON 响应
            json_object* jsonResponse = json_object_new_object();
            json_object_object_add(jsonResponse, "success", json_object_new_boolean(false));
            const char* responseStr = json_object_to_json_string(jsonResponse);

            // 发送响应给客户端
            send(clientSocket, responseStr, strlen(responseStr), 0);

            json_object_put(jsonResponse);
        }
        else
        {
            // 更新成功，构建 JSON 响应
            json_object* jsonResponse = json_object_new_object();
            json_object_object_add(jsonResponse, "success", json_object_new_boolean(true));
            const char* responseStr = json_object_to_json_string(jsonResponse);

            // 发送响应给客户端
            send(clientSocket, responseStr, strlen(responseStr), 0);

            json_object_put(jsonResponse);
        }
    }
    else
    {
       // 无效请求，构建 JSON 响应
        json_object* jsonResponse = json_object_new_object();
        json_object_object_add(jsonResponse, "success", json_object_new_boolean(false));
        const char* responseStr = json_object_to_json_string(jsonResponse);

        // 发送响应给客户端
        send(clientSocket, responseStr, strlen(responseStr), 0);

        json_object_put(jsonResponse);
    }

    json_object_put(jsonRequest);
}

// 更新灯设备信息到数据库
void updateLightDeviceStatus(const char* request)
{
    // 解析请求，获取设备信息
    json_object* jsonRequest = json_tokener_parse(request);
    json_object* jsonDeviceID;
    json_object* jsonStatusValue;
    json_object* jsonMode;

    if (json_object_object_get_ex(jsonRequest, "deviceID", &jsonDeviceID) &&
        json_object_object_get_ex(jsonRequest, "statusValue", &jsonStatusValue) &&
        json_object_object_get_ex(jsonRequest, "mode", &jsonMode))
    {
        int deviceID = json_object_get_int(jsonDeviceID);
        int statusValue = json_object_get_int(jsonStatusValue);
        int mode = json_object_get_int(jsonMode);

        // 使用 SQLite 更新语句将数据更新到数据库
        char sql[256];
        snprintf(sql, sizeof(sql), "UPDATE DeviceData SET StatusValue = %d, Mode = %d WHERE DeviceID = %d;", statusValue, mode, deviceID);

         // 执行更新语句
        char* errmsg = NULL;
        int rc = sqlite3_exec(db, sql, NULL, 0, &errmsg);
        if (rc != SQLITE_OK)
        {
            // 更新失败，打印错误信息
            printf("Error updating data: %s\n", errmsg);
            sqlite3_free(errmsg);

            // 构建 JSON 响应
            json_object* jsonResponse = json_object_new_object();
            json_object_object_add(jsonResponse, "success", json_object_new_boolean(false));
            const char* responseStr = json_object_to_json_string(jsonResponse);

            // 发送响应给客户端
            send(clientSocket, responseStr, strlen(responseStr), 0);

            json_object_put(jsonResponse);
        }
        else
        {
            // 更新成功，构建 JSON 响应
            json_object* jsonResponse = json_object_new_object();
            json_object_object_add(jsonResponse, "success", json_object_new_boolean(true));
            const char* responseStr = json_object_to_json_string(jsonResponse);

            // 发送响应给客户端
            send(clientSocket, responseStr, strlen(responseStr), 0);

            json_object_put(jsonResponse);
        }
    }
    else
    {
       // 无效请求，构建 JSON 响应
        json_object* jsonResponse = json_object_new_object();
        json_object_object_add(jsonResponse, "success", json_object_new_boolean(false));
        const char* responseStr = json_object_to_json_string(jsonResponse);

        // 发送响应给客户端
        send(clientSocket, responseStr, strlen(responseStr), 0);

        json_object_put(jsonResponse);
    }

    json_object_put(jsonRequest);
}

// 更新加湿器设备信息到数据库
void updateHumidityDeviceStatus(const char* request)
{
    // 解析请求，获取设备信息
    json_object* jsonRequest = json_tokener_parse(request);
    json_object* jsonDeviceID;
    json_object* jsonStatusValue;
    json_object* jsonFeature;

    if (json_object_object_get_ex(jsonRequest, "deviceID", &jsonDeviceID) &&
        json_object_object_get_ex(jsonRequest, "statusValue", &jsonStatusValue) &&
        json_object_object_get_ex(jsonRequest, "feature", &jsonFeature))
    {
        int deviceID = json_object_get_int(jsonDeviceID);
        int statusValue = json_object_get_int(jsonStatusValue);
        double feature = json_object_get_double(jsonFeature); // 湿度

        // 使用 SQLite 更新语句将数据更新到数据库
        char sql[256];
        snprintf(sql, sizeof(sql), "UPDATE DeviceData SET StatusValue = %d, Feature = %lf WHERE DeviceID = %d;", statusValue, feature, deviceID);

        // 执行更新语句
        char* errmsg = NULL;
        int rc = sqlite3_exec(db, sql, NULL, 0, &errmsg);
        if (rc != SQLITE_OK)
        {
            // 更新失败，打印错误信息
            printf("Error updating data: %s\n", errmsg);
            sqlite3_free(errmsg);

            // 构建 JSON 响应
            json_object* jsonResponse = json_object_new_object();
            json_object_object_add(jsonResponse, "success", json_object_new_boolean(false));
            const char* responseStr = json_object_to_json_string(jsonResponse);

            // 发送响应给客户端
            send(clientSocket, responseStr, strlen(responseStr), 0);

            json_object_put(jsonResponse);
        }
        else
        {
            // 更新成功，构建 JSON 响应
            json_object* jsonResponse = json_object_new_object();
            json_object_object_add(jsonResponse, "success", json_object_new_boolean(true));
            const char* responseStr = json_object_to_json_string(jsonResponse);

            // 发送响应给客户端
            send(clientSocket, responseStr, strlen(responseStr), 0);

            json_object_put(jsonResponse);
        }
    }
    else
    {
       // 无效请求，构建 JSON 响应
        json_object* jsonResponse = json_object_new_object();
        json_object_object_add(jsonResponse, "success", json_object_new_boolean(false));
        const char* responseStr = json_object_to_json_string(jsonResponse);

        // 发送响应给客户端
        send(clientSocket, responseStr, strlen(responseStr), 0);

        json_object_put(jsonResponse);
    }

    json_object_put(jsonRequest);
}



