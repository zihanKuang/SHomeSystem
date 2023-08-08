#include "registerview.h"
#include "ui_registerview.h"
#include <QtDebug>
#include <QMessageBox>
#include <QtNetwork>

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

// 在客户端中调用UserDB的saveUser()函数
void RegisterView::callRegisterAPI()
{
    QString name = ui->nameEdit->text().trimmed();
    QString password = ui->pwdEdit->text();

    // 创建QNetworkAccessManager对象
    QNetworkAccessManager *manager = new QNetworkAccessManager(this);

    // 构建HTTP请求
    QNetworkRequest request(QUrl("http://your_server_url/user/register"));
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/x-www-form-urlencoded");

    // 构建请求参数
    QByteArray postData;
    postData.append("username=" + name);
    postData.append("&password=" + password);

    // 发送HTTP POST请求
    QNetworkReply *reply = manager->post(request, postData);

    // 连接信号和槽，处理服务器的响应
    connect(reply, &QNetworkReply::finished, this, [reply]() {
        if (reply->error() == QNetworkReply::NoError) {
            // 请求成功，解析服务器响应的JSON数据并进行处理
            QByteArray responseData = reply->readAll();
            // 解析JSON数据并处理
            // 例如检查注册是否成功，弹出相应的提示框等
        } else {
            // 请求失败
            qDebug() << "Registration failed:" << reply->errorString();
        }
        reply->deleteLater();
    });
}

