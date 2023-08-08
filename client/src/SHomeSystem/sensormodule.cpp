#include "SensorModule.h"
#include <QDebug>
#include <cstdlib>
#include <ctime>

SensorModule::SensorModule(QObject *parent)
    : QObject(parent)
{
    // 使用随机数种子初始化
    std::srand(std::time(nullptr));
}

void SensorModule::collectTemperatureData()
{
    double temperature = generateRandomDouble(20, 30);
    qDebug() << "温度数据采集:" << temperature;

    // 实际应用中，这里可以调用发送数据到服务器的函数
    // sendDataToServer(temperature, 0, 0);
}

void SensorModule::collectHumidityData()
{
    double humidity = generateRandomDouble(40, 60);
    qDebug() << "湿度数据采集:" << humidity;

    // 实际应用中，这里可以调用发送数据到服务器的函数
    // sendDataToServer(0, humidity, 0);
}

void SensorModule::collectBrightnessData()
{
    double brightness = generateRandomDouble(100, 200);
    qDebug() << "亮度数据采集:" << brightness;

    // 实际应用中，这里可以调用发送数据到服务器的函数
    // sendDataToServer(0, 0, brightness);
}

double SensorModule::generateRandomDouble(double min, double max)
{
    // 生成min和max之间的随机实数
    return (std::rand() / (double)RAND_MAX) * (max - min) + min;
}

double SensorModule::readTemperatureSensor()
{
    // 在实际应用中，您应该从温度传感器中读取数据
    // 为了演示目的，我们使用介于20到30之间的随机值
    return generateRandomDouble(20, 30);
}

double SensorModule::readHumiditySensor()
{
    // 在实际应用中，您应该从湿度传感器中读取数据
    // 为了演示目的，我们使用介于40到60之间的随机值
    return generateRandomDouble(40, 60);
}

double SensorModule::readBrightnessSensor()
{
    // 在实际应用中，您应该从光敏传感器中读取数据
    // 为了演示目的，我们使用介于100到200之间的随机值
    return generateRandomDouble(100, 200);
}

double SensorModule::convertToDigital(double analogData)
{
    // 在实际应用中，如果需要，您可以执行模拟到数字的转换
    // 为了演示目的，我们直接返回模拟数据作为数字数据
    return analogData;
}

void SensorModule::sendDataToServer(double temperature, double humidity, double brightness)
{
    // 在实际应用中，您应该通过网络连接将数据发送到服务器
    // 在这里，我们简单地打印数据作为演示
    qDebug() << "发送数据到服务器 - 温度:" << temperature
             << " 湿度:" << humidity
             << " 亮度:" << brightness;
}
