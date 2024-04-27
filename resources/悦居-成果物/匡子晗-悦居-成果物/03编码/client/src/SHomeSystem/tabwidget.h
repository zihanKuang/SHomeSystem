#ifndef TABWIDGET_H
#define TABWIDGET_H

#include <QWidget>
#include <QChart>
#include <device.h>
#include <QLabel>
#include <QtNetwork>
#include <QMap>
#include <QSet>
#include "executor.h"

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
    //判断离线/在线，提供不同的展示页面
    void onServerConnectionFinished();

    // 处理页面切换信号的槽函数
    void handleTabChange(int);
    // 发送请求请求耗电量
    void sendDeviceTotalPowerRequest(const QString& url, const QString& deviceName);

    // 声明 sendDataToServer 函数
    void sendAirDataToServer(Device::State state, double temperature,
                             QDateTime &timestamp, AirConditioner::AirMode mode,const QString& deviceName);
    void sendLightDataToServer(Device::State state, QDateTime &timestamp, Light::LightMode mode,const QString& deviceName);
    void sendHumidityDataToServer(Device::State state, double humidity, QDateTime &timestamp,const QString& deviceName);

    // 空调温度变设置槽函数
    void onHostAirEditEditingFinished();
    void onLivingAirEditEditingFinished();
    void onSecondAirEditEditingFinished();

    // 空调定时按钮槽函数
    void onLivingAirTimeButtonClicked();
    void onHostAirTimeButtonClicked();
    void onSecondAirTimeButtonClicked();

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
    void updateHostHumidityStatusLabel(bool);
    void updateLivingHumidityStatusLabel(bool);
    void onHostHumidityBtnClicked();
    void onLivingHumidityBtnClicked();
    void onHostHumiditySliderChanged(int value);
    void onLivingHumiditySliderChanged(int value);
    void onHostHumiditySpinChanged(int value);
    void onLivingHumiditySpinChanged(int value);

    // 灯光定时时间改变槽函数
    //删除数值设置槽函数
    //void onLivingLightTimerTimeChanged(const QTime &time);
    //void onHostLightTimerTimeChanged(const QTime &time);
    //void onSecondLightTimerTimeChanged(const QTime &time);
    void updateHostLightStatusLabel();
    void updateLivingLightStatusLabel();
    void updateSecondLightStatusLabel();
    void onHostLightModeChanged(int index);
    void onLivingLightModeChanged(int index);
    void onSecondLightModeChanged(int index);
    void onHostLightButtonClicked();
    void onLivingLightButtonClicked();
    void onSecondLightButtonClicked();
    void onHostLightTimeBtnClicked();
    void onLivingLightTimeBtnClicked();
    void onSecondLightTimeBtnClicked();

public:

    QNetworkAccessManager *networkAccessManager;

    AirConditioner *hostAir;//主卧空调
    AirConditioner *livingAir;//客厅空调
    AirConditioner *secondAir;//次卧空调

    Humidifier *livingHumidity; //客厅加湿器
    Humidifier *hostHumidity; //主卧加湿器

    Light *livingLight; //客厅灯
    Light *hostLight; //主卧灯
    Light *secondLight; //次卧灯

    //计时器标识 到 myTimer类 map
    QMap<int, myTimer*> TimerIndex2MyTimerMap;
    //Device 到 计时器标识 map
    QMap<std::string, int> Device2TimerIndexMap;
    virtual void timerEvent(QTimerEvent*);


private:
    Ui::TabWidget *ui;

signals:
    void dataReceived(const QString& deviceName, double totalPower);

};

#endif // TABWIDGET_H
