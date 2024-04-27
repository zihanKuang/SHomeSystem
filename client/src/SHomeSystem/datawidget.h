#ifndef DATAWIDGET_H
#define DATAWIDGET_H

#include <QWidget>
#include <QtCharts>
#include <tabwidget.h>

QT_CHARTS_USE_NAMESPACE

class DataWidget : public QWidget
{
    Q_OBJECT

public:
    DataWidget(QWidget *parent = nullptr);

    void setPowerConsumptionBar();
    void setUsageDurationBar();

    void handleDataReceived(const QString& deviceName, double totalPower);
    void renderBarChart();

private:
    QVBoxLayout *layout;

     QChartView *chartView = nullptr;
    // 耗电量（日）柱状图
    //QChartView *powerConsumptionBarChartView;
    // 使用时长（日）柱状图
    //QChartView *usageDurationBarChartView;
    // 设备名称与耗电量的映射
    QMap<QString, double> devicePowerMap;

    int receivedDeviceCount = 0;
};

#endif // DATAWIDGET_H
