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
    QChartView *temperatureChartView;
    QChartView *humidityChartView;

    QLineSeries *temperatureSeries;
    QLineSeries *humiditySeries;

    void setupTemperatureChart();
    void setupHumidityChart();
    void updateTemperatureChart();
    void updateHumidityChart();
};

#endif // ENVIRONMENTWIDGET_H

