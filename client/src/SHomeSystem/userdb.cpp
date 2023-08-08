#include "userdb.h"
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QDebug>

UserDB::UserDB()
{
}


UserDB::~UserDB()
{
}

bool UserDB::openDatabase(const QString& databaseName)
{
    // 连接数据库
    m_database = QSqlDatabase::addDatabase("QSQLITE");
    // 设置数据库文件名
    m_database.setDatabaseName(databaseName);

    if (!m_database.open())
    {
        qDebug() << "打开数据库失败" << m_database.lastError().text();
        return false;
    }

    return true;
}

void UserDB::closeDatabase()
{
    // 关闭数据库连接
    m_database.close();
}

// 检查用户名是否唯一
bool UserDB::isUsernameUnique(const QString& username)
{
    QSqlQuery query;
    //用于查询users表中满足条件username = ?的记录数量
    //?是一个占位符
    query.prepare("SELECT COUNT(*) FROM UserData WHERE username = ?");
    //使用addBindValue()函数将username的值绑定到占位符?上
    query.addBindValue(username);

    // 执行查询
    if (!query.exec())
    {
        qDebug() << "isUsernameUnique处理命令错误" << query.lastError().text();
        return false;
    }

    // 获取查询结果
    if (query.next())
    {
        // 获取满足条件的记录数量
        int count = query.value(0).toInt();
        return count == 0;
    }

    return false;
}

// 保存用户注册信息
bool UserDB::saveUser(const QString& username, const QString& password)
{
    QSqlQuery query;
    query.prepare("INSERT INTO UserData (username, password) VALUES (?, ?)");
    //将用户名绑定到第一个占位符？
    query.addBindValue(username);
    //第二个？
    query.addBindValue(password);

    // 执行插入操作
    if (!query.exec())
    {
        qDebug() << "saveUser处理命令错误" << query.lastError().text();
        return false;
    }

    return true;
}

// 获取用户信息
bool UserDB::getUser(const QString& username, QString& password)
{
    QSqlQuery query;
    query.prepare("SELECT password FROM UserData WHERE username = ?");
    query.addBindValue(username);

    if (!query.exec())
    {
        qDebug() << "getUser处理命令错误" << query.lastError().text();
        return false;
    }

    if (query.next())
    {
        password = query.value(0).toString();
        return true;
    }

    return false;
}

