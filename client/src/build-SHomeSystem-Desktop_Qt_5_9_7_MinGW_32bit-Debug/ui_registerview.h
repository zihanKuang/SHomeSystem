/********************************************************************************
** Form generated from reading UI file 'registerview.ui'
**
** Created by: Qt User Interface Compiler version 5.9.7
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_REGISTERVIEW_H
#define UI_REGISTERVIEW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_RegisterView
{
public:
    QLabel *nameLable;
    QLabel *pwdLable;
    QLineEdit *pwdEdit;
    QLineEdit *nameEdit;
    QPushButton *registerButton;
    QLabel *rePwdLable;
    QLineEdit *rePwdEdit;

    void setupUi(QWidget *RegisterView)
    {
        if (RegisterView->objectName().isEmpty())
            RegisterView->setObjectName(QStringLiteral("RegisterView"));
        RegisterView->resize(214, 161);
        nameLable = new QLabel(RegisterView);
        nameLable->setObjectName(QStringLiteral("nameLable"));
        nameLable->setGeometry(QRect(30, 30, 41, 9));
        pwdLable = new QLabel(RegisterView);
        pwdLable->setObjectName(QStringLiteral("pwdLable"));
        pwdLable->setGeometry(QRect(30, 59, 41, 20));
        pwdEdit = new QLineEdit(RegisterView);
        pwdEdit->setObjectName(QStringLiteral("pwdEdit"));
        pwdEdit->setGeometry(QRect(80, 60, 113, 20));
        nameEdit = new QLineEdit(RegisterView);
        nameEdit->setObjectName(QStringLiteral("nameEdit"));
        nameEdit->setGeometry(QRect(80, 30, 113, 20));
        registerButton = new QPushButton(RegisterView);
        registerButton->setObjectName(QStringLiteral("registerButton"));
        registerButton->setGeometry(QRect(60, 120, 80, 15));
        rePwdLable = new QLabel(RegisterView);
        rePwdLable->setObjectName(QStringLiteral("rePwdLable"));
        rePwdLable->setGeometry(QRect(30, 100, 41, 9));
        rePwdEdit = new QLineEdit(RegisterView);
        rePwdEdit->setObjectName(QStringLiteral("rePwdEdit"));
        rePwdEdit->setGeometry(QRect(80, 90, 113, 20));

        retranslateUi(RegisterView);

        QMetaObject::connectSlotsByName(RegisterView);
    } // setupUi

    void retranslateUi(QWidget *RegisterView)
    {
        RegisterView->setWindowTitle(QApplication::translate("RegisterView", "Form", Q_NULLPTR));
        nameLable->setText(QApplication::translate("RegisterView", "\347\224\250\346\210\267\345\220\215\357\274\232", Q_NULLPTR));
        pwdLable->setText(QApplication::translate("RegisterView", "\345\257\206\347\240\201\357\274\232", Q_NULLPTR));
        registerButton->setText(QApplication::translate("RegisterView", "\346\263\250\345\206\214", Q_NULLPTR));
        rePwdLable->setText(QApplication::translate("RegisterView", "\347\241\256\350\256\244\345\257\206\347\240\201\357\274\232", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class RegisterView: public Ui_RegisterView {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_REGISTERVIEW_H
