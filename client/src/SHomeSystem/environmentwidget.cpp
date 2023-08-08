#include "environmentwidget.h"

EnvironmentWidget::EnvironmentWidget(QWidget *parent)
    : QWidget(parent)
{
    QVBoxLayout *layout = new QVBoxLayout(this);

    temperatureChartView = new QChartView(this);
    humidityChartView = new QChartView(this);

    layout->addWidget(temperatureChartView);
    layout->addWidget(humidityChartView);

    setupTemperatureChart();
    setupHumidityChart();

    setLayout(layout);
}

void EnvironmentWidget::setupTemperatureChart()
{
    temperatureChartView->setRenderHint(QPainter::Antialiasing);
    temperatureSeries = new QLineSeries();
    QChart *temperatureChart = new QChart();
    temperatureChart->addSeries(temperatureSeries);
    temperatureChart->createDefaultAxes();
    temperatureChart->setTitle("Temperature Trend");
    temperatureChartView->setChart(temperatureChart);
}

void EnvironmentWidget::setupHumidityChart()
{
    humidityChartView->setRenderHint(QPainter::Antialiasing);
    humiditySeries = new QLineSeries();
    QChart *humidityChart = new QChart();
    humidityChart->addSeries(humiditySeries);
    humidityChart->createDefaultAxes();
    humidityChart->setTitle("Humidity Trend");
    humidityChartView->setChart(humidityChart);
}

void EnvironmentWidget::updateTemperatureChart()
{
    // Update temperature data
    // ...
}

void EnvironmentWidget::updateHumidityChart()
{
    // Update humidity data
    // ...
}
