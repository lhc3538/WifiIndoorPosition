#ifndef DBOPTER_H
#define DBOPTER_H

#include <string>
#include<mysql/mysql.h>

using namespace std;

class DbOpter
{
public:
    DbOpter();
    ~DbOpter();
    bool initDB(string host, string user, string pwd, string db_name);
    bool exeSQL(string sql);
//    bool insertRow()

private:
        MYSQL *connection;
        MYSQL_RES *result;
        MYSQL_ROW row;

};

#endif // DBOPTER_H
