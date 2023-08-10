/********************************************************************************
** Form generated from reading UI file 'weatherwidget.ui'
**
** Created by: Qt User Interface Compiler version 5.9.7
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WEATHERWIDGET_H
#define UI_WEATHERWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_WeatherWidget
{
public:
    QLabel *tWeatherDetail;
    QLabel *tHumidityDetail;
    QLabel *rWeatherDetail;
    QLabel *tTemperature;
    QWidget *widget;
    QHBoxLayout *horizontalLayout;
    QLabel *tWeather;
    QSpacerItem *horizontalSpacer;
    QLabel *tHumidity;
    QSpacerItem *horizontalSpacer_2;
    QLabel *rWeather;

    void setupUi(QWidget *WeatherWidget)
    {
        if (WeatherWidget->objectName().isEmpty())
            WeatherWidget->setObjectName(QStringLiteral("WeatherWidget"));
        WeatherWidget->resize(728, 84);
        tWeatherDetail = new QLabel(WeatherWidget);
        tWeatherDetail->setObjectName(QStringLiteral("tWeatherDetail"));
        tWeatherDetail->setGeometry(QRect(190, 40, 131, 31));
        tHumidityDetail = new QLabel(WeatherWidget);
        tHumidityDetail->setObjectName(QStringLiteral("tHumidityDetail"));
        tHumidityDetail->setGeometry(QRect(340, 40, 181, 31));
        rWeatherDetail = new QLabel(WeatherWidget);
        rWeatherDetail->setObjectName(QStringLiteral("rWeatherDetail"));
        rWeatherDetail->setGeometry(QRect(560, 40, 161, 31));
        tTemperature = new QLabel(WeatherWidget);
        tTemperature->setObjectName(QStringLiteral("tTemperature"));
        tTemperature->setGeometry(QRect(40, 40, 141, 31));
        widget = new QWidget(WeatherWidget);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(70, 10, 601, 21));
        horizontalLayout = new QHBoxLayout(widget);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        tWeather = new QLabel(widget);
        tWeather->setObjectName(QStringLiteral("tWeather"));

        horizontalLayout->addWidget(tWeather);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        tHumidity = new QLabel(widget);
        tHumidity->setObjectName(QStringLiteral("tHumidity"));

        horizontalLayout->addWidget(tHumidity);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);

        rWeather = new QLabel(widget);
        rWeather->setObjectName(QStringLiteral("rWeather"));

        horizontalLayout->addWidget(rWeather);


        retranslateUi(WeatherWidget);

        QMetaObject::connectSlotsByName(WeatherWidget);
    } // setupUi

    void retranslateUi(QWidget *WeatherWidget)
    {
        WeatherWidget->setWindowTitle(QApplication::translate("WeatherWidget", "Form", Q_NULLPTR));
        tWeatherDetail->setText(QApplication::translate("WeatherWidget", "TextLabel", Q_NULLPTR));
        tHumidityDetail->setText(QApplication::translate("WeatherWidget", "TextLabel", Q_NULLPTR));
        rWeatherDetail->setText(QApplication::translate("WeatherWidget", "TextLabel", Q_NULLPTR));
        tTemperature->setText(QApplication::translate("WeatherWidget", "TextLabel", Q_NULLPTR));
        tWeather->setText(QApplication::translate("WeatherWidget", "\344\273\212\346\227\245\345\244\251\346\260\224\357\274\232", Q_NULLPTR));
        tHumidity->setText(QApplication::translate("WeatherWidget", "\344\273\212\346\227\245\346\271\277\345\272\246\357\274\232", Q_NULLPTR));
        rWeather->setText(QApplication::translate("WeatherWidget", "\345\275\223\345\211\215\345\256\244\345\206\205\346\270\251\345\272\246\357\274\232", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class WeatherWidget: public Ui_WeatherWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WEATHERWIDGET_H
