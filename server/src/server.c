/* server.c - 服务器框架和事件循环

-事件库初始化

socket创建
回调函数定义
事件分发循环 */

// 引入libevent头文件
#include <event2/event.h>

void handle_request(struct evhttp_request* req, void* arg) {
    // 获取请求路径，根据路由表选择处理函数
    // 执行处理函数，获取响应数据
    // 发送响应数据给客户端
}

void start_server() {
    // 事件库初始化
    struct event_base* base = event_base_new();

    // 创建HTTP server
    struct evhttp* http_server = evhttp_new(base);
    evhttp_bind_socket(http_server, "0.0.0.0", 8000);

    // 设置请求处理函数
    evhttp_set_gencb(http_server, handle_request, NULL);

    // 事件分发循环
    event_base_dispatch(base);
}
