/* util.c - 工具函数

通用功能函数 - 日志、转换、字符串处理等
JSON序列化和反序列化函数
错误处理函数 */

#include <time.h>
#include "db.h" // 包含数据库相关的头文件

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

// 计算空调的总耗电量
double calculateAirTotalPower(const struct DeviceData* airDeviceData)
{
    // 假设空调的基本功率为 1000 瓦特（单位：瓦特）
    double basePowerConsumption = 1000.0;

    // 每度温度调整耗电量（单位：瓦特小时/度）
    double powerConsumptionPerDegree = 10.0;

    // 不同模式下的额外耗电量（单位：瓦特小时/小时）
	// 制冷，制热，除湿，节能，睡眠，送风
    double extraPowerConsumption[] = { 50.0, 150.0, 200.0, 30.0, 20.0, 10.0 }; // 根据模式依次对应的耗电量

    // 获取空调设备的模式
    AirConditioner::AirMode airMode = static_cast<AirConditioner::AirMode>(airDeviceData->Mode);

    // 获取设备状态数据的时间戳
    struct tm timestamp;
    strptime(airDeviceData->Timestamp, "%Y-%m-%d %H:%M:%S", &timestamp);

    // 获取当前时间
    time_t currentTime = time(NULL);
    struct tm* currentTM = localtime(&currentTime);

    // 计算使用时长（单位：小时）
    double usageHours = difftime(currentTime, mktime(&timestamp)) / 3600.0;

    // 从数据库中查询设备在同一天内的所有运行数据
    QList<DeviceData> deviceDataList;
    if (getDeviceDataWithinDay(airDeviceData->DeviceID, airDeviceData->Timestamp, deviceDataList))
    {
        double totalRunningHours = 0.0;

        QDateTime lastBootTime;
        bool hasLastBootTime = false;

        for (const DeviceData& data : deviceDataList)
        {
            QDateTime shutdownTime = QDateTime::fromString(data.Timestamp, Qt::ISODate);

            if (data.StatusValue == Device::State::ON) {
                if (!hasLastBootTime) {
                    lastBootTime = shutdownTime;
                    hasLastBootTime = true;
                } else {
                    totalRunningHours += lastBootTime.secsTo(shutdownTime) / 3600.0;
                    lastBootTime = shutdownTime;
                }
            }
        }

        // 根据不同模式计算总耗电量
        if (static_cast<int>(airMode) < sizeof(extraPowerConsumption) / sizeof(extraPowerConsumption[0]))
        {
            // 计算基本功率和额外耗电量
            double totalPower = basePowerConsumption * totalRunningHours;
            totalPower += extraPowerConsumption[static_cast<int>(airMode)] * totalRunningHours;

            // 根据温度调整耗电量
            double temperatureAdjustment = fabs(airDeviceData->StatusValue - 25.0); // 假设基准温度为 25 度
            totalPower += powerConsumptionPerDegree * temperatureAdjustment;

            return totalPower;
        }
    }

    return 0.0; // 无法计算耗电量
}

// 计算灯的总耗电量
double calculateLightTotalPower(const struct DeviceData* deviceData)
{
    double powerConsumption = 50.0;

    // 假设每小时的功率消耗
    double whiteLightPowerPerHour = 10.0; // 单位：瓦特
    double yellowLightPowerPerHour = 15.0; // 单位：瓦特

    // 获取灯的模式
    enum LightMode lightMode = static_cast<enum LightMode>(deviceData->Mode);

    // 从数据库中查询设备在同一天内的所有运行数据
    QList<DeviceData> deviceDataList;
    if (getDeviceDataWithinDay(deviceData->DeviceID, deviceData->Timestamp, deviceDataList))
    {
        for (const DeviceData& data : deviceDataList)
        {
            // 获取关机时间和最近的开机时间
            QDateTime shutdownTime = QDateTime::fromString(data.Timestamp, Qt::ISODate);
            QDateTime lastBootTime = getLastBootTime(data.DeviceID);

            if (lastBootTime.isValid()) {
                // 计算运行时间（单位：毫秒）
                qint64 runningTimeMillis = shutdownTime.toMSecsSinceEpoch() - lastBootTime.toMSecsSinceEpoch();

                // 计算一天之内的运行时间
                qint64 oneDayMillis = 24 * 60 * 60 * 1000; // 一天的毫秒数
                qint64 totalRunningTimeMillis = (runningTimeMillis % oneDayMillis);

                // 将毫秒转换为小时
                double totalRunningHours = static_cast<double>(totalRunningTimeMillis) / (60 * 60 * 1000);

                // 根据不同模式计算总耗电量
                if (lightMode == LightMode::WHITE) {
                    powerConsumption += whiteLightPowerPerHour * totalRunningHours;
                } else if (lightMode == LightMode::YELLOW) {
                    powerConsumption += yellowLightPowerPerHour * totalRunningHours;
                }
            }
        }
    }

    return powerConsumption;
}

// 计算加湿器的总耗电量
double calculateHumidityTotalPower(const struct DeviceData* humidityDeviceData)
{
    // 假设加湿器的基本功率为 200 瓦特（单位：瓦特）
    double basePowerConsumption = 200.0;

    // 假设每升水的耗电量（单位：瓦特小时/升）
    double powerConsumptionPerLiter = 0.1;

    // 获取设备状态数据的时间戳
    struct tm timestamp;
    strptime(humidityDeviceData->Timestamp, "%Y-%m-%d %H:%M:%S", &timestamp);

    // 获取当前时间
    time_t currentTime = time(NULL);
    struct tm* currentTM = localtime(&currentTime);

    // 从数据库中查询设备在同一天内的所有运行数据
    QList<DeviceData> deviceDataList;
    if (getDeviceDataWithinDay(humidityDeviceData->DeviceID, humidityDeviceData->Timestamp, deviceDataList))
    {
        double totalRunningHours = 0.0;

        QDateTime lastBootTime;
        bool hasLastBootTime = false;

        for (const DeviceData& data : deviceDataList)
        {
            QDateTime shutdownTime = QDateTime::fromString(data.Timestamp, Qt::ISODate);

            if (data.StatusValue == Device::State::ON) {
                if (!hasLastBootTime) {
                    lastBootTime = shutdownTime;
                    hasLastBootTime = true;
                } else {
                    totalRunningHours += lastBootTime.secsTo(shutdownTime) / 3600.0;
                    lastBootTime = shutdownTime;
                }
            }
        }

        // 计算使用时长（单位：小时）
        double usageHours = difftime(currentTime, mktime(&timestamp)) / 3600.0;

        // 获取湿度值（假设取值范围为 0 到 100）
        double humidityValue = humidityDeviceData->StatusValue;

        // 将湿度值映射到耗水量范围（假设映射到 0.1 到 0.5 升/小时）
        double waterConsumptionPerHour = 0.1 + 0.4 * (humidityValue / 100.0);

        // 计算总耗电量
        double totalPower = basePowerConsumption * usageHours;

        // 根据每小时的耗水量计算额外耗电量
        double waterConsumed = waterConsumptionPerHour * totalRunningHours;
        double powerConsumed = waterConsumed * powerConsumptionPerLiter;
        totalPower += powerConsumed;

        return totalPower;
    }

    return 0.0; // 无法计算耗电量
}


