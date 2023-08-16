#include "SensorModule.h"
#include <QDebug>
#include <cstdlib>
#include <ctime>
#include <QTime>

SensorModule::SensorModule(QObject *parent)
    : QObject(parent),
      temperatureRange(15, 38),
      humidityRange(30, 80),
      brightnessRange(100, 200)
{
    // 使用随机数种子初始化
    std::srand(std::time(nullptr));

    // 设置定时器，定时采集数据并进行自动控制
    QTimer* autoControlTimer = new QTimer(this);
    connect(autoControlTimer, &QTimer::timeout, this, &SensorModule::performAutoControl);
    autoControlTimer->start(30*60*1000); // 每30min执行一次
}

void SensorModule::performAutoControl()
{
    //全屋一起监控，不区分房间了
    double temperature = readSensorData(temperatureRange);
    double humidity = readSensorData(humidityRange);
    double brightness = readSensorData(brightnessRange);

    Executor executor;
    // 空调自动控制逻辑示例
    if (temperature > 32) {
        executor.sendAirConditionerCommand("主卧空调", 26, AirConditioner::AirMode::COOLING, true, true);
    } else if (temperature < 20) {
        executor.sendAirConditionerCommand("主卧空调", 26, AirConditioner::AirMode::HEATING, true, true);
    }

    // 灯自动控制逻辑示例
    if (brightness < 150) {
        executor.sendLightCommand("客厅灯", Light::LightMode::WHITE, true, true);
    }

    // 加湿器自动控制逻辑示例
    if (humidity < 50) {
        executor.sendHumidityCommand("加湿器", 60, true);
    } else if (humidity > 70) {
        executor.sendHumidityCommand("加湿器", 40, true);
    }

    // 根据时间自动控制灯
    QTime currentTime = QTime::currentTime();
    if (currentTime >= QTime(18, 0) || currentTime <= QTime(6, 0)) {
        executor.sendLightCommand("客厅灯", Light::LightMode::WHITE, true, true);
    } else {
        executor.sendLightCommand("客厅灯", Light::LightMode::WHITE, false, true);
    }
}

double SensorModule::readSensorData(const QPair<double, double>& range)
{
    return generateRandomDouble(range.first, range.second);
}

double SensorModule::generateRandomDouble(double min, double max)
{
    return (std::rand() / (double)RAND_MAX) * (max - min) + min;
}

