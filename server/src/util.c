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
//	// 
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

// 解析时间戳字符串为 time_t
#include <stdio.h>
#include <time.h>

/* 添加一个变量 lastStartTime 来记录最近的开始信息的时间，
	以便计算关闭信息与最近的开始信息之间的时间间隔。
	在循环中，首先检查是否有完整的开始信息，
	然后计算关闭信息与最近的开始信息之间的时间间隔，
	并根据温度和模式计算该时间段内的额外功率消耗。
	在关闭信息后，将 recordStarted 设置为 false，
	以停止记录，并在下一个开始信息出现时重新开始记录。 */
	
double calculateAirTotalPower(const struct Device* airDevice) {
    // 假设空调的基本功率为 100 瓦特（单位：瓦特）
    double basePowerConsumption = 500.0;

    // 每度温度调整耗电量（单位：瓦特小时/度）
    double powerConsumptionPerDegree = 10.0;

    // 不同模式下的额外耗电量（单位：瓦特小时/小时）
    // 制冷，制热，除湿，节能，睡眠，送风
    double extraPowerConsumption[] = {50.0, 150.0, 200.0, 100.0, 50.0, 50.0}; // 根据模式依次对应的耗电量

    // 获取一天内的设备数据
    struct DeviceData deviceDataList[100]; // 最大的设备数据条目数
    int numEntries = 0;

    //printf("Starting calculation AirTotalPower...\n");

    const char* currentDate = getCurrentDate();
    //printf("Current Date: %s\n", currentDate);

    if (!currentDate) {
        printf("Failed to get current date.\n");
        return 0.0;
    }

    if (getDeviceDataWithinDay(db, airDevice->DeviceName, currentDate, deviceDataList, &numEntries)) {
        //printf("Got AirTotalPower data within the day.\n");

        // 定义变量以记录总功率消耗
        double totalPower = 0.0;

        // 记录第一个完整的开启时间
        time_t firstStartTime = 0;

        // 遍历设备数据列表
        for (int i = 0; i < numEntries; ++i) {
            // 检查是否为开启状态
            if (deviceDataList[i].StatusValue == 1 && deviceDataList[i].Feature != 0) {
                if (firstStartTime == 0) {
                    firstStartTime = deviceDataList[i].Timestamp;
                }
            } else {
                // 如果是关闭状态，计算时间间隔并累加到总功率中
                if (firstStartTime != 0) {
                    time_t endTime = deviceDataList[i].Timestamp;
                    double durationHours = difftime(endTime, firstStartTime) / 3600.0; // 将时间差转换为小时
                    int modeIndex = deviceDataList[i].Mode; // 获取模式索引
                    double extraPower = extraPowerConsumption[modeIndex] * durationHours; // 计算额外耗电量
                    totalPower += basePowerConsumption * durationHours + extraPower; // 累加到总功率中
                    firstStartTime = 0; // 重置第一个开启时间
                }
            }
        }

        // 打印总功率消耗
        printf("%s Total power consumption : %.2f Watt-hours.\n", airDevice->DeviceName, totalPower);

        free((char*)currentDate); // 释放 currentDate 分配的内存
        return totalPower;
    } else {
        printf("Failed to get AIR CONDITIONING data within the day.\n");
        free((char*)currentDate); // 释放 currentDate 分配的内存
        return 0.0;
    }
}


// 计算灯的总耗电量
double calculateLightTotalPower(const struct Device* lightDevice)
{
    // 假设白光模式的功率为 10 瓦特/小时（单位：瓦特/小时）
    double whiteLightPowerPerHour = 50.0;

    // 假设黄光模式的功率为 8 瓦特/小时（单位：瓦特/小时）
    double yellowLightPowerPerHour = 80.0;

    // 获取一天内的设备数据
    struct DeviceData deviceDataList[100]; // 最大的设备数据条目数
    int numEntries = 0;

    //printf("Starting calculation LightTotalPower...\n");

    const char* currentDate = getCurrentDate();
	//printf("Current Date: %s\n", currentDate);
	
    if (!currentDate) {
        printf("Failed to get current date.\n");
        return 0.0;
    }

    if (getDeviceDataWithinDay(db, lightDevice->DeviceName, currentDate, deviceDataList, &numEntries))
    {
        // 定义变量以记录总功率消耗
        double totalPower = 0.0;

        // 记录第一个完整的开启时间
        time_t firstStartTime = 0;

        // 遍历设备数据列表
        for (int i = 0; i < numEntries; ++i) {
            // 检查是否为开启状态
            if (deviceDataList[i].StatusValue == 1) {
                if (firstStartTime == 0) {
                    firstStartTime = deviceDataList[i].Timestamp;
                }
            } else {
                // 如果是关闭状态，计算时间间隔并累加到总功率中
                if (firstStartTime != 0) {
                    time_t endTime = deviceDataList[i].Timestamp;
                    double durationHours = difftime(endTime, firstStartTime) / 3600.0; // 将时间差转换为小时
                    int modeIndex = deviceDataList[i].Mode; // 获取模式索引
                    double modePowerPerHour = 0.0; // 初始化模式功率

                    // 根据模式索引选择对应的功率
                    switch (modeIndex) {
                        case WHITE:
                            modePowerPerHour = whiteLightPowerPerHour;
                            break;
                        case YELLOW:
                            modePowerPerHour = yellowLightPowerPerHour;
                            break;
                        default:
                            modePowerPerHour = 0.0; // 未知模式，功率为0
                            break;
                    }

                    double phasePower = modePowerPerHour * durationHours; // 计算阶段功率
                    totalPower += phasePower; // 累加到总功率中
                    firstStartTime = 0; // 重置第一个开启时间
                }
            }
        }

        // 打印总功率消耗
        printf("%s Total power consumption : %.2f Watt-hours.\n", lightDevice->DeviceName, totalPower);

        free((char*)currentDate); // 释放 currentDate 分配的内存
        return totalPower;
    }
    else {
        printf("Failed to get LightTotalPower data within the day.\n");
        free((char*)currentDate); // 释放 currentDate 分配的内存
        return 0.0;
    }
}



// 计算加湿器的总耗电量
double calculateHumidityTotalPower(const struct Device* humidityDevice)
{
    // 假设加湿器的基本功率为 20 瓦特（单位：瓦特）
    double basePowerConsumption = 20.0;

    // 假设每升水的耗电量（单位：瓦特小时/升）
    double powerConsumptionPerLiter = 10;

    // 获取一天内的设备数据
    struct DeviceData deviceDataList[100]; // 最大的设备数据条目数
    int numEntries = 0;
	
	double humidity=0;

    //printf("Starting calculation HumidityTotalPower...\n");

    const char* currentDate = getCurrentDate();

    if (!currentDate) {
        printf("Failed to get current date.\n");
        return 0.0;
    }

    // 查询一天内的设备运行数据
    if (getDeviceDataWithinDay(db, humidityDevice->DeviceName, currentDate, deviceDataList, &numEntries))
    {
        //printf("Got HumidityTotalPower data within the day.\n");

        // 如果没有获取到任何设备数据，直接返回基本功率
        if (numEntries == 0) {
            printf("No HumidityTotalPower data found for %s on %s\n", humidityDevice->DeviceName, currentDate);
            free((char*)currentDate); // 释放动态分配的日期字符串内存
            return 0;
        }

         // 定义变量以记录总功率消耗
        double totalPower = 0.0;

        // 记录第一个完整的开启时间
        time_t firstStartTime = 0;

        // 遍历设备数据列表
        for (int i = 0; i < numEntries; ++i) {
            // 检查是否为开启状态
            if (deviceDataList[i].StatusValue == 1) {
                if (firstStartTime == 0) {
                    firstStartTime = deviceDataList[i].Timestamp;
					humidity = deviceDataList[i].Feature; // 获取湿度数据
                }
            } else {
                // 如果是关闭状态，计算时间间隔并累加到总功率中
                if (firstStartTime != 0) {
                    time_t endTime = deviceDataList[i].Timestamp;
                    double durationHours = difftime(endTime, firstStartTime) / 3600.0; // 将时间差转换为小时
                    double phasePower = basePowerConsumption * durationHours * humidity; // 计算阶段功率
                    totalPower += phasePower; // 累加到总功率中
                    firstStartTime = 0; // 重置第一个开启时间
                }
            }
        }

        // 打印总功率消耗
        printf("%s Total power consumption : %.2f Watt-hours.\n", humidityDevice->DeviceName, totalPower);

        free((char*)currentDate); // 释放动态分配的日期字符串内存
        return totalPower;
    }
    else {
        printf("Failed to get HumidityTotalPower data within the day.\n");
        free((char*)currentDate); // 释放动态分配的日期字符串内存
        return 0.0;
    }
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