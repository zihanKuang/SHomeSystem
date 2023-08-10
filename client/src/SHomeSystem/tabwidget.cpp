#include "tabwidget.h"
#include "ui_tabwidget.h"

TabWidget::TabWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::TabWidget)
{
    ui->setupUi(this);

    // 初始化设备实例
    hostAir = new AirConditioner();
    livingAir = new AirConditioner();
    secondAir = new AirConditioner();

    livingHumidity = new Humidifier();
    hostHumidity = new Humidifier();

    livingLight = new Light();
    hostLight = new Light();
    secondLight = new Light();

    //空调模式
    connect(ui->hostAirMode, QOverload<int>::of(&QComboBox::currentIndexChanged),
            this, &TabWidget::onHostAirModeChanged);
    connect(ui->livingAirMode, QOverload<int>::of(&QComboBox::currentIndexChanged),
            this, &TabWidget::onLivingAirModeChanged);
    connect(ui->secondAirMode, QOverload<int>::of(&QComboBox::currentIndexChanged),
            this, &TabWidget::onSecondAirModeChanged);

    // 空调温度编辑
    connect(ui->hostAirEdit, &QLineEdit::editingFinished,
            this, &TabWidget::onHostAirEditEditingFinished);
    connect(ui->livingAirEdit, &QLineEdit::editingFinished,
            this, &TabWidget::onLivingAirEditEditingFinished);
    connect(ui->secondAirEdit, &QLineEdit::editingFinished,
            this, &TabWidget::onSecondAirEditEditingFinished);

    // 空调定时关闭和开启
    connect(ui->hostAirTime, &QTimeEdit::editingFinished,
                this, &TabWidget::onHostAirTimerButtonClicked);
    connect(ui->livingAirTime, &QTimeEdit::editingFinished,
                this, &TabWidget::onLivingAirTimerButtonClicked);
    connect(ui->secondAirTime, &QTimeEdit::editingFinished,
                this, &TabWidget::onSecondAirTimerButtonClicked);

    //空调开关
    connect(ui->hostAirBtn, &QPushButton::clicked,
                this, &TabWidget::onHostAirPowerButtonClicked);
    connect(ui->livingAirBtn, &QPushButton::clicked,
                this, &TabWidget::onLivingAirPowerButtonClicked);
    connect(ui->secondAirBtn, &QPushButton::clicked,
                this, &TabWidget::onSecondAirPowerButtonClicked);

}

// 空调温度编辑完成槽函数
void TabWidget::onHostAirEditEditingFinished()
{
    double temperature = ui->hostAirEdit->text().toDouble();
    hostAir->setTemperature(temperature);
}
void TabWidget::onLivingAirEditEditingFinished()
{
    double temperature = ui->livingAirEdit->text().toDouble();
    livingAir->setTemperature(temperature);
}
void TabWidget::onSecondAirEditEditingFinished()
{
    double temperature = ui->secondAirEdit->text().toDouble();
    secondAir->setTemperature(temperature);
}

//空调定时
void TabWidget::onHostAirTimerButtonClicked()
{
    // 获取定时时间的小时和分钟
    int hours = ui->hostAirTime->time().hour();
    int minutes = ui->hostAirTime->time().minute();

    // 获取空调的状态
    Device::State airState = hostAir->getState();

    // 判断空调状态并设置定时值
    if (airState == Device::State::On) {
        hostAir->setTimer(hours, minutes, Device::TimerType::Off);
    } else {
        hostAir->setTimer(hours, minutes, Device::TimerType::On);
    }
}
void TabWidget::onLivingAirTimerButtonClicked()
{
    // 获取定时时间
    QTime timerTime = ui->secondAirTime->time();
    // 获取空调的状态
    Device::State airState = livingAir->getState();

    // 判断空调状态并设置定时值
    if (airState == Device::State::On) {
        livingAir->setTimer(timerTime.hour(), timerTime.minute(), Device::TimerType::Off);
    } else {
        livingAir->setTimer(timerTime.hour(), timerTime.minute(), Device::TimerType::On);
    }
}
void TabWidget::onSecondAirTimerButtonClicked()
{
    // 获取定时时间
    QTime timerTime = ui->secondAirTime->time();

    // 获取空调的状态
    Device::State airState = secondAir->getState();

    // 判断空调状态并设置定时值
    if (airState == Device::State::On) {
        secondAir->setTimer(timerTime.hour(), timerTime.minute(), Device::TimerType::Off);
    } else {
        secondAir->setTimer(timerTime.hour(), timerTime.minute(), Device::TimerType::On);
    }
}

// 空调开关按钮点击槽函数
void TabWidget::onHostAirPowerButtonClicked()
{
    hostAir->togglePower();
}
void TabWidget::onLivingAirPowerButtonClicked()
{
    livingAir->togglePower();
}
void TabWidget::onSecondAirPowerButtonClicked()
{
    secondAir->togglePower();
}

//空调模式设置槽函数
void TabWidget::onHostAirModeChanged(int index)
{
    AirConditioner::Mode newMode = static_cast<AirConditioner::Mode>(index);
    hostAir->setMode(newMode);
}
void TabWidget::onLivingAirModeChanged(int index)
{
    AirConditioner::Mode newMode = static_cast<AirConditioner::Mode>(index);
    livingAir->setMode(newMode);
}
void TabWidget::onSecondAirModeChanged(int index)
{
    AirConditioner::Mode newMode = static_cast<AirConditioner::Mode>(index);
    secondAir->setMode(newMode);
}

TabWidget::~TabWidget()
{
    delete ui;
}
