#ifndef DEVICE_H
#define DEVICE_H

class Device {
public:
    enum class State { On, Off };//目前开还是关
    enum class TimerType { On, Off };//定时开还是关

    //virtual ~Device() {} //虚析构函数
    void turnOn();
    void turnOff();
    //状态设置
    State getState() const;
    void setState(State state);
    //控制开关
    void togglePower();

protected:
    State state = State::Off;
};

// 空调类
class AirConditioner : public Device {
public:

    //制冷，制热，除湿，节能，睡眠，送风
    enum class Mode { Heating, Cooling , Dehumidification, EnergySaving, Quiet, AirSupply };
    // 设置模式
    void setMode(Mode mode);
    // 设置温度
    void setTemperature(double temperature);
    // 设置定时
    void setTimer(int hours, int minutes, TimerType timerType);
    // 设置定时-小时
    void setTimerHours(int hours);
    int getTimerHours() const;
    // 设置定时-分钟
    void setTimerMinutes(int minutes);
    int getTimerMinutes() const;
    // 设置定时状态
    void setTimerType(TimerType type);

private:
    Mode mode;
    int timer;
    double temperature;

    int timerHours;
    int timerMinutes;
    TimerType timerType;
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
