/* server.c - 服务器框架和事件循环

-事件库初始化

socket创建
回调函数定义
事件分发循环 */

// 引入libevent头文件
#include <event2/event.h>
#include "api.c" 
#include "db.c"

// 处理客户端HTTP请求
void handleRequest(const char* request)
{
    // 解析客户端请求，根据路由选择对应的处理函数
    if (strncmp(request, "/user/register", strlen("/user/register")) == 0)
    {
        // 处理用户注册请求
        handleUserRegistration(request);
    }
    else if (strncmp(request, "/user/login", strlen("/user/login")) == 0)
    {
        // 处理用户登录请求
        handleUserLogin(request);
    }
    else if (strncmp(request, "/device/control", strlen("/device/control")) == 0)
    {
        // 处理设备控制请求
        handleDeviceControl(request);
    }
    //else if (strncmp(request, "/user/data/analyze", strlen("/user/data/analyze")) == 0)
    //{
    //    // 处理用户数据分析请求
    //    analyzeUserData(request);
    //}
	else if (strncmp(request, "/weather", strlen("/weather")) == 0) {
        // 处理获取天气数据请求
        handleWeatherRequest();
    }
	else if (strncmp(request, "/network/test", strlen("/network/test")) == 0)
    {
        // 处理网络连接测试请求
        handleNetworkConnectionTest();
    }
	else if (strncmp(request, "/data/updataAirData", strlen("/data/updataAirData")) == 0)
    {
        // 更新数据库中 空调 设备的信息
        updateAirDeviceStatus(request);
    }
	else if (strncmp(request, "/data/updataLightData", strlen("/data/updataLightData")) == 0)
    {
        // 更新数据库中 灯 设备的信息
        updateLightDeviceStatus(request);
    }
	else if (strncmp(request, "/data/updataHumidityData", strlen("/data/updataHumidityData")) == 0)
    {
        // 更新数据库中 加湿器 设备的信息
        updateHumidityDeviceStatus(request);
    }
	else if (strncmp(request, "/data/time", strlen("/data/time")) == 0)
    {
        // 处理设备 日 使用时长分析请求
        analyzeDataTime(request);
    }
	else if (strncmp(request, "/data/airTotalPower", strlen("/data/airtotalPower")) == 0)
    {
        // 处理 空调 设备 日 总耗电分析请求
        analyzeDataAirTotalPower(request);
    }
	else if (strncmp(request, "/data/lightTotalPower", strlen("/data/lighttotalPower")) == 0)
    {
        // 处理 灯 设备 日 总耗电分析请求
        analyzeDataLightTotalPower(request);
    }
	else if (strncmp(request, "/data/humidityTotalPower", strlen("/data/humiditytotalPower")) == 0)
    {
        // 处理 加湿器 设备 日 总耗电分析请求
        analyzeDataHumidityTotalPower(request);
    }
	//else if (strncmp(request, "/data/averagePower", strlen("/data/averagePower")) == 0)
    //{
        // 处理设备 每小时 耗电分析请求
    //    analyzeDataAveragePower(request);
    //}
    else
    {
        // 请求路径不合法，返回错误响应
        handleException("Invalid request");
    }
}

void start_server() {
    // 事件库初始化
    struct event_base* base = event_base_new();

    // 创建HTTP server
    struct evhttp* http_server = evhttp_new(base);
    evhttp_bind_socket(http_server, "0.0.0.0", 8080);

    // 设置请求处理函数
    evhttp_set_gencb(http_server, handle_request, NULL);

    // 事件分发循环
    event_base_dispatch(base);
}
