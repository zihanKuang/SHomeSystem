#ifndef SENSORMODULE_H
#define SENSORMODULE_H

#include <QObject>
#include <executor.h>
#include <QTimer>

class SensorModule : public QObject
{
    Q_OBJECT
public:
    explicit SensorModule(QObject *parent = nullptr);

    void performAutoControl(); // 自动控制函数

private:
    QPair<double, double> temperatureRange;
    QPair<double, double> humidityRange;
    QPair<double, double> brightnessRange;

    double readSensorData(const QPair<double, double>& range);
    double generateRandomDouble(double min, double max);
};

#endif // SENSORMODULE_H
