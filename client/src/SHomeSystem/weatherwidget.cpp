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
    //定时刷新功能，暂时放着，不然跑着会出错
    //(timer, &QTimer::timeout, this, &WeatherWidget::fetchWeather);
    timer->start(10000); // 10 seconds
}

WeatherWidget::~WeatherWidget()
{
    delete ui;
}

// 发送获取天气数据请求
void WeatherWidget::fetchWeather() {
    QString url = "http://127.0.0.1:8080/weather"; // 替换为你的服务器 IP 和端口

    QNetworkRequest request(url);
    QNetworkReply* reply = networkManager->get(request);

    connect(reply, &QNetworkReply::finished, this, [=]() {
        if (reply->error() == QNetworkReply::NoError) {
            QString data = reply->readAll();
            // 解析JSON数据并更新UI，这部分可以保持不变
        } else {
            qDebug() << "Network error:" << reply->errorString();
        }

        reply->deleteLater();
    });
}

void WeatherWidget::handleWeatherResponse(QNetworkReply* reply)
{
    if (reply->error() == QNetworkReply::NoError) {
        QString data = reply->readAll();
        QJsonDocument document = QJsonDocument::fromJson(data.toUtf8());
        if (!document.isNull()) {
            QJsonObject object = document.object();
            int status = object["status"].toInt();
            if (status == 1) {
                QJsonObject liveData = object["lives"].toObject();
                QString weather = liveData["weather"].toString();
                int temperature = liveData["temperature"].toInt();
                int humidity = liveData["humidity"].toInt();

                // 更新UI
                ui->tWeatherDetail->setText(weather);
                ui->tTemperature->setText(QString("%1°C").arg(temperature));
                ui->tHumidityDetail->setText(QString("Humidity: %1%").arg(humidity));
            } else {
                qDebug() << "API request failed: " << object["info"].toString();
            }
        }
    } else {
        qDebug() << "Network error:" << reply->errorString();
    }
}
