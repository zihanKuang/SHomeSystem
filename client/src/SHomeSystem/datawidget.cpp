#include "datawidget.h"

DataWidget::DataWidget(QWidget *parent)
    : QWidget(parent)
{
    layout = new QVBoxLayout(this);

    powerConsumptionBarChartView = new QChartView();
    usageDurationBarChartView = new QChartView();

    layout->addWidget(powerConsumptionBarChartView);
    layout->addWidget(usageDurationBarChartView);

    // 存疑
    //
    // 连接信号 dataReceived 到槽 handleDataReceived
    TabWidget *tabWidget = qobject_cast<TabWidget*>(parentWidget()); // 获取父 TabWidget 的实例
    if (tabWidget) {
        connect(tabWidget, &TabWidget::dataReceived, this, &DataWidget::handleDataReceived);
    }
}

void DataWidget::handleDataReceived(const QString& deviceName, double totalPower)
{
    // 存储耗电量数据到映射中
    devicePowerMap[deviceName] = totalPower;

    // 在这里进行数据的处理和渲染
    renderBarChart();
}

void DataWidget::renderBarChart()
{
    QChart *chart = new QChart;
    QBarSeries *series = new QBarSeries;

    // 遍历 devicePowerMap，为每个设备添加柱状图数据
    for (const QString& deviceName : devicePowerMap.keys()) {
        QBarSet *set = new QBarSet(deviceName);
        *set << devicePowerMap[deviceName];
        series->append(set);
    }

    chart->addSeries(series);

    // 创建柱状图的 X 轴和 Y 轴
    QBarCategoryAxis *axisX = new QBarCategoryAxis;
    axisX->append(devicePowerMap.keys());
    chart->addAxis(axisX, Qt::AlignBottom);
    series->attachAxis(axisX);

    QValueAxis *axisY = new QValueAxis;
    chart->addAxis(axisY, Qt::AlignLeft);
    series->attachAxis(axisY);

    // 创建柱状图视图并设置到界面
    QChartView *chartView = new QChartView(chart);
    chartView->setRenderHint(QPainter::Antialiasing);

    layout->addWidget(chartView);
}

