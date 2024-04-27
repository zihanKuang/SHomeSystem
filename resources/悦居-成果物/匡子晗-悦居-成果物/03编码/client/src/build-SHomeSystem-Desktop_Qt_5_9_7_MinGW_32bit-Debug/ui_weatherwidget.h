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
    QLabel *tTemperature;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QSpacerItem *horizontalSpacer_3;
    QLabel *tWeather;
    QSpacerItem *horizontalSpacer;
    QLabel *tHumidity;
    QSpacerItem *horizontalSpacer_2;

    void setupUi(QWidget *WeatherWidget)
    {
        if (WeatherWidget->objectName().isEmpty())
            WeatherWidget->setObjectName(QStringLiteral("WeatherWidget"));
        WeatherWidget->resize(728, 84);
        tWeatherDetail = new QLabel(WeatherWidget);
        tWeatherDetail->setObjectName(QStringLiteral("tWeatherDetail"));
        tWeatherDetail->setGeometry(QRect(270, 40, 131, 31));
        tHumidityDetail = new QLabel(WeatherWidget);
        tHumidityDetail->setObjectName(QStringLiteral("tHumidityDetail"));
        tHumidityDetail->setGeometry(QRect(470, 40, 181, 31));
        tTemperature = new QLabel(WeatherWidget);
        tTemperature->setObjectName(QStringLiteral("tTemperature"));
        tTemperature->setGeometry(QRect(70, 40, 141, 31));
        layoutWidget = new QWidget(WeatherWidget);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(70, 10, 601, 22));
        horizontalLayout = new QHBoxLayout(layoutWidget);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(layoutWidget);
        label->setObjectName(QStringLiteral("label"));

        horizontalLayout->addWidget(label);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_3);

        tWeather = new QLabel(layoutWidget);
        tWeather->setObjectName(QStringLiteral("tWeather"));

        horizontalLayout->addWidget(tWeather);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        tHumidity = new QLabel(layoutWidget);
        tHumidity->setObjectName(QStringLiteral("tHumidity"));

        horizontalLayout->addWidget(tHumidity);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);


        retranslateUi(WeatherWidget);

        QMetaObject::connectSlotsByName(WeatherWidget);
    } // setupUi

    void retranslateUi(QWidget *WeatherWidget)
    {
        WeatherWidget->setWindowTitle(QApplication::translate("WeatherWidget", "Form", Q_NULLPTR));
        tWeatherDetail->setText(QApplication::translate("WeatherWidget", "\345\210\267\346\226\260\344\270\255ing", Q_NULLPTR));
        tHumidityDetail->setText(QApplication::translate("WeatherWidget", "\345\210\267\346\226\260\344\270\255ing", Q_NULLPTR));
        tTemperature->setText(QApplication::translate("WeatherWidget", "\345\210\267\346\226\260\344\270\255ing", Q_NULLPTR));
        label->setText(QApplication::translate("WeatherWidget", "\344\273\212\346\227\245\346\270\251\345\272\246\357\274\232", Q_NULLPTR));
        tWeather->setText(QApplication::translate("WeatherWidget", "\344\273\212\346\227\245\345\244\251\346\260\224\357\274\232", Q_NULLPTR));
        tHumidity->setText(QApplication::translate("WeatherWidget", "\344\273\212\346\227\245\346\271\277\345\272\246\357\274\232", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class WeatherWidget: public Ui_WeatherWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WEATHERWIDGET_H
