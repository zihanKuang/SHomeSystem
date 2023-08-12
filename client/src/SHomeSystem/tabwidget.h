#ifndef STACKEDWIDGET_H
#define STACKEDWIDGET_H

#include <QWidget>
#include <QChart>
#include <device.h>
#include <QLabel>
#include <QtNetwork>

class myTimer {
public:
    //对应硬件名称
    std::string name;
    int current;
    int target;

    myTimer(std::string name = "", int current = 0, int target = 0) {
        this->name = name;
        this->current = current;
        this->target = target;
    }
};

namespace Ui {
class TabWidget;
}

class TabWidget : public QWidget
{
    Q_OBJECT

public:
    explicit TabWidget(QWidget *parent = nullptr);
    ~TabWidget();

public slots:
//    //判断离线/在线，提供不同的展示页面
//    void onServerConnectionFinished();

    // 空调温度变设置槽函数
    void onHostAirEditEditingFinished();
    void onLivingAirEditEditingFinished();
    void onSecondAirEditEditingFinished();

    // 空调定时按钮槽函数
    void onLivingAirTimeButtonClicked();
    void onHostAirTimeButtonClicked();
    void onSecondAirTimeButtonClicked();

//    void onHostAirTimerTimeChanged(const QTime &time);
//    void onLivingAirTimerTimeChanged(const QTime &time);
//    void onSecondAirTimerTimeChanged(const QTime &time);

    // 空调开关按钮槽函数
    void onHostAirPowerButtonClicked();
    void onLivingAirPowerButtonClicked();
    void onSecondAirPowerButtonClicked();

    // 空调模式combobox槽函数
    void onHostAirModeChanged(int index);
    void onLivingAirModeChanged(int index);
    void onSecondAirModeChanged(int index);

    // 空调展示代码
    void updateHostAirStatusLabel();
    void updateLivingAirStatusLabel();
    void updateSecondAirStatusLabel();

    //加湿器部分槽函数
    void updateHostHumidityStatusLabel();
    void updateLivingHumidityStatusLabel();
    void onHostHumidityBtnClicked();
    void onLivingHumidityBtnClicked();
    void onHostHumiditySliderChanged(int value);
    void onLivingHumiditySliderChanged(int value);
    void onHostHumiditySpinChanged(int value);
    void onLivingHumiditySpinChanged(int value);

    // 灯光定时时间改变槽函数
    void onLivingLightTimerTimeChanged(const QTime &time);
    void onHostLightTimerTimeChanged(const QTime &time);
    void onSecondLightTimerTimeChanged(const QTime &time);
    void updateHostLightStatusLabel();
    void updateLivingLightStatusLabel();
    void updateSecondLightStatusLabel();
    void onHostLightModeChanged(int index);
    void onLivingLightModeChanged(int index);
    void onSecondLightModeChanged(int index);
    void onHostLightButtonClicked();
    void onLivingLightButtonClicked();
    void onSecondLightButtonClicked();

public:

    //QNetworkAccessManager *networkAccessManager;

    AirConditioner *hostAir;//主卧空调
    AirConditioner *livingAir;//客厅空调
    AirConditioner *secondAir;//次卧空调

    Humidifier *livingHumidity; //客厅加湿器
    Humidifier *hostHumidity; //主卧加湿器

    Light *livingLight; //客厅灯
    Light *hostLight; //主卧灯
    Light *secondLight; //次卧灯

    //计时器标识 到 myTimer类 map
    std::map<int, myTimer*> TimerIndex2MyTimerMap;
    virtual void timeEvent(QTimerEvent*);


private:
    Ui::TabWidget *ui;
};

#endif // STACKEDWIDGET_H
