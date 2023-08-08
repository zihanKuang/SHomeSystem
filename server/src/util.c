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