/* util.c - 工具函数

通用功能函数 - 日志、转换、字符串处理等
JSON序列化和反序列化函数
错误处理函数 */

#include "util.h"

// 获取当前日期字符串，格式为 YYYY-MM-DD
const char* getCurrentDate() {
    static char currentDate[11]; // 10字符 + 终止符
    time_t now = time(NULL);
    struct tm* timeinfo = localtime(&now);
    strftime(currentDate, sizeof(currentDate), "%Y-%m-%d", timeinfo);
    return currentDate;
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
    double basePowerConsumption = 1000.0;

    // 每度温度调整耗电量（单位：瓦特小时/度）
    double powerConsumptionPerDegree = 10.0;

    // 不同模式下的额外耗电量（单位：瓦特小时/小时）
	// 制冷，制热，除湿，节能，睡眠，送风
    double extraPowerConsumption[] = { 50.0, 150.0, 200.0, 30.0, 20.0, 10.0 }; // 根据模式依次对应的耗电量

    // 获取一天内的设备数据
    struct DeviceData deviceDataList[100]; // 最大的设备数据条目数
    int numEntries = 0;

    if (getDeviceDataWithinDay(airDevice->DeviceID, getCurrentDate(), deviceDataList, &numEntries,db))
    {
        double totalRunningHours = 0.0;

        time_t lastBootTime = 0;
        int hasLastBootTime = 0;

        for (int i = 0; i < numEntries; i++) {
            time_t shutdownTime = parseTimestamp(deviceDataList[i].Timestamp);

            if (deviceDataList[i].StatusValue == ON) {
                if (!hasLastBootTime) {
                    lastBootTime = shutdownTime;
                    hasLastBootTime = 1;
                }
                else {
                    totalRunningHours += difftime(shutdownTime, lastBootTime) / 3600.0;
                    lastBootTime = shutdownTime;
                }
            }
        }

        if (hasLastBootTime) {

            // 初始化空调模式
            AirMode airMode = COOLING;
            //AirMode airMode = getAirModeFromString(deviceDataList[0].Mode);

            // 初始化用于计算总耗电量的变量
            double totalPower = basePowerConsumption * totalRunningHours;

            for (int i = 0; i < numEntries; i++) {

                // 获取当前条目的模式和状态
                AirMode currentAirMode =deviceDataList[i].Mode;
                State currentStatusValue = deviceDataList[i].StatusValue;

                // 计算时间间隔和额外耗电量
                double elapsedTime = difftime(parseTimestamp(deviceDataList[i].Timestamp), lastBootTime) / 3600.0;
                double extraPower = 0.0;
                
                // 如果当前条目的模式或状态与前一条不同，更新空调模式，并计算额外耗电量
                if (i == 0 || currentAirMode != airMode || currentStatusValue != deviceDataList[i - 1].StatusValue) 
                {
                    airMode = currentAirMode;
                    if (airMode < sizeof(extraPowerConsumption) / sizeof(extraPowerConsumption[0])) {
                        extraPower = extraPowerConsumption[airMode] * elapsedTime;
                    }
                }
                // 累加额外耗电量
                totalPower += extraPower;
                // 如果是最后一条数据或者设备关闭，累加总运行时间
                if (i == numEntries - 1 || deviceDataList[i].StatusValue == OFF) {
                    totalRunningHours += elapsedTime;
                }
                lastBootTime = parseTimestamp(deviceDataList[i].Timestamp);
            }
            
            totalPower += powerConsumptionPerDegree;

            return totalPower;
        }
    }
    return 0.0; // 无法计算耗电量
}

// 计算灯的总耗电量
double calculateLightTotalPower(const struct Device* lightDevice)
{
    // 初始功率消耗
    double powerConsumption = 50.0;

    // 假设每小时的功率消耗
    double whiteLightPowerPerHour = 10.0; // 单位：瓦特
    double yellowLightPowerPerHour = 15.0; // 单位：瓦特

    struct DeviceData deviceDataList[100]; // 最大的设备数据条目数
    int numEntries = 0;

    // 从数据库中查询设备在同一天内的所有运行数据
    if (getDeviceDataWithinDay(lightDevice->DeviceID, getCurrentDate(), deviceDataList, &numEntries,db))
    {
        // 初始化灯的模式和时间
        LightMode lightMode = WHITE; // 假设初始为白光模式
        time_t lastBootTime = 0;
        bool hasLastBootTime = false;

        for (int i = 0; i < numEntries; i++)
        {
            time_t shutdownTime = parseTimestamp(deviceDataList[i].Timestamp);

            if (deviceDataList[i].StatusValue == ON)
            {
                if (!hasLastBootTime)
                {
                    lastBootTime = shutdownTime;
                    hasLastBootTime = true;
                }
                else
                {
                    double elapsedTime = difftime(shutdownTime, lastBootTime) / 3600.0;

                    // 如果灯的模式发生变化，重新计算耗电量
                    if (deviceDataList[i].Mode != lightMode)
                    {
                        double usageHours = elapsedTime;

                        if (lightMode == WHITE) {
                            powerConsumption += whiteLightPowerPerHour * usageHours;
                        }
                        else if (lightMode == YELLOW) {
                            powerConsumption += yellowLightPowerPerHour * usageHours;
                        }

                    }

                    lastBootTime = shutdownTime;
                }
            }
        }
    }
    return powerConsumption;
}

// 计算加湿器的总耗电量
double calculateHumidityTotalPower(const struct Device* humidityDevice)
{
    // 假设加湿器的基本功率为 200 瓦特（单位：瓦特）
    double basePowerConsumption = 200.0;

    // 假设每升水的耗电量（单位：瓦特小时/升）
    double powerConsumptionPerLiter = 0.1;

    struct DeviceData deviceDataList[100]; // 最大的设备数据条目数
    int numEntries = 0;

    // 从数据库中查询设备在同一天内的所有运行数据
    if (getDeviceDataWithinDay(humidityDevice->DeviceID, getCurrentDate(), deviceDataList, &numEntries, db))
    {
        // 初始化总耗电量
        double totalRunningHours = basePowerConsumption;

        time_t lastBootTime = 0;
        bool hasLastBootTime = false;

        for (int i = 0; i < numEntries; i++)
        {
            time_t shutdownTime = parseTimestamp(deviceDataList[i].Timestamp);

            // 如果设备状态为开启（ON）
            if (deviceDataList[i].StatusValue == ON)
            {
                // 如果尚未记录上一次开启时间
                if (!hasLastBootTime)
                {
                    lastBootTime = shutdownTime;
                    hasLastBootTime = true;
                }
                else
                {
                    // 计算时间间隔，以小时为单位
                    double elapsedTime = difftime(shutdownTime, lastBootTime) / 3600.0;

                    // 如果湿度设备的状态发生变化，重新计算耗电量
                    if (deviceDataList[i].StatusValue != deviceDataList[i - 1].StatusValue)
                    {
                        // 计算使用时长，以小时为单位
                        double usageHours = elapsedTime;
                        // 获取当前设置湿度值
                        double humidityValue = deviceDataList[i].StatusValue;
                        // 计算每小时的耗水量
                        double waterConsumptionPerHour = 0.1 + 0.4 * (humidityValue / 100.0);

                        // 计算水消耗量和相应的电耗
                        double waterConsumed = waterConsumptionPerHour * usageHours;
                        double powerConsumed = waterConsumed * powerConsumptionPerLiter;
                        // 累加到基本功率消耗
                        basePowerConsumption += powerConsumed;
                    }
                    // 更新上一次开启时间
                    lastBootTime = shutdownTime;
                }
            }
        }

        // 计算总耗电量
        double totalPower = basePowerConsumption * totalRunningHours;

        return totalPower;
    }

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