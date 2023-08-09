#include "loginview.h"
#include "ui_loginview.h"
#include <QtNetwork>
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
void LoginView::callLoginAPI(const QString& username, const QString& password)
{
    // 创建QNetworkAccessManager对象
    QNetworkAccessManager *manager = new QNetworkAccessManager(this);

    // 构建HTTP请求
    QNetworkRequest request(QUrl("http://127.0.0.1:8080/user/login"));
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/x-www-form-urlencoded");

    // 构建请求参数
    QByteArray postData;
    postData.append("username=" + username);
    postData.append("&password=" + password);

    // 发送HTTP POST请求
    QNetworkReply *reply = manager->post(request, postData);

    // 连接信号和槽，处理服务器的响应
    connect(reply, &QNetworkReply::finished, this, [=]() {
        if (reply->error() == QNetworkReply::NoError) {
            // 请求成功，解析服务器响应的JSON数据并进行处理
            QByteArray responseData = reply->readAll();
            // 解析JSON数据并处理
            // 例如检查登录是否成功，处理用户信息等

            // 假设服务器返回的JSON数据格式如下：
            // {
            //     "success": true,
            //     "message": "登录成功",
            //     "data": {
            //         // 用户信息等数据
            //     }
            // }

            QJsonDocument jsonResponse = QJsonDocument::fromJson(responseData);
            QJsonObject jsonObject = jsonResponse.object();
            bool isSuccess = jsonObject.value("success").toBool();
            QString message = jsonObject.value("message").toString();

            if (isSuccess) {
                // 登录成功
                qDebug() << "Login successful:" << message;
                // 在这里进行登录成功后的相关处理，例如显示登录成功提示，更新用户信息等
                // emit loginSuccessful();
                QMessageBox::information(this, "登录成功", message);
            } else {
                // 登录失败
                qDebug() << "Login failed:" << message;
                // 在这里进行登录失败后的相关处理，例如显示登录失败提示
                QMessageBox::warning(this, "登录失败", message);
            }
        } else {
            // 请求失败
            qDebug() << "Login failed:" << reply->errorString();
            // 在这里进行请求失败后的相关处理，例如显示错误提示
            QMessageBox::warning(this, "登录失败", "网络错误，请稍后再试！");
        }
        reply->deleteLater();
    });
}


void LoginView::onLoginButtonClicked()
{
    // 获取用户名和密码
    QString username = ui->nameEdit->text().trimmed();
    QString password = ui->pwdEdit->text();

    // 调用登录接口进行用户验证
    callLoginAPI(username, password);
}
