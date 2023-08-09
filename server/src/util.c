/* util.c - 工具函数

通用功能函数 - 日志、转换、字符串处理等
JSON序列化和反序列化函数
错误处理函数 */

// 日志函数
void log(const char* msg) {
	printf("%s\n", msg); 
}

// JSON序列化
char* to_json(const User* u) {
	cJSON* root = cJSON_CreateObject();
	cJSON_AddStringToObject(root, "name", u->name);
	// ...
	return cJSON_Print(root);
}

// 设备故障检测
void checkDeviceFailure() {
  // 分析日志、监控数据
  // 检测故障 
  // 触发警报
}

// 温度异常检测
void checkTempAnomaly() {
  // 获取温度数据
  // 分析判断是否异常
  // 触发警报
}

// 发送警报
void sendAlert(User* user, Alert* alert) {
  // 调用通知模块接口
  // 发送警报
}