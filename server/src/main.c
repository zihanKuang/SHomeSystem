/* main.c - 程序入口

引入需要的头文件
初始化配置、日志等
调用server.c启动服务器 */
#include "server.c" 

int main() {
	init_config();
	init_logger();
	start_server();
}