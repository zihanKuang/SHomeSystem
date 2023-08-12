#include "device.h"

//设备类
void Device::turnOn() {
    state = State::ON;
}

void Device::turnOff() {
    state = State::OFF;
}

Device::State Device::getState() const {
    return state;
}

void Device::setState(State state) {
    this->state = state;
}

//如果当前状态是关闭（State::Off），那么调用这个函数会将状态切换为打开；
//如果当前状态是打开（State::On），那么调用这个函数会将状态切换为关闭。
void Device::togglePower() {
    if (state == State::OFF) {
        state = State::ON;
    } else {
        state = State::OFF;
    }
}

//void Device::updateWeeklyStats(int week, double powerConsumption, int usageTime) {
//    WeeklyStat weeklyData;
//    weeklyData.week = week;
//    weeklyData.totalPower = powerConsumption;
//    weeklyData.totalTime = usageTime;
//    weeklyStats.push_back(weeklyData);
//}

//double Device::calculateAveragePower() {
//    double totalPower = 0.0;
//    int totalTime = 0;

//    for (const WeeklyStat& weeklyData : weeklyStats) {
//        totalPower += weeklyData.totalPower;
//        totalTime += weeklyData.totalTime;
//    }

//    if (totalTime > 0) {
//        return totalPower / totalTime;
//    } else {
//        return 0.0;
//    }
//}

//空调
//空调
//空调

void AirConditioner::setMode(AirMode mode) {
    this->mode = mode;
}

AirConditioner::AirMode AirConditioner::getMode() const {
    return mode;
}

void AirConditioner::setTimer(int hours, int minutes, TimerType timerType) {
    this->timerHours = hours;
    this->timerMinutes = minutes;
    this->timerType = timerType;
}

void AirConditioner::setTemperature(double temperature) {
    this->temperature = temperature;
}
// 获取温度
double AirConditioner::getTemperature() const {
    return temperature;
}
void AirConditioner::setTimerHours(int hours) {
    this->timerHours = hours;
}
int AirConditioner::getTimerHours() const {
    return timerHours;
}
void AirConditioner::setTimerMinutes(int minutes) {
    this->timerMinutes = minutes;
}
int AirConditioner::getTimerMinutes() const {
    return timerMinutes;
}
void AirConditioner::setTimerType(TimerType type) {
    this->timerType = type;
}

AirConditioner::TimerType AirConditioner::getTimerType() const {
    if (timerType == TimerType::ON) {
        return TimerType::ON;
    } else if (timerType == TimerType::OFF) {
        return TimerType::OFF;
    } else {
        return TimerType::NOT_SET;
    }
}

QString AirConditioner::modeToString(AirConditioner::AirMode mode) {
    switch (mode) {
        case AirMode::HEATING:
            return "制热";
        case AirMode::COOLING:
            return "制冷";
        case AirMode::DEHUMIDIFICATION:
            return "除湿";
        case AirMode::ENERGY_SAVING:
            return "节能";
        case AirMode::QUIET:
            return "睡眠";
        case AirMode::AIR_SUPPLY:
            return "送风";
    }
}

//加湿器
//加湿器
//加湿器

void Humidifier::setHumidity(int value) {
    this->humidity = value;
}

int Humidifier::getHumidity() const {
    return humidity;
}

//灯
//灯
//灯

void Light::setMode(LightMode mode) {
    this->mode = mode;
}

// 获取灯光模式
Light::LightMode Light::getMode() const {
    return mode;
}

void Light::setTimerHours(int hours) {
    this->timerHours = hours;
}

void Light::setTimerMinutes(int minutes) {
    this->timerMinutes = minutes;
}

int Light::getTimerMinutes() const {
    return timerMinutes;
}

int Light::getTimerHours() const {
    return timerHours;
}

QString Light::modeToString(Light::LightMode mode) {
    switch (mode) {
        case LightMode::WHITE:
            return "冷光";
        case LightMode::YELLOW:
            return "暖光";
    }
}

void Light::setTimerType(TimerType type) {
    this->timerType = type;
}

Light::TimerType Light::getTimerType() const {
    if (timerType == TimerType::ON) {
        return TimerType::ON;
    } else if (timerType == TimerType::OFF) {
        return TimerType::OFF;
    } else {
        return TimerType::NOT_SET;
    }
}

void Light::setTimer(int hours, int minutes, TimerType timerType) {
    this->timerHours = hours;
    this->timerMinutes = minutes;
    this->timerType = timerType;

    // 根据 timerType 进行相应的逻辑处理
    if (timerType == TimerType::ON) {
        if ((getState() == State::OFF)) {
            // 如果当前状态是关闭，则设置定时开启
             setState(State::ON);
        }
    } else if (timerType == TimerType::OFF) {
        if (getState() == State::ON) {
            // 如果当前状态是开启，则设置定时关闭
             setState(State::OFF);
        }
    }
}

