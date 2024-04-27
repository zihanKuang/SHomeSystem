/********************************************************************************
** Form generated from reading UI file 'datawidget.ui'
**
** Created by: Qt User Interface Compiler version 5.9.7
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DATAWIDGET_H
#define UI_DATAWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_DataWidget
{
public:

    void setupUi(QWidget *DataWidget)
    {
        if (DataWidget->objectName().isEmpty())
            DataWidget->setObjectName(QStringLiteral("DataWidget"));
        DataWidget->resize(900, 900);

        retranslateUi(DataWidget);

        QMetaObject::connectSlotsByName(DataWidget);
    } // setupUi

    void retranslateUi(QWidget *DataWidget)
    {
        DataWidget->setWindowTitle(QApplication::translate("DataWidget", "Form", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class DataWidget: public Ui_DataWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DATAWIDGET_H
