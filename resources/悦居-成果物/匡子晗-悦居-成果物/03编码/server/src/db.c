// db.c - 数据惯例模块的实现

#include "db.h" 
#include <time.h>

// 全局数据库连接句柄
sqlite3* db;
// 声明一个数组存储设备数据
struct DeviceData deviceDataList[100];

// 打开数据库
bool openDatabase(const char* databaseName)
{
    // 尝试连接数据库
    int rc = sqlite3_open(databaseName, &db);

    if (rc != SQLITE_OK)
    {
        // 连接数据库失败，打印错误信息
        printf("Error opening database: %s\n", sqlite3_errmsg(db));
        return false;
    }
    else
    {
        printf("Database opened successfully.\n");
        return true;
    }
}

// 关闭数据库连接
void closeDatabase()
{
    if (db) {
        sqlite3_close(db);
        db = NULL;
    }
}

// 检查用户名是否唯一
bool isUsernameUnique(sqlite3* db,const char* username)
{
    char sql[256];
    snprintf(sql, sizeof(sql), "SELECT COUNT(*) FROM UserData WHERE username = '%s';", username);

    // 执行查询语句
    sqlite3_stmt* stmt;
    int rc = sqlite3_prepare_v2(db, sql, -1, &stmt, NULL);
    if (rc != SQLITE_OK)
    {
        // 查询失败，打印错误信息
        printf("Error executing query: %s\n", sqlite3_errmsg(db));
        return false;
    }

    // 获取查询结果
    int count = 0;
    if (sqlite3_step(stmt) == SQLITE_ROW)
    {
        count = sqlite3_column_int(stmt, 1);
    }

    // 释放查询句柄
    sqlite3_finalize(stmt);

    return count == 0;
}

// 保存用户注册信息
bool saveUser(sqlite3* db,const char* username, const char* password)
{
    char sql[256];
    snprintf(sql, sizeof(sql), "INSERT INTO UserData (username, password) VALUES ('%s', '%s');", username, password);
    printf("Insert SQL: %s\n", sql);

    // 执行插入语句
    char* errmsg = NULL;
    int rc = sqlite3_exec(db, sql, NULL, 0, &errmsg);
    if (rc != SQLITE_OK)
    {
        // 插入失败，打印错误信息
        printf("Error executing query: %s\n", errmsg);
        sqlite3_free(errmsg);
        return false;
    }

    return true;
}

// 获取用户信息
bool getUserData(sqlite3* db, const char* username, char* password)
{
    char sql[256];
    snprintf(sql, sizeof(sql), "SELECT password FROM UserData WHERE username = '%s';", username);

    // 执行查询语句
    sqlite3_stmt* stmt;
    int rc = sqlite3_prepare_v2(db, sql, -1, &stmt, NULL);
    if (rc != SQLITE_OK)
    {
        // 查询失败，打印错误信息
        printf("Error executing query: %s\n", sqlite3_errmsg(db));
        return false;
    }

    // 获取查询结果
    if (sqlite3_step(stmt) == SQLITE_ROW)
    {
        const unsigned char* dbPassword = sqlite3_column_text(stmt, 0);
        printf("DB Password: %s\n", dbPassword);
        snprintf(password, 32, "%s", dbPassword);
    }
    else
    {
        // 用户不存在
        return false;
    }

    // 释放查询句柄
    sqlite3_finalize(stmt);

    return true;
}


// 从数据库中获取设备数据
bool getDeviceData(sqlite3* db,int deviceID, struct DeviceData* deviceData)
{
    char sql[256];
    snprintf(sql, sizeof(sql), "SELECT * FROM DeviceData WHERE DeviceID = %d;", deviceID);

    // 执行查询语句
    sqlite3_stmt* stmt;
    int rc = sqlite3_prepare_v2(db, sql, -1, &stmt, NULL);
    if (rc != SQLITE_OK)
    {
        // 查询失败，打印错误信息
        printf("Error executing query: %s\n", sqlite3_errmsg(db));
        return false;
    }

    // 获取查询结果
    if (sqlite3_step(stmt) == SQLITE_ROW)
    {
        deviceData->DataID = sqlite3_column_int(stmt, 0);

        strcpy(deviceData->DeviceName , (const char*)sqlite3_column_text(stmt, 1));

        // 使用strcpy替代直接赋值
        strcpy(deviceData->Timestamp, (const char*)sqlite3_column_text(stmt, 2));

        deviceData->StatusValue = sqlite3_column_double(stmt, 3);
        deviceData->Mode = sqlite3_column_int(stmt, 4);
		deviceData->Feature = sqlite3_column_double(stmt, 5);
    }
    else
    {
        // 设备数据不存在
        return false;
    }

    // 释放查询句柄
    sqlite3_finalize(stmt);

    return true;
}

// 数组索引
int deviceCount = 0;

// 自己实现一个添加到数组的函数
void addToDeviceDataList(struct DeviceData data) {
    deviceDataList[deviceCount++] = data;
}

// 查询一天内的设备运行数据
int getDeviceDataWithinDay(sqlite3* db,const char* deviceName ,const char* timestamp, struct DeviceData deviceDataList[], int* numEntries)
{
    // 调用getCurrentDate并打印结果
    printf("Current Date: %s\n", timestamp);

    char sql[256];
    snprintf(sql, sizeof(sql), "SELECT * FROM DeviceData WHERE DeviceName = '%s' AND Timestamp >= '%s 00:00:00' AND Timestamp < '%s 23:59:59';", deviceName, timestamp, timestamp);

    sqlite3_stmt* stmt;
    int rc = sqlite3_prepare_v2(db, sql, -1, &stmt, NULL);
    if (rc != SQLITE_OK)
    {
        // 查询失败，打印错误信息
        printf("Error executing query: %s\n", sqlite3_errmsg(db));
        return 0; // 返回0表示查询失败
    }

    *numEntries = 0;

    while (sqlite3_step(stmt) == SQLITE_ROW)
    {
        struct DeviceData data;
        data.DataID = sqlite3_column_int(stmt, 0);
        strcpy(data.DeviceName , (const char*)sqlite3_column_text(stmt, 1));
        strcpy(data.Timestamp, (const char*)sqlite3_column_text(stmt, 2));
        data.StatusValue = sqlite3_column_int(stmt, 3);
        data.Mode = sqlite3_column_int(stmt, 4);
        data.Feature = sqlite3_column_double(stmt, 5);

        // 打印每次查询结果的参数
        printf("Entry #%d:\n", *numEntries);
        printf("  DataID: %d\n", data.DataID);
        printf("  DeviceName: %s\n", data.DeviceName);
        printf("  Timestamp: %s\n", data.Timestamp);
        printf("  StatusValue: %d\n", data.StatusValue);
        printf("  Mode: %d\n", data.Mode);
        printf("  Feature: %lf\n", data.Feature);

        deviceDataList[(*numEntries)++] = data;

        printf("Total Entries: %d\n", *numEntries); // 打印总条目数
    }

    sqlite3_finalize(stmt);
    return 1; // 返回1表示查询成功
}

// 解析时间戳字符串为 time_t
time_t parseTimestamp(const char* timestampStr)
{
    struct tm tm_time = {0}; // 初始化 struct tm 结构体

    if (sscanf(timestampStr, "%d-%d-%d %d:%d",
               &tm_time.tm_year, &tm_time.tm_mon, &tm_time.tm_mday,
               &tm_time.tm_hour, &tm_time.tm_min) == 5)
    {
        tm_time.tm_year -= 1900; // 年份需要减去 1900
        tm_time.tm_mon -= 1;     // 月份需要减去 1
        tm_time.tm_sec = 0;      // 秒钟部分设置为 0

        printf("Parsing timestamp string: %s\n", timestampStr);
        printf("Successfully parsed.\n");

        return mktime(&tm_time);
    }
    else
    {
        printf("Parsing timestamp string: %s\n", timestampStr);
        printf("Failed to parse.\n");
        return 0;
    }
}



// 获取最近的开机时间
time_t getLastBootTime(sqlite3* db,int deviceID)
{
    // 根据设备ID查询数据库获取最近的开机时间
    time_t lastBootTime = 0; // 初始化为0，表示未找到

    char sql[256];
    snprintf(sql, sizeof(sql), "SELECT LastBootTime FROM DeviceInfo WHERE DeviceID = %d;", deviceID);

    sqlite3_stmt* stmt;
    int rc = sqlite3_prepare_v2(db, sql, -1, &stmt, NULL);
    if (rc == SQLITE_OK && sqlite3_step(stmt) == SQLITE_ROW)
    {
        lastBootTime = sqlite3_column_int(stmt, 0);
    }

    sqlite3_finalize(stmt);
    return lastBootTime;
}

// 根据设备名获取设备ID
int getDeviceID(sqlite3* db, const char* deviceName) {
    int deviceID = -1; // 默认设备ID为-1，表示未找到

    char sql[256];
    snprintf(sql, sizeof(sql), "SELECT DeviceID FROM Device WHERE DeviceName = '%s';", deviceName);
    printf("SQL query: %s\n", sql); // 输出SQL查询语句

    sqlite3_stmt* stmt;
    int rc = sqlite3_prepare_v2(db, sql, -1, &stmt, NULL);
    if (rc == SQLITE_OK) {
        printf("sqlite3_prepare_v2 successful\n");

        sqlite3_reset(stmt); // 重置语句，以便可以再次执行
        int stepResult = sqlite3_step(stmt);

        if (stepResult == SQLITE_ROW) {
            deviceID = sqlite3_column_int(stmt, 0);
        } else if (stepResult == SQLITE_DONE) {
            printf("No results found.\n");
        } else {
            printf("sqlite3_step error: %s\n", sqlite3_errmsg(db));
        }

        sqlite3_finalize(stmt);
    } else {
        printf("sqlite3_prepare_v2 error: %s\n", sqlite3_errmsg(db));
    }

    return deviceID;
}


// 获取设备信息
bool getDevice(sqlite3* db, const char* deviceName, struct Device* device) {
    bool success = false;

    char sql[256];
    snprintf(sql, sizeof(sql), "SELECT * FROM Device WHERE DeviceName = '%s';", deviceName);
    printf("SQL query: %s\n", sql); // 输出SQL查询语句
    
    sqlite3_stmt* stmt;
    int rc = sqlite3_prepare_v2(db, sql, -1, &stmt, NULL);
    if (rc == SQLITE_OK) {
        if (sqlite3_step(stmt) == SQLITE_ROW) {
            device->DeviceID = sqlite3_column_int(stmt, 0);
            snprintf(device->DeviceName, sizeof(device->DeviceName), "%s", sqlite3_column_text(stmt, 1));
            snprintf(device->Type, sizeof(device->Type), "%s", sqlite3_column_text(stmt, 2));
            device->UserID = sqlite3_column_int(stmt, 3);
            success = true;
            printf("success\n");
        } else {
            printf("No results found.\n");
        }

        sqlite3_finalize(stmt);
    } else {
        printf("sqlite3_prepare_v2 error: %s\n", sqlite3_errmsg(db));
    }

    return success;
}







