#ifndef DATAWIDGET_H
#define DATAWIDGET_H

#include <QWidget>
#include <QtCharts>

QT_CHARTS_USE_NAMESPACE

class DataWidget : public QWidget
{
    Q_OBJECT

public:
    DataWidget(QWidget *parent = nullptr);

private:
    QChartView *chartView;
};

#endif // DATAWIDGET_H
