#include "loginview.h"
#include "ui_loginview.h"
#include <QMessageBox>

LoginView::LoginView(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::LoginView)
{
    ui->setupUi(this);

    // 连接登录按钮的点击信号到 onLoginButtonClicked 槽
    connect(ui->loginButton, &QPushButton::clicked, this, &LoginView::onLoginButtonClicked);
}

LoginView::~LoginView()
{
    delete ui;
}

// 验证用户登录输入信息的实现
bool LoginView::validateInput()
{
    // 获取用户名和密码输入
    QString name = ui->nameEdit->text().trimmed();
    QString password = ui->pwdEdit->text();

    // 检查用户名和密码是否为空
    if (name.isEmpty() || password.isEmpty())
    {
        QMessageBox::warning(this, "错误", "用户名和密码不能为空！");
        return false;
    }

    return true;
}

// 调用后端HTTP API登录接口的实现
void LoginView::callLoginAPI()
{
    // 调用后端HTTP API登录接口，传递用户名和密码

    // 登录成功，发送登录成功信号
    emit loginSuccessful();
}

void LoginView::onLoginButtonClicked()
{
    // 校验输入
    if (validateInput())
    {
        // 如果输入验证通过，调用登录接口
        callLoginAPI();
    }
}
