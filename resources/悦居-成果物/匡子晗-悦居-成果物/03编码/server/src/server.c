/* server.c - 服务器框架和事件循环

-事件库初始化

socket创建
回调函数定义
事件分发循环 */

#include "server.h"

// 处理客户端HTTP请求  
enum MHD_Result handleRequest(void* cls,struct MHD_Connection* connection, const char* request, 
                const char* method, const char* version, const char* upload_data, 
                size_t* upload_data_size, void** ptr) {

  if (*ptr == NULL) {

    // 第一次调用,初始化状态
    *ptr = (void*)1;
    return MHD_YES;

  } else if (*ptr == (void*)1) {

    // 解析客户端请求,根据路由选择对应的处理函数

    if (strncmp(request, "/user/register", strlen("/user/register")) == 0) {
      
      // 处理用户注册请求
      handleUserRegister(request,connection);

    } else if (strncmp(request, "/user/login", strlen("/user/login")) == 0) {

      // 处理用户登录请求  
      handleUserLogin(request,connection);

    } else if (strncmp(request, "/device/control", strlen("/device/control")) == 0) {

      // 处理设备控制请求
      //handleDeviceControl(request);

    } else if (strncmp(request, "/weather", strlen("/weather")) == 0) {

      // 处理获取天气数据请求  
      handleWeatherRequest(connection);

    } else if (strncmp(request, "/network/test", strlen("/network/test")) == 0) {

      // 处理网络连接测试请求
      handleNetworkConnectionTest(connection);

    } else if (strncmp(request, "/data/updateAirData", strlen("/data/updateAirData")) == 0) {

      // 更新数据库中空调设备的信息
      updateAirDeviceStatus(connection, request,db);

    } else if (strncmp(request, "/data/updateLightData", strlen("/data/updateLightData")) == 0) {

      // 更新数据库中灯设备的信息
      updateLightDeviceStatus(connection, request,db);

    } else if (strncmp(request, "/data/updateHumidityData", strlen("/data/updateHumidityData")) == 0) {

      // 更新数据库中加湿器设备的信息  
      updateHumidityDeviceStatus(connection, request,db);

    } else if (strncmp(request, "/data/time", strlen("/data/time")) == 0) {

      // 处理设备日使用时长分析请求
      //analyzeDataTime(connection, request);

    } else if (strncmp(request, "/data/airTotalPower", strlen("/data/airTotalPower")) == 0) {

      // 处理空调设备日总耗电分析请求
      analyzeDataAirTotalPower(connection, request);

    } else if (strncmp(request, "/data/lightTotalPower", strlen("/data/lightTotalPower")) == 0) {

      // 处理灯设备日总耗电分析请求 
      analyzeDataLightTotalPower(connection, request);

    } else if (strncmp(request, "/data/humidityTotalPower", strlen("/data/humidityTotalPower")) == 0) {

      // 处理加湿器设备日总耗电分析请求
      analyzeDataHumidityTotalPower(connection, request);

    } else {

      const char* response = "Invalid request";
      struct MHD_Response* mhdResponse = MHD_create_response_from_buffer(strlen(response), (void*)response, MHD_RESPMEM_PERSISTENT);
      MHD_queue_response(connection, MHD_HTTP_NOT_FOUND, mhdResponse);
      MHD_destroy_response(mhdResponse);

      return MHD_NO;
    }

  }

  // 返回处理成功
  return MHD_YES;

}

// 启动服务器  
void start_server() {
  
    // 初始化数据库连接
  if (!openDatabase("../../database/SHomedb.db")) {
    printf("Failed to open database\n");
    return;
  }

// 初始化libcurl
    curl_global_init(CURL_GLOBAL_DEFAULT);
    
  // 初始化事件库
  struct MHD_Daemon* daemon = MHD_start_daemon(MHD_USE_THREAD_PER_CONNECTION, 
                        8080, NULL, NULL, &handleRequest, NULL, MHD_OPTION_END);

  if (daemon == NULL) {
    printf("Failed to start server\n");
    closeDatabase(); // 关闭数据库连接
    return;
  }

  // 等待服务器结束
  printf("Server started on port 8080\n"); 
  printf("Press Enter to stop the server...\n");
  getchar(); // 等待用户输入回车

    // 停止服务器
    MHD_stop_daemon(daemon); 

    // 清理libcurl资源
    curl_global_cleanup();

    // 关闭数据库连接
    closeDatabase();
}