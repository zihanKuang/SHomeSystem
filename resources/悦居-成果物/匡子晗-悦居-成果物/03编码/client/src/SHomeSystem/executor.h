#ifndef EXECUTOR_H
#define EXECUTOR_H

#include <device.h>

class Executor {

public:
    // 对空调发指令
    void sendAirConditionerCommand(const QString& deviceName, double temperature, AirConditioner::AirMode mode, bool powerOn, bool scheduleOn);

    // 对灯发指令
    void sendLightCommand(const QString& deviceName, Light::LightMode mode, bool powerOn, bool scheduleOn);

    // 对加湿器发指令
    void sendHumidityCommand(const QString& deviceName, double humidity, bool powerOn, bool flag);

};

#endif // EXECUTOR_H
