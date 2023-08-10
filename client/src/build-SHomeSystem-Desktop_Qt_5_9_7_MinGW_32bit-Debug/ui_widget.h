/********************************************************************************
** Form generated from reading UI file 'widget.ui'
**
** Created by: Qt User Interface Compiler version 5.9.7
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGET_H
#define UI_WIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QWidget>
#include "tabwidget.h"
#include "weatherwidget.h"

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    TabWidget *tabwidget;
    WeatherWidget *weatherwidget;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName(QStringLiteral("Widget"));
        Widget->resize(818, 597);
        tabwidget = new TabWidget(Widget);
        tabwidget->setObjectName(QStringLiteral("tabwidget"));
        tabwidget->setGeometry(QRect(10, 100, 741, 481));
        weatherwidget = new WeatherWidget(Widget);
        weatherwidget->setObjectName(QStringLiteral("weatherwidget"));
        weatherwidget->setGeometry(QRect(10, 10, 711, 81));

        retranslateUi(Widget);

        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QApplication::translate("Widget", "Widget", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
