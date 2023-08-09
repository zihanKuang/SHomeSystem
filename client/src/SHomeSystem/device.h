#ifndef DEVICE_H
#define DEVICE_H

class Device {
public:
    enum class State { Off, On };

    //virtual ~Device() {} //虚析构函数
    void turnOn();
    void turnOff();

protected:
    State state = State::Off;
};

// 空调类
class AirConditioner : public Device {
public:

    enum class Mode { Heating, Cooling };
    enum class Function { Dehumidification, EnergySaving, Quiet };

    // 设置模式
    void setMode(Mode mode);
    // 设置功能
    void setFunction(Function func);
    // 设置定时
    void setTimer(int hours);

private:
    //State state= State::Off;
    Mode mode;
    Function function;
    int timer;
};

class Humidifier : public Device {
public:

    // 设置湿度
    void setHumidity(int value);
    // 设置湿度
    void setTimerOff(int hours);
    // 设置湿度
    void setTimerOn(int hours);

private:
    //State state= State::Off;
    int humidity;
    int timerOff;
    int timerOn;
};

class Light : public Device {
public:
    enum class LightMode { White, Yellow };

    // 设置灯光模式
    void setMode(LightMode mode);
    // 设置定时关灯
    void setTimer(int hours);

private:
    //State state= State::Off;
    LightMode mode;
    int timer;
};

#endif // DEVICE_H
