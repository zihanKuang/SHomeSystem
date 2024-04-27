#include "loginview.h"
#include "ui_loginview.h"


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
    QUrl url("http://127.0.0.1:8080/user/login");
    QUrlQuery query;
    query.addQueryItem("username", username);
    query.addQueryItem("password", password);
    url.setQuery(query);

    QNetworkRequest request(url);
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");

    // 发送HTTP GET请求（将数据作为URL参数）
    QNetworkReply *reply = manager->get(request);

    // 连接信号和槽，处理服务器的响应
    connect(reply, &QNetworkReply::finished, this, [this, reply]() {

        if (reply->error() == QNetworkReply::NoError) {

            // 请求成功，解析服务器响应的JSON数据并进行处理
            QByteArray responseData = reply->readAll();
            QJsonDocument jsonResponse = QJsonDocument::fromJson(responseData);

            if (!jsonResponse.isNull() && jsonResponse.isObject()) {
                QJsonObject jsonObject = jsonResponse.object();
                bool isSuccess = jsonObject.value("success").toBool();
                QString message = jsonObject.value("message").toString();

                if (isSuccess) {
                    // 登录成功
                    qDebug() << "Login successful:" << message;
                    QMessageBox::information(this, "Login successfully", "登陆成功！");
                } else {
                    // 登录失败
                    qDebug() << "Login failed:" << message;
                    QMessageBox::warning(this, "Login failed", "登陆失败！");
                }
            }
        } else {
            // 请求失败
            qDebug() << "Login failed:" << reply->errorString();
            // 在这里进行请求失败后的相关处理，例如显示错误提示
            QMessageBox::warning(this, "Login failed", "网络错误");
        }

        reply->deleteLater();
    });
}

void LoginView::onLoginButtonClicked()
{
    // 首先验证输入是否有效
    if (!validateInput())
    {
        // 输入无效，显示错误信息给用户
        QMessageBox::warning(this, "错误", "请输入有效的用户名和密码！");
        return;
    }

    // 获取用户名和密码
    QString username = ui->nameEdit->text().trimmed();
    QString password = ui->pwdEdit->text();

    // 调用登录接口进行用户验证
    callLoginAPI(username, password);
}

