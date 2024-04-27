#include "environmentwidget.h"

EnvironmentWidget::EnvironmentWidget(QWidget *parent)
    : QWidget(parent)
{
    QHBoxLayout *layout = new QHBoxLayout(this);

    temperatureSeries = new QLineSeries(this);
    humiditySeries = new QLineSeries(this);

    setTemperatureSeries();
    setHumiditySeries();

    QChart *chart = new QChart();
    chart->addSeries(temperatureSeries);
    chart->addSeries(humiditySeries);

    QValueAxis *axisX = new QValueAxis();
    axisX->setTitleText("时间");
    axisX->setTickCount(24); // Assuming hourly data points
    axisX->setLabelFormat("%d:00");
    chart->addAxis(axisX, Qt::AlignBottom);

    QValueAxis *axisY = new QValueAxis();
    axisY->setTitleText("数值");
    chart->addAxis(axisY, Qt::AlignLeft);

    temperatureSeries->attachAxis(axisX);
    temperatureSeries->attachAxis(axisY);
    humiditySeries->attachAxis(axisX);
    humiditySeries->attachAxis(axisY);

    QChartView *chartView = new QChartView(chart);
    layout->addWidget(chartView);
}

void EnvironmentWidget::setTemperatureSeries()
{
    // Assuming you have temperature data in some format
    // For example, you could add data points like this:
    temperatureSeries->append(0, 20);
    temperatureSeries->append(1, 22);
    temperatureSeries->append(2, 25);
    // ... and so on
}

void EnvironmentWidget::setHumiditySeries()
{
    // Assuming you have humidity data in some format
    // For example, you could add data points like this:
    humiditySeries->append(0, 50);
    humiditySeries->append(1, 55);
    humiditySeries->append(2, 60);
    // ... and so on
}
