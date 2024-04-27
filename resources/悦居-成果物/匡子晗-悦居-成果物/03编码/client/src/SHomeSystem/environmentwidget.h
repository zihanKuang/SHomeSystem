#ifndef ENVIRONMENTWIDGET_H
#define ENVIRONMENTWIDGET_H

#include <QWidget>
#include <QtCharts>

QT_CHARTS_USE_NAMESPACE

class EnvironmentWidget : public QWidget
{
    Q_OBJECT

public:
    EnvironmentWidget(QWidget *parent = nullptr);

private:
    //室内温度变化（日）折线图
    QLineSeries *temperatureSeries;
    //室内湿度变化（日）折线图
    QLineSeries *humiditySeries;

    void setTemperatureSeries();
    void setHumiditySeries();
};

#endif // ENVIRONMENTWIDGET_H

