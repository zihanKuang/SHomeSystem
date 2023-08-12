    #ifndef DEVICE_H
#define DEVICE_H

#include <vector>
#include <QString>
class Device {
public:
    enum class State { ON, OFF }; // 目前开还是关
    enum class TimerType { ON, OFF ,NOT_SET}; // 定时开还是关

//    struct WeeklyStat {
//      int week; // 周序号
//      double totalPower; // 周耗电量
//      int totalTime; // 周使用时长
//    };

//    std::vector<WeeklyStat> weeklyStats;

    void turnOn();
    void turnOff();
    //状态设置
    State getState() const;
    void setState(State state);
    //控制开关
    void togglePower();

//    //更新每周的统计数据
//    void updateWeeklyStats(int week, double powerConsumption, int usageTime);
//    //平均功率计算函数
//    double calculateAveragePower();

protected:
    State state = State::OFF;
};

// 空调类
class AirConditioner : public Device {
public:

    //制冷，制热，除湿，节能，睡眠，送风
    enum class AirMode { HEATING, COOLING, DEHUMIDIFICATION, ENERGY_SAVING, QUIET, AIR_SUPPLY };

    // 设置模式
    void setMode(AirMode mode);
    AirMode getMode() const;
    // 设置温度
    void setTemperature(double temperature);
    // 获取温度
    double getTemperature() const;
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
    // 获取定时器类型
    TimerType getTimerType() const;
    //
    QString modeToString(AirMode mode);

private:
    AirMode mode;
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
    // 获取湿度
    int getHumidity() const;

private:
    int humidity;
};

class Light : public Device {
public:
    //冷光，暖光
    enum class LightMode { WHITE, YELLOW };

    // 设置灯光模式
    void setMode(LightMode mode);
    // 获取灯光模式
    LightMode getMode() const;

    // 设置定时关灯
    void setTimerHours(int hours);
    void setTimerMinutes(int minutes);
    int getTimerMinutes() const;
    int getTimerHours() const;


    // 设置定时状态
    void setTimerType(TimerType type);
    // 获取定时器类型
    TimerType getTimerType() const;

    // 设置定时
    void setTimer(int hours, int minutes, TimerType timerType);

    QString modeToString(LightMode mode);

private:
    LightMode mode;
    int timer;
    int timerHours; // Timer hours
    int timerMinutes; // Timer minutes
    TimerType timerType;
};

#endif // DEVICE_H
