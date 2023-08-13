#ifndef USERDB_H
#define USERDB_H

#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlQuery>
#include <QString>

class UserDB
{
public:
    UserDB();
    ~UserDB();

    // 打开数据库
    bool openDatabase(const QString& databaseName);
    // 关闭数据库
    void closeDatabase();
    // 检查用户名是否唯一
    bool isUsernameUnique(const QString& username);
    // 保存用户注册信息
    bool saveUser(const QString& username, const QString& password);
    // 获取用户信息
    bool getUser(const QString& username, QString& password);

private:
    QSqlDatabase m_database;
};

#endif // USERDB_H
