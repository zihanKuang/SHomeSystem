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
#include <QtWidgets/QLCDNumber>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpacerItem>
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
    QLabel *label_5;
    QLabel *label_6;
    QLabel *label_7;
    QLabel *label_8;
    QLabel *label_9;
    QLabel *label_10;
    QLabel *label_11;
    QLabel *label_19;
    QComboBox *comboBox;
    QComboBox *comboBox_2;
    QComboBox *comboBox_3;
    QSlider *horizontalSlider;
    QSlider *horizontalSlider_2;
    QPushButton *pushButton_4;
    QPushButton *pushButton_5;
    QLCDNumber *lcdNumber_4;
    QLCDNumber *lcdNumber_5;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QLabel *label_15;
    QLabel *label_20;
    QLabel *label_16;
    QLabel *label_17;
    QLabel *label_18;
    QWidget *layoutWidget1;
    QHBoxLayout *horizontalLayout;
    QLabel *label_2;
    QSpacerItem *horizontalSpacer_7;
    QLabel *label_3;
    QSpacerItem *horizontalSpacer_8;
    QLabel *label_4;
    QWidget *layoutWidget2;
    QHBoxLayout *horizontalLayout_2;
    QLCDNumber *lcdNumber;
    QSpacerItem *horizontalSpacer;
    QLCDNumber *lcdNumber_2;
    QSpacerItem *horizontalSpacer_2;
    QLCDNumber *lcdNumber_3;
    QWidget *layoutWidget3;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_12;
    QSpacerItem *horizontalSpacer_3;
    QLabel *label_13;
    QSpacerItem *horizontalSpacer_4;
    QLabel *label_14;
    QWidget *layoutWidget4;
    QHBoxLayout *horizontalLayout_4;
    QTimeEdit *timeEdit;
    QSpacerItem *horizontalSpacer_5;
    QTimeEdit *timeEdit_2;
    QSpacerItem *horizontalSpacer_6;
    QTimeEdit *timeEdit_3;
    QWidget *layoutWidget5;
    QHBoxLayout *horizontalLayout_5;
    QPushButton *pushButton;
    QSpacerItem *horizontalSpacer_9;
    QPushButton *pushButton_2;
    QSpacerItem *horizontalSpacer_10;
    QPushButton *pushButton_3;
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
        tabWidget->setGeometry(QRect(10, 130, 711, 461));
        tabWidget->setTabPosition(QTabWidget::West);
        FurnitureOverviewPage = new QWidget();
        FurnitureOverviewPage->setObjectName(QStringLiteral("FurnitureOverviewPage"));
        label_5 = new QLabel(FurnitureOverviewPage);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(30, 220, 41, 9));
        label_6 = new QLabel(FurnitureOverviewPage);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(140, 220, 41, 9));
        label_7 = new QLabel(FurnitureOverviewPage);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setGeometry(QRect(380, 220, 41, 20));
        label_8 = new QLabel(FurnitureOverviewPage);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setGeometry(QRect(640, 220, 41, 9));
        label_9 = new QLabel(FurnitureOverviewPage);
        label_9->setObjectName(QStringLiteral("label_9"));
        label_9->setGeometry(QRect(30, 340, 41, 9));
        label_10 = new QLabel(FurnitureOverviewPage);
        label_10->setObjectName(QStringLiteral("label_10"));
        label_10->setGeometry(QRect(30, 380, 51, 16));
        label_11 = new QLabel(FurnitureOverviewPage);
        label_11->setObjectName(QStringLiteral("label_11"));
        label_11->setGeometry(QRect(30, 440, 61, 16));
        label_19 = new QLabel(FurnitureOverviewPage);
        label_19->setObjectName(QStringLiteral("label_19"));
        label_19->setGeometry(QRect(20, 260, 41, 9));
        comboBox = new QComboBox(FurnitureOverviewPage);
        comboBox->setObjectName(QStringLiteral("comboBox"));
        comboBox->setGeometry(QRect(120, 250, 62, 22));
        comboBox_2 = new QComboBox(FurnitureOverviewPage);
        comboBox_2->setObjectName(QStringLiteral("comboBox_2"));
        comboBox_2->setGeometry(QRect(360, 250, 62, 22));
        comboBox_3 = new QComboBox(FurnitureOverviewPage);
        comboBox_3->setObjectName(QStringLiteral("comboBox_3"));
        comboBox_3->setGeometry(QRect(630, 240, 62, 22));
        horizontalSlider = new QSlider(FurnitureOverviewPage);
        horizontalSlider->setObjectName(QStringLiteral("horizontalSlider"));
        horizontalSlider->setGeometry(QRect(110, 380, 160, 16));
        horizontalSlider->setOrientation(Qt::Horizontal);
        horizontalSlider_2 = new QSlider(FurnitureOverviewPage);
        horizontalSlider_2->setObjectName(QStringLiteral("horizontalSlider_2"));
        horizontalSlider_2->setGeometry(QRect(110, 440, 160, 16));
        horizontalSlider_2->setOrientation(Qt::Horizontal);
        pushButton_4 = new QPushButton(FurnitureOverviewPage);
        pushButton_4->setObjectName(QStringLiteral("pushButton_4"));
        pushButton_4->setGeometry(QRect(360, 380, 80, 15));
        pushButton_5 = new QPushButton(FurnitureOverviewPage);
        pushButton_5->setObjectName(QStringLiteral("pushButton_5"));
        pushButton_5->setGeometry(QRect(360, 440, 80, 15));
        lcdNumber_4 = new QLCDNumber(FurnitureOverviewPage);
        lcdNumber_4->setObjectName(QStringLiteral("lcdNumber_4"));
        lcdNumber_4->setGeometry(QRect(280, 380, 64, 23));
        lcdNumber_5 = new QLCDNumber(FurnitureOverviewPage);
        lcdNumber_5->setObjectName(QStringLiteral("lcdNumber_5"));
        lcdNumber_5->setGeometry(QRect(280, 430, 64, 23));
        layoutWidget = new QWidget(FurnitureOverviewPage);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(20, 10, 65, 171));
        verticalLayout = new QVBoxLayout(layoutWidget);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(layoutWidget);
        label->setObjectName(QStringLiteral("label"));

        verticalLayout->addWidget(label);

        label_15 = new QLabel(layoutWidget);
        label_15->setObjectName(QStringLiteral("label_15"));

        verticalLayout->addWidget(label_15);

        label_20 = new QLabel(layoutWidget);
        label_20->setObjectName(QStringLiteral("label_20"));

        verticalLayout->addWidget(label_20);

        label_16 = new QLabel(layoutWidget);
        label_16->setObjectName(QStringLiteral("label_16"));

        verticalLayout->addWidget(label_16);

        label_17 = new QLabel(layoutWidget);
        label_17->setObjectName(QStringLiteral("label_17"));

        verticalLayout->addWidget(label_17);

        label_18 = new QLabel(layoutWidget);
        label_18->setObjectName(QStringLiteral("label_18"));

        verticalLayout->addWidget(label_18);

        layoutWidget1 = new QWidget(FurnitureOverviewPage);
        layoutWidget1->setObjectName(QStringLiteral("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(100, 60, 591, 22));
        horizontalLayout = new QHBoxLayout(layoutWidget1);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        label_2 = new QLabel(layoutWidget1);
        label_2->setObjectName(QStringLiteral("label_2"));

        horizontalLayout->addWidget(label_2);

        horizontalSpacer_7 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_7);

        label_3 = new QLabel(layoutWidget1);
        label_3->setObjectName(QStringLiteral("label_3"));

        horizontalLayout->addWidget(label_3);

        horizontalSpacer_8 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_8);

        label_4 = new QLabel(layoutWidget1);
        label_4->setObjectName(QStringLiteral("label_4"));

        horizontalLayout->addWidget(label_4);

        layoutWidget2 = new QWidget(FurnitureOverviewPage);
        layoutWidget2->setObjectName(QStringLiteral("layoutWidget2"));
        layoutWidget2->setGeometry(QRect(90, 100, 611, 31));
        horizontalLayout_2 = new QHBoxLayout(layoutWidget2);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        lcdNumber = new QLCDNumber(layoutWidget2);
        lcdNumber->setObjectName(QStringLiteral("lcdNumber"));

        horizontalLayout_2->addWidget(lcdNumber);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);

        lcdNumber_2 = new QLCDNumber(layoutWidget2);
        lcdNumber_2->setObjectName(QStringLiteral("lcdNumber_2"));

        horizontalLayout_2->addWidget(lcdNumber_2);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_2);

        lcdNumber_3 = new QLCDNumber(layoutWidget2);
        lcdNumber_3->setObjectName(QStringLiteral("lcdNumber_3"));

        horizontalLayout_2->addWidget(lcdNumber_3);

        layoutWidget3 = new QWidget(FurnitureOverviewPage);
        layoutWidget3->setObjectName(QStringLiteral("layoutWidget3"));
        layoutWidget3->setGeometry(QRect(100, 130, 591, 22));
        horizontalLayout_3 = new QHBoxLayout(layoutWidget3);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        label_12 = new QLabel(layoutWidget3);
        label_12->setObjectName(QStringLiteral("label_12"));

        horizontalLayout_3->addWidget(label_12);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_3);

        label_13 = new QLabel(layoutWidget3);
        label_13->setObjectName(QStringLiteral("label_13"));

        horizontalLayout_3->addWidget(label_13);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_4);

        label_14 = new QLabel(layoutWidget3);
        label_14->setObjectName(QStringLiteral("label_14"));

        horizontalLayout_3->addWidget(label_14);

        layoutWidget4 = new QWidget(FurnitureOverviewPage);
        layoutWidget4->setObjectName(QStringLiteral("layoutWidget4"));
        layoutWidget4->setGeometry(QRect(100, 150, 591, 31));
        horizontalLayout_4 = new QHBoxLayout(layoutWidget4);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        horizontalLayout_4->setContentsMargins(0, 0, 0, 0);
        timeEdit = new QTimeEdit(layoutWidget4);
        timeEdit->setObjectName(QStringLiteral("timeEdit"));

        horizontalLayout_4->addWidget(timeEdit);

        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_5);

        timeEdit_2 = new QTimeEdit(layoutWidget4);
        timeEdit_2->setObjectName(QStringLiteral("timeEdit_2"));

        horizontalLayout_4->addWidget(timeEdit_2);

        horizontalSpacer_6 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_6);

        timeEdit_3 = new QTimeEdit(layoutWidget4);
        timeEdit_3->setObjectName(QStringLiteral("timeEdit_3"));

        horizontalLayout_4->addWidget(timeEdit_3);

        layoutWidget5 = new QWidget(FurnitureOverviewPage);
        layoutWidget5->setObjectName(QStringLiteral("layoutWidget5"));
        layoutWidget5->setGeometry(QRect(100, 80, 591, 22));
        horizontalLayout_5 = new QHBoxLayout(layoutWidget5);
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        horizontalLayout_5->setContentsMargins(0, 0, 0, 0);
        pushButton = new QPushButton(layoutWidget5);
        pushButton->setObjectName(QStringLiteral("pushButton"));

        horizontalLayout_5->addWidget(pushButton);

        horizontalSpacer_9 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_9);

        pushButton_2 = new QPushButton(layoutWidget5);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));

        horizontalLayout_5->addWidget(pushButton_2);

        horizontalSpacer_10 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_10);

        pushButton_3 = new QPushButton(layoutWidget5);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));

        horizontalLayout_5->addWidget(pushButton_3);

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

        tabWidget->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(TabWidget);
    } // setupUi

    void retranslateUi(QWidget *TabWidget)
    {
        TabWidget->setWindowTitle(QApplication::translate("TabWidget", "Form", Q_NULLPTR));
        label_5->setText(QApplication::translate("TabWidget", "\347\201\257", Q_NULLPTR));
        label_6->setText(QApplication::translate("TabWidget", "\345\256\242\345\216\205\347\201\257", Q_NULLPTR));
        label_7->setText(QApplication::translate("TabWidget", "\344\270\273\345\215\247\347\201\257", Q_NULLPTR));
        label_8->setText(QApplication::translate("TabWidget", "\346\254\241\345\215\247\347\201\257", Q_NULLPTR));
        label_9->setText(QApplication::translate("TabWidget", "\345\212\240\346\271\277\345\231\250\357\274\232", Q_NULLPTR));
        label_10->setText(QApplication::translate("TabWidget", "\345\256\242\345\216\205\345\212\240\346\271\277\345\231\250", Q_NULLPTR));
        label_11->setText(QApplication::translate("TabWidget", "\344\270\273\345\215\247\345\212\240\346\271\277\345\231\250", Q_NULLPTR));
        label_19->setText(QApplication::translate("TabWidget", "\346\250\241\345\274\217\351\200\211\346\213\251\357\274\232", Q_NULLPTR));
        pushButton_4->setText(QApplication::translate("TabWidget", "PushButton", Q_NULLPTR));
        pushButton_5->setText(QApplication::translate("TabWidget", "PushButton", Q_NULLPTR));
        label->setText(QApplication::translate("TabWidget", "\347\251\272\350\260\203\346\216\247\345\210\266", Q_NULLPTR));
        label_15->setText(QApplication::translate("TabWidget", "\347\251\272\350\260\203\345\220\215\347\247\260\357\274\232", Q_NULLPTR));
        label_20->setText(QApplication::translate("TabWidget", "\347\251\272\350\260\203\345\274\200\345\205\263\357\274\232", Q_NULLPTR));
        label_16->setText(QApplication::translate("TabWidget", "\347\251\272\350\260\203\346\270\251\345\272\246\357\274\232", Q_NULLPTR));
        label_17->setText(QApplication::translate("TabWidget", "\347\251\272\350\260\203\346\250\241\345\274\217\357\274\232", Q_NULLPTR));
        label_18->setText(QApplication::translate("TabWidget", "\347\251\272\350\260\203\350\207\252\345\212\250\345\256\232\346\227\266\357\274\232", Q_NULLPTR));
        label_2->setText(QApplication::translate("TabWidget", "\345\256\242\345\216\205\347\251\272\350\260\203", Q_NULLPTR));
        label_3->setText(QApplication::translate("TabWidget", "\344\270\273\345\215\247\347\251\272\350\260\203", Q_NULLPTR));
        label_4->setText(QApplication::translate("TabWidget", "\346\254\241\345\215\247\347\251\272\350\260\203", Q_NULLPTR));
        label_12->setText(QApplication::translate("TabWidget", "TextLabel", Q_NULLPTR));
        label_13->setText(QApplication::translate("TabWidget", "TextLabel", Q_NULLPTR));
        label_14->setText(QApplication::translate("TabWidget", "TextLabel", Q_NULLPTR));
        pushButton->setText(QApplication::translate("TabWidget", "PushButton", Q_NULLPTR));
        pushButton_2->setText(QApplication::translate("TabWidget", "PushButton", Q_NULLPTR));
        pushButton_3->setText(QApplication::translate("TabWidget", "PushButton", Q_NULLPTR));
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
