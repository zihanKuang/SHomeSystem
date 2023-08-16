#include "registerview.h"
#include "ui_registerview.h"

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
    // 首先验证输入是否有效
    if (!validateInput())
    {
        // 输入无效，显示错误信息给用户
        QMessageBox::warning(this, "错误", "请输入有效的用户名和密码！");
        return;
    }

    // 输入有效，调用注册接口
    callRegisterAPI();
}

// 在客户端中调用UserDB的saveUser()函数
void RegisterView::callRegisterAPI()
{
    QString username = ui->nameEdit->text().trimmed();
    QString password = ui->pwdEdit->text();

    // 创建QNetworkAccessManager对象
    QNetworkAccessManager *manager = new QNetworkAccessManager(this);

    // 构建HTTP请求
    QUrl url("http://127.0.0.1:8080/user/register/");
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
                    // 注册成功
                    qDebug() << "Registration successful:" << message;
                    QMessageBox::information(this, "Registration successful", "注册成功");
                } else {
                    // 注册失败
                    qDebug() << "Registration failed:" << message;
                    QMessageBox::warning(this, "Registration failed", "注册失败");
                }
            }
        } else {
            // 请求失败
            qDebug() << "Registration failed:" << reply->errorString();
            QMessageBox::warning(this, "Registration failed", "网络错误，请稍后再试！");
        }
        reply->deleteLater();
    });
}

