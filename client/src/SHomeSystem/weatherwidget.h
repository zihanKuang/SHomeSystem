// weatherwidget.h
#ifndef WEATHERWIDGET_H
#define WEATHERWIDGET_H

#include <QWidget>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QTimer>

namespace Ui {
class WeatherWidget;
}

class WeatherWidget : public QWidget
{
    Q_OBJECT

public:
    explicit WeatherWidget(QWidget *parent = nullptr);
    ~WeatherWidget();

private slots:
    void fetchWeather();
    void handleWeatherResponse(QNetworkReply* reply);

private:
    Ui::WeatherWidget *ui;
    QNetworkAccessManager *networkManager;
    QTimer *timer;
};

#endif // WEATHERWIDGET_H
