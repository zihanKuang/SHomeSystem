/* util.c - 工具函数

通用功能函数 - 日志、转换、字符串处理等
JSON序列化和反序列化函数
错误处理函数 */

#include "util.h"

// 获取当前日期字符串，格式为 YYYY-MM-DD
const char* getCurrentDate() {
    char* currentDate = (char*)malloc(11); // 10字符 + 终止符
    if (currentDate) {
        time_t now = time(NULL);
        struct tm* timeinfo = localtime(&now);
        strftime(currentDate, 11, "%Y-%m-%d", timeinfo);
    }
    return currentDate;
}

// 释放动态分配的日期字符串内存
void freeCurrentDate(char* currentDate) {
    if (currentDate) {
        free(currentDate);
    }
}

// 根据字符串获取空调模式枚举
AirMode getAirModeFromString(const char* modeStr) {
    if (strcmp(modeStr, "COOLING") == 0) {
        return COOLING;
    }
    else if (strcmp(modeStr, "HEATING") == 0) {
        return HEATING;
    }
    else if (strcmp(modeStr, "DEHUMIDIFY") == 0) {
        return DEHUMIDIFY;
    }
    else if (strcmp(modeStr, "ENERGY_SAVER") == 0) {
        return ENERGY_SAVER;
    }
    else if (strcmp(modeStr, "SLEEP") == 0) {
        return SLEEP;
    }
    else if (strcmp(modeStr, "FAN") == 0) {
        return FAN;
    }
    // 默认返回制冷模式
    return COOLING;
}

//// 日志函数
//void log(const char* msg) {
//	printf("%s\n", msg); 
//}

//// JSON序列化
//char* to_json(const User* u) {
//	cJSON* root = cJSON_CreateObject();
//	cJSON_AddStringToObject(root, "name", u->name);
//	// ...
//    char* json_string = cJSON_Print(root);
//    cJSON_Delete(root);
//    return json_string;
//}
//
//// 设备故障检测
//void checkDeviceFailure() {
//  // 分析日志、监控数据
//  // 检测故障 
//  // 触发警报
//}
//
//// 温度异常检测
//void checkTempAnomaly() {
//  // 获取温度数据
//  // 分析判断是否异常
//  // 触发警报
//}
//
//// 发送警报
//void sendAlert(User* user, Alert* alert) {
//  // 调用通知模块接口
//  // 发送警报
//}

// 计算空调的总耗电量
double calculateAirTotalPower(const struct Device* airDevice)
{
    // 假设空调的基本功率为 1000 瓦特（单位：瓦特）
    double basePowerConsumption = 500.0;

    // 每度温度调整耗电量（单位：瓦特小时/度）
    double powerConsumptionPerDegree = 10.0;

    // 不同模式下的额外耗电量（单位：瓦特小时/小时）
    // 制冷，制热，除湿，节能，睡眠，送风
    double extraPowerConsumption[] = { 50.0, 150.0, 200.0, 30.0, 20.0, 10.0 }; // 根据模式依次对应的耗电量

    // 获取一天内的设备数据
    struct DeviceData deviceDataList[100]; // 最大的设备数据条目数
    int numEntries = 0;

    printf("Starting calculation...\n");

    char* currentDate = getCurrentDate();
    if (!currentDate) {
        printf("Failed to get current date.\n");
        return 0.0;
    }

    if (getDeviceDataWithinDay(db, airDevice->DeviceName, currentDate, deviceDataList, &numEntries))
    {
        printf("Got device data within the day.\n");

        double totalRunningHours = 0.0;
        double totalBasePower = 0.0;
        double totalExtraPower = 0.0;
        double totalTempPower = 0.0;

        time_t lastBootTime = 0;
        int hasLastBootTime = 1;
        double elapsedTimeMinutes;

        for (int i = 0; i < numEntries; i++) {
            printf("Processing entry %d...\n", i);

            time_t shutdownTime = parseTimestamp(deviceDataList[i].Timestamp);

            printf("shutdownTime: %ld\n", shutdownTime);
            printf("lastBootTime: %ld\n", lastBootTime);

            if (deviceDataList[i].StatusValue == OFF) {
                elapsedTimeMinutes = difftime(shutdownTime, lastBootTime) / 60.0;
                totalRunningHours += elapsedTimeMinutes / 60.0; // 分钟转为小时

                // 计算温控功率
                if (i > 0 && deviceDataList[i].StatusValue == OFF) {
                    double tempChange = deviceDataList[i].Feature - deviceDataList[i - 1].Feature;
                    double tempPower = powerConsumptionPerDegree * tempChange;
                    totalTempPower += tempPower;
                }
                // 计算基本功率耗电量
                totalBasePower += basePowerConsumption * (elapsedTimeMinutes / 60.0);
            }
            else if (deviceDataList[i].StatusValue == ON) {
                if (!hasLastBootTime) {
                    lastBootTime = shutdownTime;
                    hasLastBootTime = 1;
                }
                else {
                    elapsedTimeMinutes = difftime(shutdownTime, lastBootTime) / 60.0;
                    totalRunningHours += elapsedTimeMinutes / 60.0; // 分钟转为小时
                    lastBootTime = shutdownTime;
                }
            }
            // 累加每个时间段的额外功率
            totalExtraPower += extraPowerConsumption[deviceDataList[i].Mode];
            printf("extraPowerConsumption[deviceDataList[i].Mode]: %f\n", extraPowerConsumption[deviceDataList[i].Mode]);
            printf("deviceDataList[i].mode: %d\n", deviceDataList[i].Mode);
            printf("totalExtraPower: %f\n", totalExtraPower);

            printf("elapsedTime: %f\n", elapsedTimeMinutes);
        }

        if (hasLastBootTime) {
            double totalPower = totalBasePower + totalExtraPower + totalTempPower;
            printf("totalRunningHours: %f\n", totalRunningHours);
            printf("totalPower: %f\n", totalPower);
            return totalPower;
        }
    }
    free(currentDate); // 释放动态分配的日期字符串内存

    return 0.0; // 无法计算耗电量
}



// 计算灯的总耗电量
double calculateLightTotalPower(const struct Device* lightDevice)
{
    // 假设白光模式的功率为 10 瓦特/小时（单位：瓦特/小时）
    double whiteLightPowerPerHour = 10.0;

    // 假设黄光模式的功率为 8 瓦特/小时（单位：瓦特/小时）
    double yellowLightPowerPerHour = 8.0;

    // 获取一天内的设备数据
    struct DeviceData deviceDataList[100]; // 最大的设备数据条目数
    int numEntries = 0;

    printf("Starting calculation...\n");

    char* currentDate = getCurrentDate();
    if (!currentDate) {
        printf("Failed to get current date.\n");
        return 0.0;
    }

    if (getDeviceDataWithinDay(db, lightDevice->DeviceName, currentDate, deviceDataList, &numEntries))
    {
        printf("Got device data within the day.\n");

        double powerConsumption = 0.0;
        time_t lastBootTime = 0;
        int hasLastBootTime = 0;
        double elapsedTimeMinutes;

        int lightMode = -1; // 假设初始模式为无效值

        for (int i = 0; i < numEntries; i++) {
            printf("Processing entry %d...\n", i);

            time_t shutdownTime = parseTimestamp(deviceDataList[i].Timestamp);

            printf("shutdownTime: %ld\n", shutdownTime);
            printf("lastBootTime: %ld\n", lastBootTime);

            if (deviceDataList[i].StatusValue == OFF) {
                elapsedTimeMinutes = difftime(shutdownTime, lastBootTime) / 60.0;

                // 如果有有效的上一次模式，计算耗电量
                if (lightMode != -1) {
                    double usageHours = elapsedTimeMinutes / 60.0; // 转换为小时

                    if (lightMode == WHITE) {
                        powerConsumption += whiteLightPowerPerHour * usageHours;
                    }
                    else if (lightMode == YELLOW) {
                        powerConsumption += yellowLightPowerPerHour * usageHours;
                    }
                }

                lastBootTime = shutdownTime;
            }
            else if (deviceDataList[i].StatusValue == ON) {
                if (!hasLastBootTime) {
                    lastBootTime = shutdownTime;
                    hasLastBootTime = 1;
                }
                else {
                    elapsedTimeMinutes = difftime(shutdownTime, lastBootTime) / 60.0;
                    lastBootTime = shutdownTime;
                }

                // 记录灯的模式
                lightMode = deviceDataList[i].Mode;
            }
        }

        free(currentDate); // 释放动态分配的日期字符串内存
        return powerConsumption;
    }

    free(currentDate); // 释放动态分配的日期字符串内存
    return 0.0; // 无法计算耗电量
}



// 计算加湿器的总耗电量
double calculateHumidityTotalPower(const struct Device* humidityDevice)
{
    // 假设加湿器的基本功率为 200 瓦特（单位：瓦特）
    double basePowerConsumption = 200.0;

    // 假设每升水的耗电量（单位：瓦特小时/升）
    double powerConsumptionPerLiter = 50;

    // 获取一天内的设备数据
    struct DeviceData deviceDataList[100]; // 最大的设备数据条目数
    int numEntries = 0;

    printf("Starting calculation...\n");

    char* currentDate = getCurrentDate();
    if (!currentDate) {
        printf("Failed to get current date.\n");
        return 0.0;
    }

    if (getDeviceDataWithinDay(db, humidityDevice->DeviceName, currentDate, deviceDataList, &numEntries))
    {
        printf("Got device data within the day.\n");

        double totalPowerConsumed = 0.0;
        time_t lastBootTime = 0;
        bool hasLastBootTime = 1;

        for (int i = 0; i < numEntries; i++)
        {
            printf("Processing entry %d...\n", i);

            time_t shutdownTime = parseTimestamp(deviceDataList[i].Timestamp);

            printf("shutdownTime: %ld\n", shutdownTime);
            printf("lastBootTime: %ld\n", lastBootTime);

            if (deviceDataList[i].StatusValue == OFF)
            {
                if (hasLastBootTime)
                {
                    printf("1111111111111111");
                    double elapsedTimeMinutes = difftime(shutdownTime, lastBootTime) / 60.0;

                    // 计算用水时长，以分钟为单位
                    double waterUsageMinutes = elapsedTimeMinutes;

                    // 获取当前设置湿度值
                    double humidityValue = deviceDataList[i].Feature;

                    // 计算每分钟的耗水量
                    double waterConsumptionPerMinute = 0.1 / 60.0 + 0.4 / 60.0 * (humidityValue / 100.0);

                    // 计算水消耗量和相应的电耗
                    double waterConsumed = waterConsumptionPerMinute * waterUsageMinutes;
                    printf("waterConsumed: %f\n", waterConsumed);
                    double powerConsumed = waterConsumed * powerConsumptionPerLiter;
                    printf("powerConsumed: %f\n", powerConsumed);

                    // 累加到总耗电量
                    totalPowerConsumed += powerConsumed;
                }
                lastBootTime = shutdownTime;
            }
            else if (deviceDataList[i].StatusValue == ON)
            {
                lastBootTime = shutdownTime;
                hasLastBootTime = true;
            }
        }

        free(currentDate); // 释放动态分配的日期字符串内存

        // 计算总耗电量，基本功率消耗加上用水的电耗
        double totalPower = basePowerConsumption + totalPowerConsumed;
        printf("basePowerConsumption: %f\n", basePowerConsumption);
        printf("totalPowerConsumed: %f\n", totalPowerConsumed);
        printf("totalPower: %f\n", totalPower);

        return totalPower;
    }

    free(currentDate); // 释放动态分配的日期字符串内存

    return 0.0; // 无法计算耗电量
}



const char* get_error_message(int error_code) {
    switch (error_code) {
        case 400:
            return "Bad Request";
        case 401:
            return "Unauthorized";
        case 403:
            return "Forbidden";
        case 404:
            return "Not Found";
        case 500:
            return "Internal Server Error";
        default:
            return "Unknown Error";
    }
}

void sendHttpError(struct MHD_Connection *connection, int status_code, const char *message) {
    const char *error_page = "<html><body><h1>Error</h1><p>%s</p></body></html>";
    char *error_response;

    // Create the error response body by formatting the error message
    int response_size = snprintf(NULL, 0, error_page, message);
    error_response = (char *)malloc(response_size + 1);
    snprintf(error_response, response_size + 1, error_page, message);

    // Send the error response
    struct MHD_Response *response = MHD_create_response_from_buffer(
        strlen(error_response), (void *)error_response, MHD_RESPMEM_MUST_FREE
    );
    MHD_add_response_header(response, "Content-Type", "text/html");
    int ret = MHD_queue_response(connection, status_code, response);

    // Clean up the response
    MHD_destroy_response(response);
}