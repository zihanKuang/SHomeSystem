// api.h - 通信接口类的声明

#ifndef API_H
#define API_H

#include <curl/curl.h>
#include "cJSON.h"
#include <stdbool.h>
#include <stddef.h>
#include "db.h"  
#include <string.h>
#include "util.h"

// 使用 microhttpd 或其他适合的 HTTP 服务器库

// 验证用户身份是否合法
bool validateUser(const char* username, const char* password);

// 将对象数据序列化为JSON格式
const char* serializeToJson(const void* object);

// 将JSON反序列化为对象
void* deserializeFromJson(const char* json, size_t size);

// 处理网络错误等异常情况
void handleException(const char* message);

// 处理用户注册请求与信息验证
void handleUserRegister(const char* request, struct MHD_Connection* connection);

// 用户登录  
void handleUserLogin(const char* request, struct MHD_Connection* connection);

// 天气数据
const char* fetchWeatherData();
void handleWeatherRequest(struct MHD_Connection* con);

// 网络测试
void handleNetworkConnectionTest(struct MHD_Connection* con);

// 空调耗电分析
void analyzeDataAirTotalPower(struct MHD_Connection* con, const char* request);

// 灯耗电分析
void analyzeDataLightTotalPower(struct MHD_Connection* con, const char* request);

// 加湿器耗电分析
void analyzeDataHumidityTotalPower(struct MHD_Connection* con, const char* request); 

// 使用时长分析
//void analyzeDataTime(struct MHD_Connection* con, const char* request);

// 更新设备状态  
void updateAirDeviceStatus(struct MHD_Connection* connection, const char* request, sqlite3* db);
void updateLightDeviceStatus(struct MHD_Connection* connection, const char* request, sqlite3* db);
void updateHumidityDeviceStatus(struct MHD_Connection* connection, const char* request, sqlite3* db);

size_t writeCallback(void* contents, size_t size, size_t nmemb, void* userp);
#endif // API_H
