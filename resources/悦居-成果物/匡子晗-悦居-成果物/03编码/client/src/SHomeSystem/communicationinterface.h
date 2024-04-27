#ifndef COMMUNICATIONINTERFACE_H
#define COMMUNICATIONINTERFACE_H

#include <QObject>

class CommunicationInterface : public QObject
{
    Q_OBJECT
public:
    explicit CommunicationInterface(QObject *parent = nullptr);

signals:
    // 用户验证信号，用于通知业务层用户身份验证结果
    void userValidated(bool isValid);

    // 数据交换信号，用于通知业务层接收到的数据
    void dataReceived(const QJsonObject &jsonData);

public slots:
    // 处理客户端HTTP请求，包括用户验证和数据交换
    void handleRequest(const QJsonObject &requestData);

private:
    // 验证用户身份是否合法，确保请求来自合法的用户
    bool validateUser(const QString &username, const QString &password);

    // 将对象数据序列化为JSON格式，方便在网络中传输数据
    QJsonObject serializeToJson(const QVariantMap &data);

    // 将JSON反序列化为对象，方便在服务器端处理请求
    QVariantMap deserializeFromJson(const QJsonObject &jsonData);

    // 处理网络错误等异常情况，确保系统稳定性和安全性
    void handleException(const QString &errorMessage);
};

#endif // COMMUNICATIONINTERFACE_H
