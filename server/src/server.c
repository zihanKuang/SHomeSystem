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
    else if (strncmp(request, "/user/data/analyze", strlen("/user/data/analyze")) == 0)
    {
        // 处理用户数据分析请求
        analyzeUserData(request);
    }
	else if (strncmp(request, "/weather", strlen("/weather")) == 0) {
        // 处理获取天气数据请求
        handleWeatherRequest();
    }else if (strncmp(request, "/network/test", strlen("/network/test")) == 0)
    {
        // 处理网络连接测试请求
        handleNetworkConnectionTest();
    }
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
