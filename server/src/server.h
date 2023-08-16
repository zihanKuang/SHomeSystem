#ifndef SERVER_H
#define SERVER_H

#include "api.h" 
#include "util.h"
#include <stdio.h>
#include <string.h>
#include "api.h" // 包含通信接口类的头文件

// 处理客户端HTTP请求
enum MHD_Result handleRequest(void* cls,struct MHD_Connection* connection, const char* request,
  const char* method, const char* version, const char* upload_data,
  size_t* upload_data_size, void** ptr);

// 开始服务器
void start_server();

#endif // SERVER_H
