#ifndef DB_H
#define DB_H

#include <sqlite3.h>
#include <stdbool.h>
#include <string.h>
#include <stdio.h>
#include <time.h>

#define PASSWORD_LENGTH 32

// 数据库连接句柄
extern sqlite3* db;

struct Device {
    int DeviceID;
    char DeviceName[255];
    char Type[255];
    int UserID; // Foreign key reference to UserData
};

struct DeviceData {
    int DataID;
    char DeviceName[255];
    char Timestamp[20];
    int StatusValue;
    int Mode;   // 枚举类：模式
    double Feature; // 空调：温度 or 加湿器：湿度
};

struct EnvironmentData {
    int DataID;
    char Timestamp[20]; // Assuming DATETIME is stored as string
    float Temperature;
    float Humidity;
};

struct UserData {
    int UserID;
    char UserName[255];
    char Password[255];
};

struct DeviceDataList {
    struct DeviceData data;
    struct DeviceDataList* next;
};

// 打开数据库
bool openDatabase(const char* databaseName);

// 关闭数据库连接
void closeDatabase();

// 检查用户名是否唯一
bool isUsernameUnique(sqlite3* db, const char* username);

// 保存用户注册信息
bool saveUser(sqlite3* db, const char* username, const char* password);

// 获取用户信息
bool getUserData(sqlite3* db, const char* username, char* password);

// 从数据库中获取设备数据
bool getDeviceData(sqlite3* db, int deviceID, struct DeviceData* deviceData);

// 从数据库中获取设备在同一天内的所有运行数据
int getDeviceDataWithinDay(sqlite3* db, const char* deviceName, const char* timestamp, struct DeviceData deviceDataList[], int* numEntries);

time_t parseTimestamppp(const char* timestampStr);
time_t getLastBootTime(sqlite3* db, int deviceID);
// 根据设备名获取设备ID
int getDeviceID(sqlite3* db, const char* deviceName);
// 获取设备信息
bool getDevice(sqlite3* db, const char* deviceName, struct Device* device);


#endif // DB_H
