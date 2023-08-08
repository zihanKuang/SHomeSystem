/********************************************************************************
** Form generated from reading UI file 'loginview.ui'
**
** Created by: Qt User Interface Compiler version 5.9.7
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGINVIEW_H
#define UI_LOGINVIEW_H

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

class Ui_LoginView
{
public:
    QLabel *nameLabel;
    QLabel *pwdLabel;
    QLineEdit *nameEdit;
    QLineEdit *pwdEdit;
    QPushButton *loginButton;

    void setupUi(QWidget *LoginView)
    {
        if (LoginView->objectName().isEmpty())
            LoginView->setObjectName(QStringLiteral("LoginView"));
        LoginView->resize(223, 119);
        nameLabel = new QLabel(LoginView);
        nameLabel->setObjectName(QStringLiteral("nameLabel"));
        nameLabel->setGeometry(QRect(30, 20, 41, 9));
        pwdLabel = new QLabel(LoginView);
        pwdLabel->setObjectName(QStringLiteral("pwdLabel"));
        pwdLabel->setGeometry(QRect(30, 49, 41, 20));
        nameEdit = new QLineEdit(LoginView);
        nameEdit->setObjectName(QStringLiteral("nameEdit"));
        nameEdit->setGeometry(QRect(80, 20, 113, 20));
        pwdEdit = new QLineEdit(LoginView);
        pwdEdit->setObjectName(QStringLiteral("pwdEdit"));
        pwdEdit->setGeometry(QRect(80, 50, 113, 20));
        loginButton = new QPushButton(LoginView);
        loginButton->setObjectName(QStringLiteral("loginButton"));
        loginButton->setGeometry(QRect(70, 90, 80, 15));

        retranslateUi(LoginView);

        QMetaObject::connectSlotsByName(LoginView);
    } // setupUi

    void retranslateUi(QWidget *LoginView)
    {
        LoginView->setWindowTitle(QApplication::translate("LoginView", "Form", Q_NULLPTR));
        nameLabel->setText(QApplication::translate("LoginView", "\347\224\250\346\210\267\345\220\215\357\274\232", Q_NULLPTR));
        pwdLabel->setText(QApplication::translate("LoginView", "\345\257\206\347\240\201\357\274\232", Q_NULLPTR));
        loginButton->setText(QApplication::translate("LoginView", "\347\231\273\345\275\225", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class LoginView: public Ui_LoginView {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGINVIEW_H
