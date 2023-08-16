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
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_LoginView
{
public:
    QLabel *title;
    QWidget *widget;
    QVBoxLayout *verticalLayout;
    QFormLayout *formLayout;
    QLabel *nameLabel;
    QLineEdit *nameEdit;
    QLabel *pwdLabel;
    QLineEdit *pwdEdit;
    QPushButton *loginButton;

    void setupUi(QWidget *LoginView)
    {
        if (LoginView->objectName().isEmpty())
            LoginView->setObjectName(QStringLiteral("LoginView"));
        LoginView->resize(500, 500);
        title = new QLabel(LoginView);
        title->setObjectName(QStringLiteral("title"));
        title->setGeometry(QRect(210, 190, 91, 41));
        widget = new QWidget(LoginView);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(60, 240, 341, 111));
        verticalLayout = new QVBoxLayout(widget);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        formLayout = new QFormLayout();
        formLayout->setObjectName(QStringLiteral("formLayout"));
        nameLabel = new QLabel(widget);
        nameLabel->setObjectName(QStringLiteral("nameLabel"));

        formLayout->setWidget(0, QFormLayout::LabelRole, nameLabel);

        nameEdit = new QLineEdit(widget);
        nameEdit->setObjectName(QStringLiteral("nameEdit"));

        formLayout->setWidget(0, QFormLayout::FieldRole, nameEdit);

        pwdLabel = new QLabel(widget);
        pwdLabel->setObjectName(QStringLiteral("pwdLabel"));

        formLayout->setWidget(1, QFormLayout::LabelRole, pwdLabel);

        pwdEdit = new QLineEdit(widget);
        pwdEdit->setObjectName(QStringLiteral("pwdEdit"));

        formLayout->setWidget(1, QFormLayout::FieldRole, pwdEdit);


        verticalLayout->addLayout(formLayout);

        loginButton = new QPushButton(widget);
        loginButton->setObjectName(QStringLiteral("loginButton"));

        verticalLayout->addWidget(loginButton);


        retranslateUi(LoginView);

        QMetaObject::connectSlotsByName(LoginView);
    } // setupUi

    void retranslateUi(QWidget *LoginView)
    {
        LoginView->setWindowTitle(QApplication::translate("LoginView", "Form", Q_NULLPTR));
        title->setText(QApplication::translate("LoginView", "\347\231\273\345\275\225\351\241\265\351\235\242", Q_NULLPTR));
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
