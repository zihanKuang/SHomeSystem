#include "CommunicationInterface.h"
#include <QJsonDocument>
#include <QJsonObject>
#include <QDebug>

CommunicationInterface::CommunicationInterface(QObject *parent)
    : QObject(parent)
{
}

void CommunicationInterface::handleRequest(const QJsonObject &requestData)
{
    // 获取请求类型，根据不同的请求类型进行处理
    QString requestType = requestData.value("type").toString();

    if (requestType == "login") {
        // 处理登录请求
        QString username = requestData.value("username").toString();
        QString password = requestData.value("password").toString();
        bool isValid = validateUser(username, password);
        emit userValidated(isValid);
    } else if (requestType == "dataExchange") {
        // 处理数据交换请求
        QVariantMap data = deserializeFromJson(requestData);
        // 实际应用中，这里可以处理接收到的数据并作出相应响应
        // ...
    } else {
        // 未知的请求类型，处理异常
        handleException("Unknown request type");
    }
}

bool CommunicationInterface::validateUser(const QString &username, const QString &password)
{
    // 实际应用中，这里可以进行用户验证，例如查询数据库等
    // 这里为演示直接验证用户名和密码是否为"admin"
    return (username == "admin" && password == "admin");
}

QJsonObject CommunicationInterface::serializeToJson(const QVariantMap &data)
{
    // 实际应用中，这里可以将 QVariantMap 数据转换为 QJsonObject
    // 这里为演示直接将 QVariantMap 数据作为 QJsonObject 返回
    return QJsonObject::fromVariantMap(data);
}

QVariantMap CommunicationInterface::deserializeFromJson(const QJsonObject &jsonData)
{
    // 实际应用中，这里可以将 QJsonObject 数据转换为 QVariantMap
    // 这里为演示直接将 QJsonObject 数据作为 QVariantMap 返回
    return jsonData.toVariantMap();
}

void CommunicationInterface::handleException(const QString &errorMessage)
{
    // 处理网络错误等异常情况，可以打印错误信息或者通知上层处理
    qDebug() << "Error: " << errorMessage;
}
