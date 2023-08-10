#include "device.h"

//设备类
void Device::turnOn() {
    state = State::On;
}

void Device::turnOff() {
    state = State::Off;
}

Device::State Device::getState() const {
    return state;
}

void Device::setState(State state) {
    this->state = state;
    //emit stateChanged(state);
}

//如果当前状态是关闭（State::Off），那么调用这个函数会将状态切换为打开；
//如果当前状态是打开（State::On），那么调用这个函数会将状态切换为关闭。
void Device::togglePower() {
    if (state == State::Off) {
        state = State::On;
    } else {
        state = State::Off;
    }
}

//空调
//空调
//空调

void AirConditioner::setMode(Mode mode) {
    this->mode = mode;
}

void AirConditioner::setTimer(int hours, int minutes, TimerType timerType) {
    this->timerHours = hours;
    this->timerMinutes = minutes;
    this->timerType = timerType;

    // 根据 timerType 进行相应的逻辑处理
    if (timerType == TimerType::On) {
        if (state == State::Off) {
            // 如果当前状态是关闭，则设置定时开启
             setState(State::On);
        }
    } else if (timerType == TimerType::Off) {
        if (state == State::On) {
            // 如果当前状态是开启，则设置定时关闭
             setState(State::Off);
        }
    }
}

void AirConditioner::setTemperature(double temperature) {
    this->temperature = temperature;
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

//加湿器
//加湿器
//加湿器

void Humidifier::setHumidity(int value) {
    this->humidity = value;
}

void Humidifier::setTimerOff(int hours) {
    this->timerOff = hours;
}

void Humidifier::setTimerOn(int hours) {
    this->timerOn = hours;
}

//灯
//灯
//灯

void Light::setMode(LightMode mode) {
    this->mode = mode;
}

void Light::setTimer(int hours) {
    this->timer = hours;
}
