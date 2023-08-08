#include "userdb.h"
#include <QSqlQuery>
#include <QSqlError>
#include <QDebug>

UserDB::UserDB()
{
}

bool UserDB::openDatabase(const QString& databaseName)
{
    // 尝试连接数据库
    m_database = QSqlDatabase::addDatabase("QSQLITE");
    m_database.setDatabaseName(databaseName);

    if (!m_database.open())
    {
        qDebug() << "Error opening database:" << m_database.lastError().text();
        return false;
    }

    return true;
}

void UserDB::closeDatabase()
{
    // 关闭数据库连接
    m_database.close();
}

bool UserDB::isUsernameUnique(const QString& username)
{
    QSqlQuery query;
    query.prepare("SELECT COUNT(*) FROM users WHERE username = ?");
    query.addBindValue(username);

    if (!query.exec())
    {
        qDebug() << "Error executing query:" << query.lastError().text();
        return false;
    }

    if (query.next())
    {
        int count = query.value(0).toInt();
        return count == 0;
    }

    return false;
}

bool UserDB::saveUser(const QString& username, const QString& password)
{
    QSqlQuery query;
    query.prepare("INSERT INTO users (username, password) VALUES (?, ?)");
    query.addBindValue(username);
    query.addBindValue(password);

    if (!query.exec())
    {
        qDebug() << "Error executing query:" << query.lastError().text();
        return false;
    }

    return true;
}

bool UserDB::getUser(const QString& username, QString& password)
{
    QSqlQuery query;
    query.prepare("SELECT password FROM users WHERE username = ?");
    query.addBindValue(username);

    if (!query.exec())
    {
        qDebug() << "Error executing query:" << query.lastError().text();
        return false;
    }

    if (query.next())
    {
        password = query.value(0).toString();
        return true;
    }

    return false;
}

