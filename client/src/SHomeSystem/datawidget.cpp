#include "datawidget.h"

DataWidget::DataWidget(QWidget *parent)
    : QWidget(parent)
{
    layout = new QVBoxLayout(this);
    //powerConsumptionBarChartView = new QChartView();
    //usageDurationBarChartView = new QChartView();

    //layout->addWidget(powerConsumptionBarChartView);
    //layout->addWidget(usageDurationBarChartView);
}

void DataWidget::handleDataReceived(const QString& deviceName, double totalPower)
{
    // 存储耗电量数据到映射中
    devicePowerMap[deviceName] = totalPower;
    receivedDeviceCount++;
    qDebug() << "Received data for device:" << deviceName << "Total power:" << totalPower;

    // 打印出 devicePowerMap 的内容
       qDebug() << "Device power map:" << devicePowerMap;

        if (receivedDeviceCount == 8) {
            renderBarChart(); // 在所有设备数据接收后绘制柱状图
            receivedDeviceCount=0;
        }
}

void DataWidget::renderBarChart()
{
    QChart *chart = new QChart;
    QBarSeries *series = new QBarSeries;

    QStringList deviceNames;  // 存储设备名称的顺序

    // 创建一个 QBarSet 对象
    QBarSet *set = new QBarSet("Total Power");

    // 遍历 devicePowerMap，为每个设备添加柱状图数据
    for (const QString& deviceName : devicePowerMap.keys()) {
        //QBarSet *set = new QBarSet(deviceName);

        // 添加实际的数据
        *set << devicePowerMap[deviceName];

        series->append(set);

        // 将设备名称按顺序存储
        deviceNames << deviceName;
    }

    chart->addSeries(series);

    // 创建柱状图的 X 轴和 Y 轴
    QBarCategoryAxis *axisX = new QBarCategoryAxis;
    axisX->setMin(nullptr);  // 设置最小刻度值
    axisX->setMax(QString::number(deviceNames.size() - 1)); // 设置最大刻度值
    qDebug() << "Number of device names:" << deviceNames.size(); // 打印出设备名称的数量
    axisX->setLabelsAngle(-45);
    axisX->setLabelsFont(QFont("Arial", 6));  // 设置字号为8
    axisX->append(deviceNames);  // 设置刻度标签为设备名称
    axisX->setLabelsVisible(true); // 设置刻度值可见
    chart->addAxis(axisX, Qt::AlignBottom);
    series->attachAxis(axisX);

    QValueAxis *axisY = new QValueAxis;
    chart->addAxis(axisY, Qt::AlignLeft);
    series->attachAxis(axisY);

    // 设置柱状图的宽度
    double barWidth = 1; // 调整这个值来改变柱子的宽度
    series->setBarWidth(barWidth);

    // 在柱状图顶部显示数据标签
    QValueAxis *axisYTop = new QValueAxis;
    axisYTop->setLabelsVisible(true);
    chart->addAxis(axisYTop, Qt::AlignTop);
    series->attachAxis(axisYTop);

    // 如果已经存在柱状图视图，先删除
    if (chartView) {
        layout->removeWidget(chartView);
        delete chartView;
    }

    // 创建新的柱状图视图并设置到界面
    chartView = new QChartView(chart);
    chartView->setRenderHint(QPainter::Antialiasing);
    layout->addWidget(chartView);
}

