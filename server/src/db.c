// db.c - 数据惯例模块的实现

#include "db.h" // 包含数据惯例模块的头文件
#include <sqlite3.h>
#include <stdio.h>
#include <stdbool.h>

// 数据库连接句柄
sqlite3* db;

// 打开数据库
bool openDatabase(const char* databaseName)
{
    // 尝试连接数据库
    int rc = sqlite3_open(databaseName, &db);

    if (rc != SQLITE_OK)
    {
        // 连接数据库失败，打印错误信息
        printf("Error opening database: %s\n", sqlite3_errmsg(db));
        return false;
    }

    return true;
}

// 关闭数据库连接
void closeDatabase()
{
    // 关闭数据库连接
    sqlite3_close(db);
}

// 检查用户名是否唯一
bool isUsernameUnique(const char* username)
{
    char sql[256];
    snprintf(sql, sizeof(sql), "SELECT COUNT(*) FROM UserData WHERE username = '%s';", username);

    // 执行查询语句
    sqlite3_stmt* stmt;
    int rc = sqlite3_prepare_v2(db, sql, -1, &stmt, NULL);
    if (rc != SQLITE_OK)
    {
        // 查询失败，打印错误信息
        printf("Error executing query: %s\n", sqlite3_errmsg(db));
        return false;
    }

    // 获取查询结果
    int count = 0;
    if (sqlite3_step(stmt) == SQLITE_ROW)
    {
        count = sqlite3_column_int(stmt, 0);
    }

    // 释放查询句柄
    sqlite3_finalize(stmt);

    return count == 0;
}

// 保存用户注册信息
bool saveUser(const char* username, const char* password)
{
    char sql[256];
    snprintf(sql, sizeof(sql), "INSERT INTO UserData (username, password) VALUES ('%s', '%s');", username, password);

    // 执行插入语句
    char* errmsg = NULL;
    int rc = sqlite3_exec(db, sql, NULL, 0, &errmsg);
    if (rc != SQLITE_OK)
    {
        // 插入失败，打印错误信息
        printf("Error executing query: %s\n", errmsg);
        sqlite3_free(errmsg);
        return false;
    }

    return true;
}

// 获取用户信息
bool getUser(const char* username, char* password)
{
    char sql[256];
    snprintf(sql, sizeof(sql), "SELECT password FROM UserData WHERE username = '%s';", username);

    // 执行查询语句
    sqlite3_stmt* stmt;
    int rc = sqlite3_prepare_v2(db, sql, -1, &stmt, NULL);
    if (rc != SQLITE_OK)
    {
        // 查询失败，打印错误信息
        printf("Error executing query: %s\n", sqlite3_errmsg(db));
        return false;
    }

    // 获取查询结果
    if (sqlite3_step(stmt) == SQLITE_ROW)
    {
        const unsigned char* dbPassword = sqlite3_column_text(stmt, 0);
        snprintf(password, PASSWORD_LENGTH, "%s", dbPassword);
    }
    else
    {
        // 用户不存在
        return false;
    }

    // 释放查询句柄
    sqlite3_finalize(stmt);

    return true;
}

