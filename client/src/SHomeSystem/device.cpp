#include "device.h"

void Device::turnOn() {
    state = State::On;
}

void Device::turnOff() {
    state = State::Off;
}

//空调
void AirConditioner::setMode(Mode mode) {
    this->mode = mode;
}

void AirConditioner::setFunction(Function func) {
    this->function = func;
}

void AirConditioner::setTimer(int hours) {
    this->timer = hours;
}

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
void Light::setMode(LightMode mode) {
    this->mode = mode;
}

void Light::setTimer(int hours) {
    this->timer = hours;
}
