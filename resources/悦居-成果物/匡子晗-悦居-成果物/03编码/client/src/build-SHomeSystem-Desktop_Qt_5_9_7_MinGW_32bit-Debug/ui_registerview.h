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
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_RegisterView
{
public:
    QLabel *title;
    QWidget *widget;
    QVBoxLayout *verticalLayout;
    QFormLayout *formLayout;
    QLabel *nameLable;
    QLineEdit *nameEdit;
    QLabel *pwdLable;
    QLineEdit *pwdEdit;
    QLabel *rePwdLable;
    QLineEdit *rePwdEdit;
    QPushButton *registerButton;

    void setupUi(QWidget *RegisterView)
    {
        if (RegisterView->objectName().isEmpty())
            RegisterView->setObjectName(QStringLiteral("RegisterView"));
        RegisterView->resize(500, 500);
        title = new QLabel(RegisterView);
        title->setObjectName(QStringLiteral("title"));
        title->setGeometry(QRect(220, 170, 71, 31));
        widget = new QWidget(RegisterView);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(80, 210, 341, 151));
        verticalLayout = new QVBoxLayout(widget);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        formLayout = new QFormLayout();
        formLayout->setObjectName(QStringLiteral("formLayout"));
        nameLable = new QLabel(widget);
        nameLable->setObjectName(QStringLiteral("nameLable"));

        formLayout->setWidget(0, QFormLayout::LabelRole, nameLable);

        nameEdit = new QLineEdit(widget);
        nameEdit->setObjectName(QStringLiteral("nameEdit"));

        formLayout->setWidget(0, QFormLayout::FieldRole, nameEdit);

        pwdLable = new QLabel(widget);
        pwdLable->setObjectName(QStringLiteral("pwdLable"));

        formLayout->setWidget(1, QFormLayout::LabelRole, pwdLable);

        pwdEdit = new QLineEdit(widget);
        pwdEdit->setObjectName(QStringLiteral("pwdEdit"));

        formLayout->setWidget(1, QFormLayout::FieldRole, pwdEdit);

        rePwdLable = new QLabel(widget);
        rePwdLable->setObjectName(QStringLiteral("rePwdLable"));

        formLayout->setWidget(2, QFormLayout::LabelRole, rePwdLable);

        rePwdEdit = new QLineEdit(widget);
        rePwdEdit->setObjectName(QStringLiteral("rePwdEdit"));

        formLayout->setWidget(2, QFormLayout::FieldRole, rePwdEdit);


        verticalLayout->addLayout(formLayout);

        registerButton = new QPushButton(widget);
        registerButton->setObjectName(QStringLiteral("registerButton"));

        verticalLayout->addWidget(registerButton);


        retranslateUi(RegisterView);

        QMetaObject::connectSlotsByName(RegisterView);
    } // setupUi

    void retranslateUi(QWidget *RegisterView)
    {
        RegisterView->setWindowTitle(QApplication::translate("RegisterView", "Form", Q_NULLPTR));
        title->setText(QApplication::translate("RegisterView", "\346\263\250\345\206\214\351\241\265\351\235\242", Q_NULLPTR));
        nameLable->setText(QApplication::translate("RegisterView", "\347\224\250\346\210\267\345\220\215\357\274\232", Q_NULLPTR));
        pwdLable->setText(QApplication::translate("RegisterView", "\345\257\206\347\240\201\357\274\232", Q_NULLPTR));
        rePwdLable->setText(QApplication::translate("RegisterView", "\347\241\256\350\256\244\345\257\206\347\240\201\357\274\232", Q_NULLPTR));
        registerButton->setText(QApplication::translate("RegisterView", "\346\263\250\345\206\214", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class RegisterView: public Ui_RegisterView {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_REGISTERVIEW_H
