#include "executor.h"
#include <QMessageBox>

// 对空调发指令
void Executor::sendAirConditionerCommand(const QString& deviceName, double temperature, AirConditioner::AirMode mode, bool powerOn, bool scheduleOn)
{
    QString command = "Sending command to air conditioner:\n";
    command += QString("Device Name: %1\n").arg(deviceName);
    command += QString("Temperature: %1°C\n").arg(temperature);
    command += QString("Mode: %1\n").arg(static_cast<int>(mode));
    command += QString("Power: %1\n").arg(powerOn ? "On" : "Off");
    command += QString("Schedule: %1\n").arg(scheduleOn ? "On" : "Off");

    // 模拟发送命令给空调
    QMessageBox::information(nullptr, "Air Conditioner Command", command);
}

// 对灯发指令
void Executor::sendLightCommand(const QString& deviceName,Light::LightMode mode, bool powerOn, bool scheduleOn)
{
    QString command = "Sending command to light:\n";
    command += QString("Device Name: %1\n").arg(deviceName);
    command += QString("Mode: %1\n").arg(static_cast<int>(mode));
    command += QString("Power: %1\n").arg(powerOn ? "On" : "Off");
    command += QString("Schedule: %1\n").arg(scheduleOn ? "On" : "Off");

    // 模拟发送命令给灯
    QMessageBox::information(nullptr, "Light Command", command);
}

// 对加湿器发指令
void Executor::sendHumidityCommand(const QString& deviceName, double humidity, bool powerOn)
{
    QString command = "Sending command to humidity:\n";
     command += QString("Device Name: %1\n").arg(deviceName);
    command += QString("Humidity: %1\n").arg(humidity);
    command += QString("Power: %1\n").arg(powerOn ? "On" : "Off");

    // 模拟发送命令给加湿器
    QMessageBox::information(nullptr, "Humidity Command", command);
}

