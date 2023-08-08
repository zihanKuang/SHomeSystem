#include "registerview.h"
#include "ui_registerview.h"
#include <QtDebug>
#include <QMessageBox>

RegisterView::RegisterView(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::RegisterView)
{
    ui->setupUi(this);

    connect(ui->registerButton, &QPushButton::clicked, this, &RegisterView::onRegisterButtonClicked);
}

RegisterView::~RegisterView()
{
    delete ui;
}

bool RegisterView::validateInput()
{
    // 获取用户名和密码
    QString name = ui->nameEdit->text().trimmed();
    QString password = ui->pwdEdit->text();
    QString confirmPassword = ui->rePwdEdit->text();

    // 验证用户名和密码不能为空
        if (name.isEmpty() || password.isEmpty())
        {
            QMessageBox::warning(this, "错误", "用户名和密码不能为空！");
            return false;
        }

        // 验证用户名格式是否符合规范
        // 用户名可以包含英文字母（大小写均可）或中文字符
        // 用户名可以包含数字和下划线
        // 用户名不得包含空格
        QRegExp nameRegExp("^[A-Za-z\\u4e00-\\u9fa5\\d_]+$");
        if (!nameRegExp.exactMatch(name))
        {
            // 用户名格式不符合规范，显示错误信息给用户
            QMessageBox::warning(this, "错误", "用户名格式不符合规范！");
            return false;
        }

        // 验证密码和确认密码是否一致
        if (password != confirmPassword)
        {
            // 密码和确认密码不一致，显示错误信息给用户
            QMessageBox::warning(this, "错误", "确认密码与密码不同！");
            return false;
        }

        //检查用户名是否唯一

        //UserDatabase::isUsernameUnique(const QString& username);

        return true;
    }


// 在用户点击注册按钮时执行的槽函数
void RegisterView::onRegisterButtonClicked()
{
    // 首先验证输入是否有效
    if (!validateInput())
    {
        // 输入无效，显示错误信息给用户
        // 处理无效输入的代码




        //...
        return;
    }

    // 输入有效，调用注册接口
    callRegisterAPI();
}

void RegisterView::callRegisterAPI()
{
    // 调用后端注册接口的逻辑
    // 实际调用后端注册接口的代码，并处理后端的响应

    QString name = ui->nameEdit->text().trimmed();
    QString password = ui->pwdEdit->text();

    qDebug() << "Registering user with name: " << name << " and password: " << password;
}
