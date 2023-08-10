#ifndef STACKEDWIDGET_H
#define STACKEDWIDGET_H

#include <QWidget>
#include <QChart>
#include <device.h>

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
    // 空调温度变设置槽函数
    void onHostAirEditEditingFinished();
    void onLivingAirEditEditingFinished();
    void onSecondAirEditEditingFinished();

    // 空调定时按钮槽函数
    void onHostAirTimerButtonClicked();
    void onLivingAirTimerButtonClicked();
    void onSecondAirTimerButtonClicked();

    // 空调开关按钮槽函数
    void onHostAirPowerButtonClicked();
    void onLivingAirPowerButtonClicked();
    void onSecondAirPowerButtonClicked();

    // 空调模式combobox槽函数
    void onHostAirModeChanged(int index);
    void onLivingAirModeChanged(int index);
    void onSecondAirModeChanged(int index);

public:
    AirConditioner *hostAir;//主卧空调
    AirConditioner *livingAir;//客厅空调
    AirConditioner *secondAir;//次卧空调

    Humidifier *livingHumidity; //客厅加湿器
    Humidifier *hostHumidity; //主卧加湿器

    Light *livingLight; //客厅灯
    Light *hostLight; //主卧灯
    Light *secondLight; //次卧灯

private:
    Ui::TabWidget *ui;
};

#endif // STACKEDWIDGET_H
