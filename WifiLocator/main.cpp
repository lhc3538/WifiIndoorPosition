#include <iostream>
#include "socketconnector.h"
#include "../Common/sockettransfer.h"
#include "stringutils.h"
#include "wificell.h"
#include "dbopter.h"
#include "wificellarray.h"

using namespace std;

int main(int argc, char *argv[])
{
    SocketConnector sockConnector;
    int fd_cli = sockConnector.ConnectServer("192.168.1.131",3538);
//    int fd_cli = sockConnector.ConnectServer("127.0.0.1",3538);
    SocketTransfer sockTransfer(fd_cli);

    int num = 3;
    while(num--)
    {
        sockTransfer.Send("iwinfo wlan0 scan");
        string str = sockTransfer.Recv();
        if (str.empty())
            break;
        WifiCellArray cells(str);

        DbOpter dbopter;
        dbopter.initDB("139.199.27.197","wifipos","iotiot128","wifi_test_set");
        dbopter.insertWifiCellArray("A8N",cells);

    }
//-------------------------------------------------------------------------------

//    DbOpter dbopter;
//    bool ret = dbopter.initDB("139.199.27.197","wifipos","iotiot128","wifi_training_set");
//    cout << ret << endl;
////    dbopter.exeSQL("SELECT * FROM level_meter");
//    dbopter.insertRow("A2",-1,-2,-3,-4,-5,-6);

    //    vector<string> rul = StringUtils().Split("a\nb\nc\n\nd\ne\nf\n","\n\n");
    //    for(int i=0;i<rul.size();i++)
    //    {
    //        cout << rul[i] << ";;;;;" << endl;
    //    }
    //    rul = StringUtils().Split("a\nb\nc\n\nd\ne\nf\n","\n");
    //    for(int i=0;i<rul.size();i++)
    //    {
    //        cout << rul[i] << ";;;;;" << endl;
    //    }

    //    string cell = "Signal: -42 dBm  Quality: 68/70";
    //    string str_mid = StringUtils().GetMiddleStr(cell,": "," dBm");
    //    cout << str_mid << endl;


    return 0;
}
