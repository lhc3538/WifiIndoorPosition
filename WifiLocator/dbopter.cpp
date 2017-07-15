#include <iostream>
#include <sstream>
#include <cstdlib>

#include "dbopter.h"


DbOpter::DbOpter()
{
    connection = mysql_init(NULL); // 初始化数据库连接变量
    if(connection == NULL)
    {
        cout << "Error:" << mysql_error(connection);
        exit(1);
    }
}

DbOpter::~DbOpter()
{
    if(connection != NULL)  // 关闭数据库连接
    {
        mysql_close(connection);
    }
}

bool DbOpter::initDB(string host, string user, string pwd, string db_name)
{
    // 函数mysql_real_connect建立一个数据库连接
    // 成功返回MYSQL*连接句柄，失败返回NULL
    connection = mysql_real_connect(connection, host.c_str(),
            user.c_str(), pwd.c_str(), db_name.c_str(), 0, NULL, 0);
    if(connection == NULL)
    {
        cout << "Error:" << mysql_error(connection);
        exit(1);
    }
    return true;
}

bool DbOpter::exeSQL(string sql)
{
    // mysql_query()执行成功返回0，失败返回非0值。与PHP中不一样
    if(mysql_query(connection, sql.c_str()))
    {
        cout << "Query Error:" << mysql_error(connection);
        exit(1);
    }
    else
    {
        result = mysql_use_result(connection); // 获取结果集
        // mysql_field_count()返回connection查询的列数
        cout << "mysql_field_count=" << mysql_num_rows(result) << endl;
        cout << "mysql_num_fields=" << mysql_num_fields(result) << endl;
        for(int i=0; i < mysql_num_rows(result); ++i)
        {
            // 获取下一行
            row = mysql_fetch_row(result);
            if(row <= 0)
            {
                break;
            }
            // mysql_num_fields()返回结果集中的字段数
            for(int j=0; j < mysql_num_fields(result); ++j)
            {
                cout << row[j] << " ";
            }
            cout << endl;
        }
        // 释放结果集的内存
        mysql_free_result(result);
    }
    return true;
}

bool DbOpter::insertRow(string pos, int G1, int G2, int G3, int C1, int C2, int C3)
{
    stringstream sql_stream;
    sql_stream << "INSERT INTO level_meter VALUES(NULL, \"" <<
              pos << "\"," <<
              G1 << "," <<
              G2 << "," <<
              G3 << "," <<
              C1 << "," <<
              C2 << "," <<
              C3 << ")";

    cout << sql_stream.str() << endl;
    if(mysql_query(connection, sql_stream.str().c_str()))
    {
        cout << "Query Error:" << mysql_error(connection);
        return false;
    }
    return true;
}

bool DbOpter::insertWifiCellArray(string pos,WifiCellArray cells)
{
    insertRow(pos,
              cells.getSignalByMac("00:34:CB:E4:DC:54"),
              cells.getSignalByMac("00:34:CB:E4:DC:48"),
              cells.getSignalByMac("00:34:CB:E4:DC:4C"),
              cells.getSignalByMac("00:17:7B:31:0C:13"),
              cells.getSignalByMac("00:17:7B:9C:19:4D"),
              cells.getSignalByMac("00:17:7B:32:E0:1D"));
}
