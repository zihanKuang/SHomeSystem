// weatherwidget.cpp
#include "weatherwidget.h"
#include "ui_weatherwidget.h"
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonValue>

WeatherWidget::WeatherWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::WeatherWidget),
    networkManager(new QNetworkAccessManager(this)),
    timer(new QTimer(this))
{
    ui->setupUi(this);

    //定时刷新功能
    connect(timer, &QTimer::timeout, this, &WeatherWidget::fetchWeather);
    timer->start(5000); // 5 seconds
}

WeatherWidget::~WeatherWidget()
{
    delete ui;
}

// 发送获取天气数据请求
void WeatherWidget::fetchWeather() {
    QString url = "http://127.0.0.1:8080/weather";

    QNetworkRequest request(url);
    QNetworkReply* reply = networkManager->get(request);

    connect(reply, &QNetworkReply::finished, this, [=]() {
        handleWeatherResponse(reply);
        reply->deleteLater();
    });
}

void WeatherWidget::handleWeatherResponse(QNetworkReply* reply) {
    if (reply->error() == QNetworkReply::NoError) {
        QString data = reply->readAll();
        qDebug() << "Received data:" << data;

        QJsonDocument document = QJsonDocument::fromJson(data.toUtf8());

        if (!document.isNull()) {
            QJsonObject object = document.object();
            QString weatherString = object["weather"].toString();
            qDebug() << "Weather string:" << weatherString;
            QJsonDocument weatherDocument = QJsonDocument::fromJson(weatherString.toUtf8());

            if (!weatherDocument.isNull()) {
                QJsonObject weatherObject = weatherDocument.object();
                QJsonArray livesArray = weatherObject["lives"].toArray();

                if (!livesArray.isEmpty()) {
                    QJsonObject liveData = livesArray.at(0).toObject();

                    QString weather = liveData["weather"].toString();
                    QString temperatureStr = liveData["temperature_float"].toString();
                    QString humidityStr = liveData["humidity_float"].toString();
                    double temperature = temperatureStr.toDouble();
                    double humidity = humidityStr.toDouble();


                    qDebug() << "Weather:" << weather;
                    qDebug() << "Temperature:" << temperature;
                    qDebug() << "Humidity:" << humidity;

                    // 更新UI
                    ui->tWeatherDetail->setText(weather);
                    ui->tTemperature->setText(QString("%1°C").arg(temperature));
                    ui->tHumidityDetail->setText(QString("Humidity: %1%").arg(humidity));
                } else {
                    qDebug() << "No 'lives' data found.";
                }
            } else {
                qDebug() << "Failed to parse internal JSON data.";
            }
        } else {
            qDebug() << "Failed to parse JSON data.";
        }
    } else {
        qDebug() << "Network error:" << reply->errorString();
    }
}






