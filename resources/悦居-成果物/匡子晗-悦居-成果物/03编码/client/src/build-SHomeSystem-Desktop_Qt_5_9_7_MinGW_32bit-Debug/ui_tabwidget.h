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
#include "loginview.h"
#include "registerview.h"

QT_BEGIN_NAMESPACE

class Ui_TabWidget
{
public:
    QTabWidget *tabWidget;
    QWidget *ControlPage;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout_5;
    QVBoxLayout *humidityTitle;
    QLabel *label_9;
    QLabel *label_10;
    QLabel *label_11;
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayout_3;
    QLabel *livingHumidityShow;
    QLabel *hostHumidityShow;
    QHBoxLayout *livingHumidity;
    QSlider *livingHumiditySlider;
    QSpinBox *livingHumiditySpin;
    QPushButton *livingHumidityBtn;
    QHBoxLayout *hostHumidity;
    QSlider *hostHumiditySlider;
    QSpinBox *hostHumiditySpin;
    QPushButton *hostHumidityBtn;
    QWidget *layoutWidget1;
    QHBoxLayout *horizontalLayout_4;
    QVBoxLayout *lightTitle;
    QLabel *label_5;
    QLabel *label_2;
    QLabel *label_21;
    QLabel *label_19;
    QLabel *label_22;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout_2;
    QLabel *livingLightShow;
    QLabel *hostLightShow;
    QLabel *secondLightShow;
    QHBoxLayout *horizontalLayout_6;
    QSpacerItem *horizontalSpacer_34;
    QPushButton *livingLightBtn;
    QSpacerItem *horizontalSpacer_33;
    QPushButton *hostLightBtn;
    QSpacerItem *horizontalSpacer_36;
    QPushButton *secondLightBtn;
    QSpacerItem *horizontalSpacer_35;
    QHBoxLayout *lightName;
    QSpacerItem *horizontalSpacer_27;
    QLabel *label_6;
    QSpacerItem *horizontalSpacer_11;
    QLabel *label_7;
    QSpacerItem *horizontalSpacer_12;
    QLabel *label_8;
    QSpacerItem *horizontalSpacer_30;
    QHBoxLayout *lightMode;
    QSpacerItem *horizontalSpacer_28;
    QComboBox *livingLightMode;
    QSpacerItem *horizontalSpacer_13;
    QComboBox *hostLightMode;
    QSpacerItem *horizontalSpacer_14;
    QComboBox *secondLightMode;
    QSpacerItem *horizontalSpacer_31;
    QHBoxLayout *lightAuto;
    QSpacerItem *horizontalSpacer_29;
    QTimeEdit *livingLightAuto;
    QPushButton *livingLightTimeBtn;
    QSpacerItem *horizontalSpacer_15;
    QTimeEdit *hostLightAuto;
    QPushButton *hostLightTimeBtn;
    QSpacerItem *horizontalSpacer_16;
    QTimeEdit *secondLightAuto;
    QPushButton *secondLightTimeBtn;
    QSpacerItem *horizontalSpacer_32;
    QWidget *layoutWidget2;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *airTitle;
    QLabel *label;
    QLabel *label_15;
    QLabel *label_20;
    QLabel *label_16;
    QLabel *label_17;
    QLabel *label_18;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *Details;
    QLabel *livingAirShow;
    QLabel *hostAirShow;
    QLabel *secondAirShow;
    QHBoxLayout *airName;
    QSpacerItem *horizontalSpacer_17;
    QLabel *livingAir;
    QSpacerItem *horizontalSpacer_7;
    QLabel *hostAir;
    QSpacerItem *horizontalSpacer_8;
    QLabel *secondAir;
    QSpacerItem *horizontalSpacer_22;
    QHBoxLayout *airBtn;
    QSpacerItem *horizontalSpacer_18;
    QPushButton *livingAirBtn;
    QSpacerItem *horizontalSpacer_9;
    QPushButton *hostAirBtn;
    QSpacerItem *horizontalSpacer_10;
    QPushButton *secondAirBtn;
    QSpacerItem *horizontalSpacer_23;
    QHBoxLayout *airLcd;
    QSpacerItem *horizontalSpacer_19;
    QLineEdit *livingAirEdit;
    QSpacerItem *horizontalSpacer;
    QLineEdit *hostAirEdit;
    QSpacerItem *horizontalSpacer_2;
    QLineEdit *secondAirEdit;
    QSpacerItem *horizontalSpacer_24;
    QHBoxLayout *airMode;
    QSpacerItem *horizontalSpacer_20;
    QComboBox *livingAirMode;
    QSpacerItem *horizontalSpacer_3;
    QComboBox *hostAirMode;
    QSpacerItem *horizontalSpacer_4;
    QComboBox *secondAirMode;
    QSpacerItem *horizontalSpacer_25;
    QHBoxLayout *airAuto;
    QSpacerItem *horizontalSpacer_21;
    QTimeEdit *livingAirTime;
    QPushButton *livingAirTimeBtn;
    QSpacerItem *horizontalSpacer_5;
    QTimeEdit *hostAirTime;
    QPushButton *hostAirTimeBtn;
    QSpacerItem *horizontalSpacer_6;
    QTimeEdit *secondAirTime;
    QPushButton *secondAirTimeBtn;
    QSpacerItem *horizontalSpacer_26;
    QWidget *DataAnalyticsPage;
    DataWidget *widget;
    QWidget *loginTab;
    LoginView *widget_3;
    QWidget *registerTab;
    RegisterView *widget_2;

    void setupUi(QWidget *TabWidget)
    {
        if (TabWidget->objectName().isEmpty())
            TabWidget->setObjectName(QStringLiteral("TabWidget"));
        TabWidget->resize(1000, 900);
        tabWidget = new QTabWidget(TabWidget);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        tabWidget->setGeometry(QRect(0, 10, 1531, 891));
        tabWidget->setTabPosition(QTabWidget::West);
        ControlPage = new QWidget();
        ControlPage->setObjectName(QStringLiteral("ControlPage"));
        layoutWidget = new QWidget(ControlPage);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(20, 660, 921, 211));
        horizontalLayout_5 = new QHBoxLayout(layoutWidget);
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        horizontalLayout_5->setContentsMargins(0, 0, 0, 0);
        humidityTitle = new QVBoxLayout();
        humidityTitle->setObjectName(QStringLiteral("humidityTitle"));
        label_9 = new QLabel(layoutWidget);
        label_9->setObjectName(QStringLiteral("label_9"));

        humidityTitle->addWidget(label_9);

        label_10 = new QLabel(layoutWidget);
        label_10->setObjectName(QStringLiteral("label_10"));

        humidityTitle->addWidget(label_10);

        label_11 = new QLabel(layoutWidget);
        label_11->setObjectName(QStringLiteral("label_11"));

        humidityTitle->addWidget(label_11);


        horizontalLayout_5->addLayout(humidityTitle);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        livingHumidityShow = new QLabel(layoutWidget);
        livingHumidityShow->setObjectName(QStringLiteral("livingHumidityShow"));

        horizontalLayout_3->addWidget(livingHumidityShow);

        hostHumidityShow = new QLabel(layoutWidget);
        hostHumidityShow->setObjectName(QStringLiteral("hostHumidityShow"));

        horizontalLayout_3->addWidget(hostHumidityShow);


        verticalLayout_3->addLayout(horizontalLayout_3);

        livingHumidity = new QHBoxLayout();
        livingHumidity->setObjectName(QStringLiteral("livingHumidity"));
        livingHumiditySlider = new QSlider(layoutWidget);
        livingHumiditySlider->setObjectName(QStringLiteral("livingHumiditySlider"));
        livingHumiditySlider->setOrientation(Qt::Horizontal);

        livingHumidity->addWidget(livingHumiditySlider);

        livingHumiditySpin = new QSpinBox(layoutWidget);
        livingHumiditySpin->setObjectName(QStringLiteral("livingHumiditySpin"));

        livingHumidity->addWidget(livingHumiditySpin);

        livingHumidityBtn = new QPushButton(layoutWidget);
        livingHumidityBtn->setObjectName(QStringLiteral("livingHumidityBtn"));

        livingHumidity->addWidget(livingHumidityBtn);


        verticalLayout_3->addLayout(livingHumidity);

        hostHumidity = new QHBoxLayout();
        hostHumidity->setObjectName(QStringLiteral("hostHumidity"));
        hostHumiditySlider = new QSlider(layoutWidget);
        hostHumiditySlider->setObjectName(QStringLiteral("hostHumiditySlider"));
        hostHumiditySlider->setOrientation(Qt::Horizontal);

        hostHumidity->addWidget(hostHumiditySlider);

        hostHumiditySpin = new QSpinBox(layoutWidget);
        hostHumiditySpin->setObjectName(QStringLiteral("hostHumiditySpin"));

        hostHumidity->addWidget(hostHumiditySpin);

        hostHumidityBtn = new QPushButton(layoutWidget);
        hostHumidityBtn->setObjectName(QStringLiteral("hostHumidityBtn"));

        hostHumidity->addWidget(hostHumidityBtn);


        verticalLayout_3->addLayout(hostHumidity);


        horizontalLayout_5->addLayout(verticalLayout_3);

        layoutWidget1 = new QWidget(ControlPage);
        layoutWidget1->setObjectName(QStringLiteral("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(20, 380, 921, 271));
        horizontalLayout_4 = new QHBoxLayout(layoutWidget1);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        horizontalLayout_4->setContentsMargins(0, 0, 0, 0);
        lightTitle = new QVBoxLayout();
        lightTitle->setObjectName(QStringLiteral("lightTitle"));
        label_5 = new QLabel(layoutWidget1);
        label_5->setObjectName(QStringLiteral("label_5"));

        lightTitle->addWidget(label_5);

        label_2 = new QLabel(layoutWidget1);
        label_2->setObjectName(QStringLiteral("label_2"));

        lightTitle->addWidget(label_2);

        label_21 = new QLabel(layoutWidget1);
        label_21->setObjectName(QStringLiteral("label_21"));

        lightTitle->addWidget(label_21);

        label_19 = new QLabel(layoutWidget1);
        label_19->setObjectName(QStringLiteral("label_19"));

        lightTitle->addWidget(label_19);

        label_22 = new QLabel(layoutWidget1);
        label_22->setObjectName(QStringLiteral("label_22"));

        lightTitle->addWidget(label_22);


        horizontalLayout_4->addLayout(lightTitle);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        livingLightShow = new QLabel(layoutWidget1);
        livingLightShow->setObjectName(QStringLiteral("livingLightShow"));

        horizontalLayout_2->addWidget(livingLightShow);

        hostLightShow = new QLabel(layoutWidget1);
        hostLightShow->setObjectName(QStringLiteral("hostLightShow"));

        horizontalLayout_2->addWidget(hostLightShow);

        secondLightShow = new QLabel(layoutWidget1);
        secondLightShow->setObjectName(QStringLiteral("secondLightShow"));

        horizontalLayout_2->addWidget(secondLightShow);


        verticalLayout_2->addLayout(horizontalLayout_2);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        horizontalSpacer_34 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_6->addItem(horizontalSpacer_34);

        livingLightBtn = new QPushButton(layoutWidget1);
        livingLightBtn->setObjectName(QStringLiteral("livingLightBtn"));

        horizontalLayout_6->addWidget(livingLightBtn);

        horizontalSpacer_33 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_6->addItem(horizontalSpacer_33);

        hostLightBtn = new QPushButton(layoutWidget1);
        hostLightBtn->setObjectName(QStringLiteral("hostLightBtn"));

        horizontalLayout_6->addWidget(hostLightBtn);

        horizontalSpacer_36 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_6->addItem(horizontalSpacer_36);

        secondLightBtn = new QPushButton(layoutWidget1);
        secondLightBtn->setObjectName(QStringLiteral("secondLightBtn"));

        horizontalLayout_6->addWidget(secondLightBtn);

        horizontalSpacer_35 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_6->addItem(horizontalSpacer_35);


        verticalLayout_2->addLayout(horizontalLayout_6);

        lightName = new QHBoxLayout();
        lightName->setObjectName(QStringLiteral("lightName"));
        horizontalSpacer_27 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        lightName->addItem(horizontalSpacer_27);

        label_6 = new QLabel(layoutWidget1);
        label_6->setObjectName(QStringLiteral("label_6"));

        lightName->addWidget(label_6);

        horizontalSpacer_11 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        lightName->addItem(horizontalSpacer_11);

        label_7 = new QLabel(layoutWidget1);
        label_7->setObjectName(QStringLiteral("label_7"));

        lightName->addWidget(label_7);

        horizontalSpacer_12 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        lightName->addItem(horizontalSpacer_12);

        label_8 = new QLabel(layoutWidget1);
        label_8->setObjectName(QStringLiteral("label_8"));

        lightName->addWidget(label_8);

        horizontalSpacer_30 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        lightName->addItem(horizontalSpacer_30);


        verticalLayout_2->addLayout(lightName);

        lightMode = new QHBoxLayout();
        lightMode->setObjectName(QStringLiteral("lightMode"));
        horizontalSpacer_28 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        lightMode->addItem(horizontalSpacer_28);

        livingLightMode = new QComboBox(layoutWidget1);
        livingLightMode->setObjectName(QStringLiteral("livingLightMode"));

        lightMode->addWidget(livingLightMode);

        horizontalSpacer_13 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        lightMode->addItem(horizontalSpacer_13);

        hostLightMode = new QComboBox(layoutWidget1);
        hostLightMode->setObjectName(QStringLiteral("hostLightMode"));

        lightMode->addWidget(hostLightMode);

        horizontalSpacer_14 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        lightMode->addItem(horizontalSpacer_14);

        secondLightMode = new QComboBox(layoutWidget1);
        secondLightMode->setObjectName(QStringLiteral("secondLightMode"));

        lightMode->addWidget(secondLightMode);

        horizontalSpacer_31 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        lightMode->addItem(horizontalSpacer_31);


        verticalLayout_2->addLayout(lightMode);

        lightAuto = new QHBoxLayout();
        lightAuto->setObjectName(QStringLiteral("lightAuto"));
        horizontalSpacer_29 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        lightAuto->addItem(horizontalSpacer_29);

        livingLightAuto = new QTimeEdit(layoutWidget1);
        livingLightAuto->setObjectName(QStringLiteral("livingLightAuto"));

        lightAuto->addWidget(livingLightAuto);

        livingLightTimeBtn = new QPushButton(layoutWidget1);
        livingLightTimeBtn->setObjectName(QStringLiteral("livingLightTimeBtn"));

        lightAuto->addWidget(livingLightTimeBtn);

        horizontalSpacer_15 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        lightAuto->addItem(horizontalSpacer_15);

        hostLightAuto = new QTimeEdit(layoutWidget1);
        hostLightAuto->setObjectName(QStringLiteral("hostLightAuto"));

        lightAuto->addWidget(hostLightAuto);

        hostLightTimeBtn = new QPushButton(layoutWidget1);
        hostLightTimeBtn->setObjectName(QStringLiteral("hostLightTimeBtn"));

        lightAuto->addWidget(hostLightTimeBtn);

        horizontalSpacer_16 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        lightAuto->addItem(horizontalSpacer_16);

        secondLightAuto = new QTimeEdit(layoutWidget1);
        secondLightAuto->setObjectName(QStringLiteral("secondLightAuto"));

        lightAuto->addWidget(secondLightAuto);

        secondLightTimeBtn = new QPushButton(layoutWidget1);
        secondLightTimeBtn->setObjectName(QStringLiteral("secondLightTimeBtn"));

        lightAuto->addWidget(secondLightTimeBtn);

        horizontalSpacer_32 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        lightAuto->addItem(horizontalSpacer_32);


        verticalLayout_2->addLayout(lightAuto);


        horizontalLayout_4->addLayout(verticalLayout_2);

        layoutWidget2 = new QWidget(ControlPage);
        layoutWidget2->setObjectName(QStringLiteral("layoutWidget2"));
        layoutWidget2->setGeometry(QRect(20, 30, 921, 331));
        horizontalLayout = new QHBoxLayout(layoutWidget2);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        airTitle = new QVBoxLayout();
        airTitle->setObjectName(QStringLiteral("airTitle"));
        label = new QLabel(layoutWidget2);
        label->setObjectName(QStringLiteral("label"));

        airTitle->addWidget(label);

        label_15 = new QLabel(layoutWidget2);
        label_15->setObjectName(QStringLiteral("label_15"));

        airTitle->addWidget(label_15);

        label_20 = new QLabel(layoutWidget2);
        label_20->setObjectName(QStringLiteral("label_20"));

        airTitle->addWidget(label_20);

        label_16 = new QLabel(layoutWidget2);
        label_16->setObjectName(QStringLiteral("label_16"));

        airTitle->addWidget(label_16);

        label_17 = new QLabel(layoutWidget2);
        label_17->setObjectName(QStringLiteral("label_17"));

        airTitle->addWidget(label_17);

        label_18 = new QLabel(layoutWidget2);
        label_18->setObjectName(QStringLiteral("label_18"));

        airTitle->addWidget(label_18);


        horizontalLayout->addLayout(airTitle);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        Details = new QHBoxLayout();
        Details->setObjectName(QStringLiteral("Details"));
        livingAirShow = new QLabel(layoutWidget2);
        livingAirShow->setObjectName(QStringLiteral("livingAirShow"));
        QFont font;
        font.setFamily(QStringLiteral("Agency FB"));
        font.setPointSize(10);
        livingAirShow->setFont(font);

        Details->addWidget(livingAirShow);

        hostAirShow = new QLabel(layoutWidget2);
        hostAirShow->setObjectName(QStringLiteral("hostAirShow"));
        hostAirShow->setFont(font);

        Details->addWidget(hostAirShow);

        secondAirShow = new QLabel(layoutWidget2);
        secondAirShow->setObjectName(QStringLiteral("secondAirShow"));
        secondAirShow->setFont(font);

        Details->addWidget(secondAirShow);


        verticalLayout->addLayout(Details);

        airName = new QHBoxLayout();
        airName->setObjectName(QStringLiteral("airName"));
        horizontalSpacer_17 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        airName->addItem(horizontalSpacer_17);

        livingAir = new QLabel(layoutWidget2);
        livingAir->setObjectName(QStringLiteral("livingAir"));

        airName->addWidget(livingAir);

        horizontalSpacer_7 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        airName->addItem(horizontalSpacer_7);

        hostAir = new QLabel(layoutWidget2);
        hostAir->setObjectName(QStringLiteral("hostAir"));

        airName->addWidget(hostAir);

        horizontalSpacer_8 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        airName->addItem(horizontalSpacer_8);

        secondAir = new QLabel(layoutWidget2);
        secondAir->setObjectName(QStringLiteral("secondAir"));

        airName->addWidget(secondAir);

        horizontalSpacer_22 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        airName->addItem(horizontalSpacer_22);


        verticalLayout->addLayout(airName);

        airBtn = new QHBoxLayout();
        airBtn->setObjectName(QStringLiteral("airBtn"));
        horizontalSpacer_18 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        airBtn->addItem(horizontalSpacer_18);

        livingAirBtn = new QPushButton(layoutWidget2);
        livingAirBtn->setObjectName(QStringLiteral("livingAirBtn"));

        airBtn->addWidget(livingAirBtn);

        horizontalSpacer_9 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        airBtn->addItem(horizontalSpacer_9);

        hostAirBtn = new QPushButton(layoutWidget2);
        hostAirBtn->setObjectName(QStringLiteral("hostAirBtn"));

        airBtn->addWidget(hostAirBtn);

        horizontalSpacer_10 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        airBtn->addItem(horizontalSpacer_10);

        secondAirBtn = new QPushButton(layoutWidget2);
        secondAirBtn->setObjectName(QStringLiteral("secondAirBtn"));

        airBtn->addWidget(secondAirBtn);

        horizontalSpacer_23 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        airBtn->addItem(horizontalSpacer_23);


        verticalLayout->addLayout(airBtn);

        airLcd = new QHBoxLayout();
        airLcd->setObjectName(QStringLiteral("airLcd"));
        horizontalSpacer_19 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        airLcd->addItem(horizontalSpacer_19);

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

        horizontalSpacer_24 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        airLcd->addItem(horizontalSpacer_24);


        verticalLayout->addLayout(airLcd);

        airMode = new QHBoxLayout();
        airMode->setObjectName(QStringLiteral("airMode"));
        horizontalSpacer_20 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        airMode->addItem(horizontalSpacer_20);

        livingAirMode = new QComboBox(layoutWidget2);
        livingAirMode->setObjectName(QStringLiteral("livingAirMode"));

        airMode->addWidget(livingAirMode);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        airMode->addItem(horizontalSpacer_3);

        hostAirMode = new QComboBox(layoutWidget2);
        hostAirMode->setObjectName(QStringLiteral("hostAirMode"));

        airMode->addWidget(hostAirMode);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        airMode->addItem(horizontalSpacer_4);

        secondAirMode = new QComboBox(layoutWidget2);
        secondAirMode->setObjectName(QStringLiteral("secondAirMode"));

        airMode->addWidget(secondAirMode);

        horizontalSpacer_25 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        airMode->addItem(horizontalSpacer_25);


        verticalLayout->addLayout(airMode);

        airAuto = new QHBoxLayout();
        airAuto->setObjectName(QStringLiteral("airAuto"));
        horizontalSpacer_21 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        airAuto->addItem(horizontalSpacer_21);

        livingAirTime = new QTimeEdit(layoutWidget2);
        livingAirTime->setObjectName(QStringLiteral("livingAirTime"));

        airAuto->addWidget(livingAirTime);

        livingAirTimeBtn = new QPushButton(layoutWidget2);
        livingAirTimeBtn->setObjectName(QStringLiteral("livingAirTimeBtn"));

        airAuto->addWidget(livingAirTimeBtn);

        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        airAuto->addItem(horizontalSpacer_5);

        hostAirTime = new QTimeEdit(layoutWidget2);
        hostAirTime->setObjectName(QStringLiteral("hostAirTime"));

        airAuto->addWidget(hostAirTime);

        hostAirTimeBtn = new QPushButton(layoutWidget2);
        hostAirTimeBtn->setObjectName(QStringLiteral("hostAirTimeBtn"));

        airAuto->addWidget(hostAirTimeBtn);

        horizontalSpacer_6 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        airAuto->addItem(horizontalSpacer_6);

        secondAirTime = new QTimeEdit(layoutWidget2);
        secondAirTime->setObjectName(QStringLiteral("secondAirTime"));

        airAuto->addWidget(secondAirTime);

        secondAirTimeBtn = new QPushButton(layoutWidget2);
        secondAirTimeBtn->setObjectName(QStringLiteral("secondAirTimeBtn"));

        airAuto->addWidget(secondAirTimeBtn);

        horizontalSpacer_26 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        airAuto->addItem(horizontalSpacer_26);


        verticalLayout->addLayout(airAuto);


        horizontalLayout->addLayout(verticalLayout);

        tabWidget->addTab(ControlPage, QString());
        DataAnalyticsPage = new QWidget();
        DataAnalyticsPage->setObjectName(QStringLiteral("DataAnalyticsPage"));
        widget = new DataWidget(DataAnalyticsPage);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(0, 0, 971, 900));
        tabWidget->addTab(DataAnalyticsPage, QString());
        loginTab = new QWidget();
        loginTab->setObjectName(QStringLiteral("loginTab"));
        widget_3 = new LoginView(loginTab);
        widget_3->setObjectName(QStringLiteral("widget_3"));
        widget_3->setGeometry(QRect(10, 20, 500, 500));
        tabWidget->addTab(loginTab, QString());
        registerTab = new QWidget();
        registerTab->setObjectName(QStringLiteral("registerTab"));
        widget_2 = new RegisterView(registerTab);
        widget_2->setObjectName(QStringLiteral("widget_2"));
        widget_2->setGeometry(QRect(10, 20, 500, 500));
        tabWidget->addTab(registerTab, QString());

        retranslateUi(TabWidget);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(TabWidget);
    } // setupUi

    void retranslateUi(QWidget *TabWidget)
    {
        TabWidget->setWindowTitle(QApplication::translate("TabWidget", "Form", Q_NULLPTR));
        label_9->setText(QApplication::translate("TabWidget", "\345\212\240\346\271\277\345\231\250\347\212\266\346\200\201", Q_NULLPTR));
        label_10->setText(QApplication::translate("TabWidget", "\345\256\242\345\216\205\345\212\240\346\271\277\345\231\250", Q_NULLPTR));
        label_11->setText(QApplication::translate("TabWidget", "\344\270\273\345\215\247\345\212\240\346\271\277\345\231\250", Q_NULLPTR));
        livingHumidityShow->setText(QApplication::translate("TabWidget", "TextLabel", Q_NULLPTR));
        hostHumidityShow->setText(QApplication::translate("TabWidget", "TextLabel", Q_NULLPTR));
        livingHumidityBtn->setText(QApplication::translate("TabWidget", "\347\241\256\345\256\232", Q_NULLPTR));
        hostHumidityBtn->setText(QApplication::translate("TabWidget", "\347\241\256\345\256\232", Q_NULLPTR));
        label_5->setText(QApplication::translate("TabWidget", "\347\201\257\347\212\266\346\200\201", Q_NULLPTR));
        label_2->setText(QApplication::translate("TabWidget", "\347\201\257\345\274\200\345\205\263\357\274\232", Q_NULLPTR));
        label_21->setText(QApplication::translate("TabWidget", "\347\201\257\345\220\215\357\274\232", Q_NULLPTR));
        label_19->setText(QApplication::translate("TabWidget", "\346\250\241\345\274\217\351\200\211\346\213\251\357\274\232", Q_NULLPTR));
        label_22->setText(QApplication::translate("TabWidget", "\347\201\257\350\207\252\345\212\250\345\256\232\346\227\266\357\274\232", Q_NULLPTR));
        livingLightShow->setText(QApplication::translate("TabWidget", "TextLabel", Q_NULLPTR));
        hostLightShow->setText(QApplication::translate("TabWidget", "TextLabel", Q_NULLPTR));
        secondLightShow->setText(QApplication::translate("TabWidget", "TextLabel", Q_NULLPTR));
        livingLightBtn->setText(QApplication::translate("TabWidget", "\345\274\200/\345\205\263", Q_NULLPTR));
        hostLightBtn->setText(QApplication::translate("TabWidget", "\345\274\200/\345\205\263", Q_NULLPTR));
        secondLightBtn->setText(QApplication::translate("TabWidget", "\345\274\200/\345\205\263", Q_NULLPTR));
        label_6->setText(QApplication::translate("TabWidget", "\345\256\242\345\216\205\347\201\257", Q_NULLPTR));
        label_7->setText(QApplication::translate("TabWidget", "\344\270\273\345\215\247\347\201\257", Q_NULLPTR));
        label_8->setText(QApplication::translate("TabWidget", "\346\254\241\345\215\247\347\201\257", Q_NULLPTR));
        livingLightTimeBtn->setText(QApplication::translate("TabWidget", "\347\241\256\345\256\232", Q_NULLPTR));
        hostLightTimeBtn->setText(QApplication::translate("TabWidget", "\347\241\256\345\256\232", Q_NULLPTR));
        secondLightTimeBtn->setText(QApplication::translate("TabWidget", "\347\241\256\345\256\232", Q_NULLPTR));
        label->setText(QApplication::translate("TabWidget", "\347\251\272\350\260\203\347\212\266\346\200\201", Q_NULLPTR));
        label_15->setText(QApplication::translate("TabWidget", "\347\251\272\350\260\203\345\220\215\347\247\260\357\274\232", Q_NULLPTR));
        label_20->setText(QApplication::translate("TabWidget", "\347\251\272\350\260\203\345\274\200\345\205\263\357\274\232", Q_NULLPTR));
        label_16->setText(QApplication::translate("TabWidget", "\347\251\272\350\260\203\346\270\251\345\272\246\357\274\232", Q_NULLPTR));
        label_17->setText(QApplication::translate("TabWidget", "\347\251\272\350\260\203\346\250\241\345\274\217\357\274\232", Q_NULLPTR));
        label_18->setText(QApplication::translate("TabWidget", "\347\251\272\350\260\203\350\207\252\345\212\250\345\256\232\346\227\266\357\274\232", Q_NULLPTR));
        livingAirShow->setText(QApplication::translate("TabWidget", "TextLabel", Q_NULLPTR));
        hostAirShow->setText(QApplication::translate("TabWidget", "TextLabel", Q_NULLPTR));
        secondAirShow->setText(QApplication::translate("TabWidget", "TextLabel", Q_NULLPTR));
        livingAir->setText(QApplication::translate("TabWidget", "\345\256\242\345\216\205\347\251\272\350\260\203", Q_NULLPTR));
        hostAir->setText(QApplication::translate("TabWidget", "\344\270\273\345\215\247\347\251\272\350\260\203", Q_NULLPTR));
        secondAir->setText(QApplication::translate("TabWidget", "\346\254\241\345\215\247\347\251\272\350\260\203", Q_NULLPTR));
        livingAirBtn->setText(QApplication::translate("TabWidget", "\345\274\200/\345\205\263", Q_NULLPTR));
        hostAirBtn->setText(QApplication::translate("TabWidget", "\345\274\200/\345\205\263", Q_NULLPTR));
        secondAirBtn->setText(QApplication::translate("TabWidget", "\345\274\200/\345\205\263", Q_NULLPTR));
        livingAirTimeBtn->setText(QApplication::translate("TabWidget", "\347\241\256\345\256\232", Q_NULLPTR));
        hostAirTimeBtn->setText(QApplication::translate("TabWidget", "\347\241\256\345\256\232", Q_NULLPTR));
        secondAirTimeBtn->setText(QApplication::translate("TabWidget", "\347\241\256\345\256\232", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(ControlPage), QApplication::translate("TabWidget", "\345\256\266\345\261\205\346\216\247\345\210\266", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(DataAnalyticsPage), QApplication::translate("TabWidget", "\346\225\260\346\215\256\345\210\206\346\236\220", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(loginTab), QApplication::translate("TabWidget", "\347\231\273\345\275\225\351\241\265\351\235\242", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(registerTab), QApplication::translate("TabWidget", "\346\263\250\345\206\214\351\241\265\351\235\242", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class TabWidget: public Ui_TabWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TABWIDGET_H
