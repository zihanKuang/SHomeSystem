/*  api.c - 实现API路由

定义请求路径到函数指针的map
请求处理函数 - 获取参数、验证、业务处理等
返回响应数据*/

#include "api.h"

// 定义请求路径到函数指针的map
static std::map<std::string, RequestHandler> routes;

// 请求处理函数 - 获取参数、验证、业务处理等
void get_user(Request req) {
    pid_t pid = fork();
    if (pid == 0) {
        // 子进程数据库查询
        // 执行数据库查询操作，并将结果写入管道
        send(pipe_fd, result, len, 0);
        exit(0);  // 子进程执行完毕后退出
    } else if (pid > 0) {
        // 父进程继续处理其他请求
    } else {
        // 处理fork失败的情况
    }
}


void initialize_routes() {
    // 注册处理函数
    routes["/api/user"] = get_user;
}

void handle_request(Request req) {
    // 根据请求路径找到对应的处理函数
    auto it = routes.find(req.path);
    if (it != routes.end()) {
        RequestHandler handler = it->second;
        handler(req);
    } else {
        // 未找到路径对应的处理函数，返回404
        send_response(req.client_fd, "404 Not Found");
    }
}
