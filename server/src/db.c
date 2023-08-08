/* db.c - 数据库操作

连接数据库
执行SQL语句
封装常用数据库操作函数 */

#include "db.h"

sqlite3* db;

bool db_connect() {
    int rc = sqlite3_open("..\database\SHomedb.db", &db);
    if (rc != SQLITE_OK) {
        // 处理连接错误
        return false;
    }
    return true;
}

void db_disconnect() {
    sqlite3_close(db);
}

bool db_execute_sql(const char* sql) {
    char* err_message = 0;
    int rc = sqlite3_exec(db, sql, 0, 0, &err_message);
    if (rc != SQLITE_OK) {
        // 处理执行错误
        return false;
    }
    return true;
}

// 封装其他常用数据库操作函数
// ...
