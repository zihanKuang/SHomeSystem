#ifndef UTIL_H
#define UTIL_H

#include "microhttpd.h"
#include <stdio.h>
#include <time.h>
#include "cJSON.h" 
#include "db.h" 
#include <math.h>
#include <stdlib.h>

typedef enum {
    WHITE,
    YELLOW
} LightMode;

typedef enum {
    COOLING,
    HEATING,
    DEHUMIDIFY,
    ENERGY_SAVER,
    SLEEP,
    FAN
} AirMode;

typedef enum {
    ON,
    OFF
} State;

// 日志函数
//void log(const char* msg);

//// JSON序列化
//char* to_json(const User* u);
//
//// 设备故障检测
//void checkDeviceFailure();
//
//// 温度异常检测
//void checkTempAnomaly();
//
//// 发送警报
//void sendAlert(User* user, Alert* alert);

// 计算空调的总耗电量
double calculateAirTotalPower(const struct Device* airDevice);

// 计算灯的总耗电量
double calculateLightTotalPower(const struct Device* lightDevice);

// 计算加湿器的总耗电量
double calculateHumidityTotalPower(const struct Device* humidityDevice);

const char* getCurrentDate();

void freeCurrentDate(char* currentDate);

AirMode getAirModeFromString(const char* modeStr);

const char* get_error_message(int error_code);

void sendHttpError(struct MHD_Connection *connection, int status_code, const char *message);

#endif // UTIL_H
