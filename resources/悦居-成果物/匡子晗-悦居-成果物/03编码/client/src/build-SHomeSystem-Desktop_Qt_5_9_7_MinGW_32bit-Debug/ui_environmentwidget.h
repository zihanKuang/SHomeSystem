/********************************************************************************
** Form generated from reading UI file 'environmentwidget.ui'
**
** Created by: Qt User Interface Compiler version 5.9.7
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ENVIRONMENTWIDGET_H
#define UI_ENVIRONMENTWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_EnvirmentWidget
{
public:

    void setupUi(QWidget *EnvirmentWidget)
    {
        if (EnvirmentWidget->objectName().isEmpty())
            EnvirmentWidget->setObjectName(QStringLiteral("EnvirmentWidget"));
        EnvirmentWidget->resize(734, 593);

        retranslateUi(EnvirmentWidget);

        QMetaObject::connectSlotsByName(EnvirmentWidget);
    } // setupUi

    void retranslateUi(QWidget *EnvirmentWidget)
    {
        EnvirmentWidget->setWindowTitle(QApplication::translate("EnvirmentWidget", "Form", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class EnvirmentWidget: public Ui_EnvirmentWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ENVIRONMENTWIDGET_H
