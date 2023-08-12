// api.c - 通信接口类的实现

#include "api.h" // 包含通信接口类的头文件
#include "db.h"  // 包含数据惯例模块的头文件
#include <stdio.h>
#include <string.h>
#include "cJSON.h"

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







