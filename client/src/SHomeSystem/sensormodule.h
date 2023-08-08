#ifndef SENSORMODULE_H
#define SENSORMODULE_H

#include <QObject>

class SensorModule : public QObject
{
    Q_OBJECT
public:
    explicit SensorModule(QObject *parent = nullptr);

    void collectTemperatureData();
    void collectHumidityData();
    void collectBrightnessData();

private:
    double generateRandomDouble(double min, double max);
    double readTemperatureSensor();
    double readHumiditySensor();
    double readBrightnessSensor();
    double convertToDigital(double analogData);
    void sendDataToServer(double temperature, double humidity, double brightness);
};

#endif // SENSORMODULE_H
