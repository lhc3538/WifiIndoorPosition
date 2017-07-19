#ifndef DBOPTER_H
#define DBOPTER_H

#include <string>
#include <mysql/mysql.h>
#include "wificellarray.h"

using namespace std;

class DbOpter
{
public:
    DbOpter();
    ~DbOpter();
    bool initDB(string host, string user, string pwd, string db_name);
    bool exeSQL(string sql);
//    bool insertRow(string pos,int G1=-96,int G2=-96,int G3=-96,int C1=-96,int C2=-96,int C3=-96);
    bool insertRow(string table,string pos,int G1=-96,int G2=-96,int G3=-96,\
                   int C1=-96,int C2=-96,int C3=-96,\
                   int O1=-96,int O2=-96,int O3=-96);
    bool insertWifiCellArray(string table,string pos,WifiCellArray cells);

private:
        MYSQL *connection;
        MYSQL_RES *result;
        MYSQL_ROW row;

};

#endif // DBOPTER_H
