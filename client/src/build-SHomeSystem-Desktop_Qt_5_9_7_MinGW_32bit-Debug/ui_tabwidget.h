/********************************************************************************
** Form generated from reading UI file 'tabwidget.ui'
**
** Created by: Qt User Interface Compiler version 5.9.7
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TABWIDGET_H
#define UI_TABWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTimeEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "datawidget.h"
#include "environmentwidget.h"

QT_BEGIN_NAMESPACE

class Ui_TabWidget
{
public:
    QTabWidget *tabWidget;
    QWidget *FurnitureOverviewPage;
    QWidget *layoutWidget;
    QVBoxLayout *airTitle;
    QLabel *label;
    QLabel *label_15;
    QLabel *label_20;
    QLabel *label_16;
    QLabel *label_17;
    QLabel *label_18;
    QWidget *layoutWidget1;
    QHBoxLayout *airName;
    QLabel *livingAir;
    QSpacerItem *horizontalSpacer_7;
    QLabel *hostAir;
    QSpacerItem *horizontalSpacer_8;
    QLabel *secondAir;
    QWidget *layoutWidget2;
    QHBoxLayout *airLcd;
    QLineEdit *livingAirEdit;
    QSpacerItem *horizontalSpacer;
    QLineEdit *hostAirEdit;
    QSpacerItem *horizontalSpacer_2;
    QLineEdit *secondAirEdit;
    QWidget *layoutWidget3;
    QHBoxLayout *airMode;
    QComboBox *livingAirMode;
    QSpacerItem *horizontalSpacer_3;
    QComboBox *hostAirMode;
    QSpacerItem *horizontalSpacer_4;
    QComboBox *secondAirMode;
    QWidget *layoutWidget4;
    QHBoxLayout *airAuto;
    QTimeEdit *livingAirTime;
    QSpacerItem *horizontalSpacer_5;
    QTimeEdit *hostAirTime;
    QSpacerItem *horizontalSpacer_6;
    QTimeEdit *secondAirTime;
    QWidget *layoutWidget5;
    QHBoxLayout *airBtn;
    QPushButton *livingAirBtn;
    QSpacerItem *horizontalSpacer_9;
    QPushButton *hostAirBtn;
    QSpacerItem *horizontalSpacer_10;
    QPushButton *secondAirBtn;
    QWidget *layoutWidget_2;
    QHBoxLayout *lightAuto;
    QTimeEdit *livingLightAuto;
    QSpacerItem *horizontalSpacer_15;
    QTimeEdit *hostLightAuto;
    QSpacerItem *horizontalSpacer_16;
    QTimeEdit *secondLightAuto;
    QWidget *layoutWidget6;
    QVBoxLayout *lightTitle;
    QLabel *label_5;
    QLabel *label_21;
    QLabel *label_19;
    QLabel *label_22;
    QWidget *layoutWidget7;
    QHBoxLayout *lightMode;
    QComboBox *livingLightMode;
    QSpacerItem *horizontalSpacer_13;
    QComboBox *hostLightMode;
    QSpacerItem *horizontalSpacer_14;
    QComboBox *secondLightMode;
    QWidget *layoutWidget8;
    QHBoxLayout *lightName;
    QLabel *label_6;
    QSpacerItem *horizontalSpacer_11;
    QLabel *label_7;
    QSpacerItem *horizontalSpacer_12;
    QLabel *label_8;
    QWidget *layoutWidget9;
    QVBoxLayout *humidityTitle;
    QLabel *label_9;
    QLabel *label_10;
    QLabel *label_11;
    QWidget *layoutWidget10;
    QHBoxLayout *livingHumidity;
    QSlider *livingHumiditySlider;
    QSpinBox *spinBox;
    QPushButton *livingHumidityBtn;
    QWidget *layoutWidget11;
    QHBoxLayout *hostHumidity;
    QSlider *hostHumiditySlider;
    QSpinBox *spinBox_2;
    QPushButton *hostHumidityBtn;
    QWidget *EnvirmentPage;
    EnvironmentWidget *widget_2;
    QWidget *DataAnalyticsPage;
    DataWidget *widget;

    void setupUi(QWidget *TabWidget)
    {
        if (TabWidget->objectName().isEmpty())
            TabWidget->setObjectName(QStringLiteral("TabWidget"));
        TabWidget->resize(733, 595);
        tabWidget = new QTabWidget(TabWidget);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        tabWidget->setGeometry(QRect(0, 0, 731, 591));
        tabWidget->setTabPosition(QTabWidget::West);
        FurnitureOverviewPage = new QWidget();
        FurnitureOverviewPage->setObjectName(QStringLiteral("FurnitureOverviewPage"));
        layoutWidget = new QWidget(FurnitureOverviewPage);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(20, 10, 65, 171));
        airTitle = new QVBoxLayout(layoutWidget);
        airTitle->setObjectName(QStringLiteral("airTitle"));
        airTitle->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(layoutWidget);
        label->setObjectName(QStringLiteral("label"));

        airTitle->addWidget(label);

        label_15 = new QLabel(layoutWidget);
        label_15->setObjectName(QStringLiteral("label_15"));

        airTitle->addWidget(label_15);

        label_20 = new QLabel(layoutWidget);
        label_20->setObjectName(QStringLiteral("label_20"));

        airTitle->addWidget(label_20);

        label_16 = new QLabel(layoutWidget);
        label_16->setObjectName(QStringLiteral("label_16"));

        airTitle->addWidget(label_16);

        label_17 = new QLabel(layoutWidget);
        label_17->setObjectName(QStringLiteral("label_17"));

        airTitle->addWidget(label_17);

        label_18 = new QLabel(layoutWidget);
        label_18->setObjectName(QStringLiteral("label_18"));

        airTitle->addWidget(label_18);

        layoutWidget1 = new QWidget(FurnitureOverviewPage);
        layoutWidget1->setObjectName(QStringLiteral("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(100, 60, 591, 22));
        airName = new QHBoxLayout(layoutWidget1);
        airName->setObjectName(QStringLiteral("airName"));
        airName->setContentsMargins(0, 0, 0, 0);
        livingAir = new QLabel(layoutWidget1);
        livingAir->setObjectName(QStringLiteral("livingAir"));

        airName->addWidget(livingAir);

        horizontalSpacer_7 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        airName->addItem(horizontalSpacer_7);

        hostAir = new QLabel(layoutWidget1);
        hostAir->setObjectName(QStringLiteral("hostAir"));

        airName->addWidget(hostAir);

        horizontalSpacer_8 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        airName->addItem(horizontalSpacer_8);

        secondAir = new QLabel(layoutWidget1);
        secondAir->setObjectName(QStringLiteral("secondAir"));

        airName->addWidget(secondAir);

        layoutWidget2 = new QWidget(FurnitureOverviewPage);
        layoutWidget2->setObjectName(QStringLiteral("layoutWidget2"));
        layoutWidget2->setGeometry(QRect(90, 100, 611, 31));
        airLcd = new QHBoxLayout(layoutWidget2);
        airLcd->setObjectName(QStringLiteral("airLcd"));
        airLcd->setContentsMargins(0, 0, 0, 0);
        livingAirEdit = new QLineEdit(layoutWidget2);
        livingAirEdit->setObjectName(QStringLiteral("livingAirEdit"));

        airLcd->addWidget(livingAirEdit);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        airLcd->addItem(horizontalSpacer);

        hostAirEdit = new QLineEdit(layoutWidget2);
        hostAirEdit->setObjectName(QStringLiteral("hostAirEdit"));

        airLcd->addWidget(hostAirEdit);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        airLcd->addItem(horizontalSpacer_2);

        secondAirEdit = new QLineEdit(layoutWidget2);
        secondAirEdit->setObjectName(QStringLiteral("secondAirEdit"));

        airLcd->addWidget(secondAirEdit);

        layoutWidget3 = new QWidget(FurnitureOverviewPage);
        layoutWidget3->setObjectName(QStringLiteral("layoutWidget3"));
        layoutWidget3->setGeometry(QRect(100, 130, 591, 24));
        airMode = new QHBoxLayout(layoutWidget3);
        airMode->setObjectName(QStringLiteral("airMode"));
        airMode->setContentsMargins(0, 0, 0, 0);
        livingAirMode = new QComboBox(layoutWidget3);
        livingAirMode->setObjectName(QStringLiteral("livingAirMode"));

        airMode->addWidget(livingAirMode);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        airMode->addItem(horizontalSpacer_3);

        hostAirMode = new QComboBox(layoutWidget3);
        hostAirMode->setObjectName(QStringLiteral("hostAirMode"));

        airMode->addWidget(hostAirMode);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        airMode->addItem(horizontalSpacer_4);

        secondAirMode = new QComboBox(layoutWidget3);
        secondAirMode->setObjectName(QStringLiteral("secondAirMode"));

        airMode->addWidget(secondAirMode);

        layoutWidget4 = new QWidget(FurnitureOverviewPage);
        layoutWidget4->setObjectName(QStringLiteral("layoutWidget4"));
        layoutWidget4->setGeometry(QRect(100, 150, 591, 31));
        airAuto = new QHBoxLayout(layoutWidget4);
        airAuto->setObjectName(QStringLiteral("airAuto"));
        airAuto->setContentsMargins(0, 0, 0, 0);
        livingAirTime = new QTimeEdit(layoutWidget4);
        livingAirTime->setObjectName(QStringLiteral("livingAirTime"));

        airAuto->addWidget(livingAirTime);

        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        airAuto->addItem(horizontalSpacer_5);

        hostAirTime = new QTimeEdit(layoutWidget4);
        hostAirTime->setObjectName(QStringLiteral("hostAirTime"));

        airAuto->addWidget(hostAirTime);

        horizontalSpacer_6 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        airAuto->addItem(horizontalSpacer_6);

        secondAirTime = new QTimeEdit(layoutWidget4);
        secondAirTime->setObjectName(QStringLiteral("secondAirTime"));

        airAuto->addWidget(secondAirTime);

        layoutWidget5 = new QWidget(FurnitureOverviewPage);
        layoutWidget5->setObjectName(QStringLiteral("layoutWidget5"));
        layoutWidget5->setGeometry(QRect(100, 80, 591, 22));
        airBtn = new QHBoxLayout(layoutWidget5);
        airBtn->setObjectName(QStringLiteral("airBtn"));
        airBtn->setContentsMargins(0, 0, 0, 0);
        livingAirBtn = new QPushButton(layoutWidget5);
        livingAirBtn->setObjectName(QStringLiteral("livingAirBtn"));

        airBtn->addWidget(livingAirBtn);

        horizontalSpacer_9 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        airBtn->addItem(horizontalSpacer_9);

        hostAirBtn = new QPushButton(layoutWidget5);
        hostAirBtn->setObjectName(QStringLiteral("hostAirBtn"));

        airBtn->addWidget(hostAirBtn);

        horizontalSpacer_10 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        airBtn->addItem(horizontalSpacer_10);

        secondAirBtn = new QPushButton(layoutWidget5);
        secondAirBtn->setObjectName(QStringLiteral("secondAirBtn"));

        airBtn->addWidget(secondAirBtn);

        layoutWidget_2 = new QWidget(FurnitureOverviewPage);
        layoutWidget_2->setObjectName(QStringLiteral("layoutWidget_2"));
        layoutWidget_2->setGeometry(QRect(100, 280, 591, 31));
        lightAuto = new QHBoxLayout(layoutWidget_2);
        lightAuto->setObjectName(QStringLiteral("lightAuto"));
        lightAuto->setContentsMargins(0, 0, 0, 0);
        livingLightAuto = new QTimeEdit(layoutWidget_2);
        livingLightAuto->setObjectName(QStringLiteral("livingLightAuto"));

        lightAuto->addWidget(livingLightAuto);

        horizontalSpacer_15 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        lightAuto->addItem(horizontalSpacer_15);

        hostLightAuto = new QTimeEdit(layoutWidget_2);
        hostLightAuto->setObjectName(QStringLiteral("hostLightAuto"));

        lightAuto->addWidget(hostLightAuto);

        horizontalSpacer_16 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        lightAuto->addItem(horizontalSpacer_16);

        secondLightAuto = new QTimeEdit(layoutWidget_2);
        secondLightAuto->setObjectName(QStringLiteral("secondLightAuto"));

        lightAuto->addWidget(secondLightAuto);

        layoutWidget6 = new QWidget(FurnitureOverviewPage);
        layoutWidget6->setObjectName(QStringLiteral("layoutWidget6"));
        layoutWidget6->setGeometry(QRect(20, 190, 56, 121));
        lightTitle = new QVBoxLayout(layoutWidget6);
        lightTitle->setObjectName(QStringLiteral("lightTitle"));
        lightTitle->setContentsMargins(0, 0, 0, 0);
        label_5 = new QLabel(layoutWidget6);
        label_5->setObjectName(QStringLiteral("label_5"));

        lightTitle->addWidget(label_5);

        label_21 = new QLabel(layoutWidget6);
        label_21->setObjectName(QStringLiteral("label_21"));

        lightTitle->addWidget(label_21);

        label_19 = new QLabel(layoutWidget6);
        label_19->setObjectName(QStringLiteral("label_19"));

        lightTitle->addWidget(label_19);

        label_22 = new QLabel(layoutWidget6);
        label_22->setObjectName(QStringLiteral("label_22"));

        lightTitle->addWidget(label_22);

        layoutWidget7 = new QWidget(FurnitureOverviewPage);
        layoutWidget7->setObjectName(QStringLiteral("layoutWidget7"));
        layoutWidget7->setGeometry(QRect(100, 250, 591, 24));
        lightMode = new QHBoxLayout(layoutWidget7);
        lightMode->setObjectName(QStringLiteral("lightMode"));
        lightMode->setContentsMargins(0, 0, 0, 0);
        livingLightMode = new QComboBox(layoutWidget7);
        livingLightMode->setObjectName(QStringLiteral("livingLightMode"));

        lightMode->addWidget(livingLightMode);

        horizontalSpacer_13 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        lightMode->addItem(horizontalSpacer_13);

        hostLightMode = new QComboBox(layoutWidget7);
        hostLightMode->setObjectName(QStringLiteral("hostLightMode"));

        lightMode->addWidget(hostLightMode);

        horizontalSpacer_14 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        lightMode->addItem(horizontalSpacer_14);

        secondLightMode = new QComboBox(layoutWidget7);
        secondLightMode->setObjectName(QStringLiteral("secondLightMode"));

        lightMode->addWidget(secondLightMode);

        layoutWidget8 = new QWidget(FurnitureOverviewPage);
        layoutWidget8->setObjectName(QStringLiteral("layoutWidget8"));
        layoutWidget8->setGeometry(QRect(100, 220, 591, 22));
        lightName = new QHBoxLayout(layoutWidget8);
        lightName->setObjectName(QStringLiteral("lightName"));
        lightName->setContentsMargins(0, 0, 0, 0);
        label_6 = new QLabel(layoutWidget8);
        label_6->setObjectName(QStringLiteral("label_6"));

        lightName->addWidget(label_6);

        horizontalSpacer_11 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        lightName->addItem(horizontalSpacer_11);

        label_7 = new QLabel(layoutWidget8);
        label_7->setObjectName(QStringLiteral("label_7"));

        lightName->addWidget(label_7);

        horizontalSpacer_12 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        lightName->addItem(horizontalSpacer_12);

        label_8 = new QLabel(layoutWidget8);
        label_8->setObjectName(QStringLiteral("label_8"));

        lightName->addWidget(label_8);

        layoutWidget9 = new QWidget(FurnitureOverviewPage);
        layoutWidget9->setObjectName(QStringLiteral("layoutWidget9"));
        layoutWidget9->setGeometry(QRect(20, 340, 61, 131));
        humidityTitle = new QVBoxLayout(layoutWidget9);
        humidityTitle->setObjectName(QStringLiteral("humidityTitle"));
        humidityTitle->setContentsMargins(0, 0, 0, 0);
        label_9 = new QLabel(layoutWidget9);
        label_9->setObjectName(QStringLiteral("label_9"));

        humidityTitle->addWidget(label_9);

        label_10 = new QLabel(layoutWidget9);
        label_10->setObjectName(QStringLiteral("label_10"));

        humidityTitle->addWidget(label_10);

        label_11 = new QLabel(layoutWidget9);
        label_11->setObjectName(QStringLiteral("label_11"));

        humidityTitle->addWidget(label_11);

        layoutWidget10 = new QWidget(FurnitureOverviewPage);
        layoutWidget10->setObjectName(QStringLiteral("layoutWidget10"));
        layoutWidget10->setGeometry(QRect(100, 400, 361, 25));
        livingHumidity = new QHBoxLayout(layoutWidget10);
        livingHumidity->setObjectName(QStringLiteral("livingHumidity"));
        livingHumidity->setContentsMargins(0, 0, 0, 0);
        livingHumiditySlider = new QSlider(layoutWidget10);
        livingHumiditySlider->setObjectName(QStringLiteral("livingHumiditySlider"));
        livingHumiditySlider->setOrientation(Qt::Horizontal);

        livingHumidity->addWidget(livingHumiditySlider);

        spinBox = new QSpinBox(layoutWidget10);
        spinBox->setObjectName(QStringLiteral("spinBox"));

        livingHumidity->addWidget(spinBox);

        livingHumidityBtn = new QPushButton(layoutWidget10);
        livingHumidityBtn->setObjectName(QStringLiteral("livingHumidityBtn"));

        livingHumidity->addWidget(livingHumidityBtn);

        layoutWidget11 = new QWidget(FurnitureOverviewPage);
        layoutWidget11->setObjectName(QStringLiteral("layoutWidget11"));
        layoutWidget11->setGeometry(QRect(100, 440, 361, 25));
        hostHumidity = new QHBoxLayout(layoutWidget11);
        hostHumidity->setObjectName(QStringLiteral("hostHumidity"));
        hostHumidity->setContentsMargins(0, 0, 0, 0);
        hostHumiditySlider = new QSlider(layoutWidget11);
        hostHumiditySlider->setObjectName(QStringLiteral("hostHumiditySlider"));
        hostHumiditySlider->setOrientation(Qt::Horizontal);

        hostHumidity->addWidget(hostHumiditySlider);

        spinBox_2 = new QSpinBox(layoutWidget11);
        spinBox_2->setObjectName(QStringLiteral("spinBox_2"));

        hostHumidity->addWidget(spinBox_2);

        hostHumidityBtn = new QPushButton(layoutWidget11);
        hostHumidityBtn->setObjectName(QStringLiteral("hostHumidityBtn"));

        hostHumidity->addWidget(hostHumidityBtn);

        tabWidget->addTab(FurnitureOverviewPage, QString());
        EnvirmentPage = new QWidget();
        EnvirmentPage->setObjectName(QStringLiteral("EnvirmentPage"));
        widget_2 = new EnvironmentWidget(EnvirmentPage);
        widget_2->setObjectName(QStringLiteral("widget_2"));
        widget_2->setGeometry(QRect(20, 20, 651, 441));
        tabWidget->addTab(EnvirmentPage, QString());
        DataAnalyticsPage = new QWidget();
        DataAnalyticsPage->setObjectName(QStringLiteral("DataAnalyticsPage"));
        widget = new DataWidget(DataAnalyticsPage);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(40, 30, 591, 421));
        tabWidget->addTab(DataAnalyticsPage, QString());

        retranslateUi(TabWidget);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(TabWidget);
    } // setupUi

    void retranslateUi(QWidget *TabWidget)
    {
        TabWidget->setWindowTitle(QApplication::translate("TabWidget", "Form", Q_NULLPTR));
        label->setText(QApplication::translate("TabWidget", "\347\251\272\350\260\203\346\216\247\345\210\266", Q_NULLPTR));
        label_15->setText(QApplication::translate("TabWidget", "\347\251\272\350\260\203\345\220\215\347\247\260\357\274\232", Q_NULLPTR));
        label_20->setText(QApplication::translate("TabWidget", "\347\251\272\350\260\203\345\274\200\345\205\263\357\274\232", Q_NULLPTR));
        label_16->setText(QApplication::translate("TabWidget", "\347\251\272\350\260\203\346\270\251\345\272\246\357\274\232", Q_NULLPTR));
        label_17->setText(QApplication::translate("TabWidget", "\347\251\272\350\260\203\346\250\241\345\274\217\357\274\232", Q_NULLPTR));
        label_18->setText(QApplication::translate("TabWidget", "\347\251\272\350\260\203\350\207\252\345\212\250\345\256\232\346\227\266\357\274\232", Q_NULLPTR));
        livingAir->setText(QApplication::translate("TabWidget", "\345\256\242\345\216\205\347\251\272\350\260\203", Q_NULLPTR));
        hostAir->setText(QApplication::translate("TabWidget", "\344\270\273\345\215\247\347\251\272\350\260\203", Q_NULLPTR));
        secondAir->setText(QApplication::translate("TabWidget", "\346\254\241\345\215\247\347\251\272\350\260\203", Q_NULLPTR));
        livingAirBtn->setText(QApplication::translate("TabWidget", "PushButton", Q_NULLPTR));
        hostAirBtn->setText(QApplication::translate("TabWidget", "PushButton", Q_NULLPTR));
        secondAirBtn->setText(QApplication::translate("TabWidget", "PushButton", Q_NULLPTR));
        label_5->setText(QApplication::translate("TabWidget", "\347\201\257\346\216\247\345\210\266", Q_NULLPTR));
        label_21->setText(QApplication::translate("TabWidget", "\347\201\257\345\220\215\357\274\232", Q_NULLPTR));
        label_19->setText(QApplication::translate("TabWidget", "\346\250\241\345\274\217\351\200\211\346\213\251\357\274\232", Q_NULLPTR));
        label_22->setText(QApplication::translate("TabWidget", "\347\201\257\350\207\252\345\212\250\345\256\232\346\227\266\357\274\232", Q_NULLPTR));
        label_6->setText(QApplication::translate("TabWidget", "\345\256\242\345\216\205\347\201\257", Q_NULLPTR));
        label_7->setText(QApplication::translate("TabWidget", "\344\270\273\345\215\247\347\201\257", Q_NULLPTR));
        label_8->setText(QApplication::translate("TabWidget", "\346\254\241\345\215\247\347\201\257", Q_NULLPTR));
        label_9->setText(QApplication::translate("TabWidget", "\345\212\240\346\271\277\345\231\250\346\216\247\345\210\266", Q_NULLPTR));
        label_10->setText(QApplication::translate("TabWidget", "\345\256\242\345\216\205\345\212\240\346\271\277\345\231\250", Q_NULLPTR));
        label_11->setText(QApplication::translate("TabWidget", "\344\270\273\345\215\247\345\212\240\346\271\277\345\231\250", Q_NULLPTR));
        livingHumidityBtn->setText(QApplication::translate("TabWidget", "PushButton", Q_NULLPTR));
        hostHumidityBtn->setText(QApplication::translate("TabWidget", "PushButton", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(FurnitureOverviewPage), QApplication::translate("TabWidget", "\345\256\266\345\205\267\346\200\273\350\247\210", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(EnvirmentPage), QApplication::translate("TabWidget", "\347\216\257\345\242\203\347\233\221\346\265\213", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(DataAnalyticsPage), QApplication::translate("TabWidget", "\346\225\260\346\215\256\345\210\206\346\236\220", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class TabWidget: public Ui_TabWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TABWIDGET_H
