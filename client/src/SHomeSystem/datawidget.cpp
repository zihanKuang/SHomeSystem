#include "datawidget.h"

DataWidget::DataWidget(QWidget *parent)
    : QWidget(parent)
{
    chartView = new QChartView(this);

    QChart *chart = new QChart();
    QBarSeries *series = new QBarSeries();

    // Add bar sets and data to the series
    QBarSet *barSet = new QBarSet("Category 1");
    *barSet << 1 << 2 << 3;
    series->append(barSet);

    QBarSet *barSet2 = new QBarSet("Category 2");
    *barSet2 << 4 << 5 << 6;
    series->append(barSet2);

    chart->addSeries(series);

    QValueAxis *axisX = new QValueAxis();
    chart->addAxis(axisX, Qt::AlignBottom);
    series->attachAxis(axisX);

    QValueAxis *axisY = new QValueAxis();
    chart->addAxis(axisY, Qt::AlignLeft);
    series->attachAxis(axisY);

    chartView->setChart(chart);
    chartView->setRenderHint(QPainter::Antialiasing);

    QVBoxLayout *layout = new QVBoxLayout(this);
    layout->addWidget(chartView);
    setLayout(layout);
}

