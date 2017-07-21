#include <iostream>
#include <fstream>
#include <sstream>
#include <stdlib.h>
#include <string.h>

#include "socketconnector.h"
#include "../Common/sockettransfer.h"
#include "stringutils.h"
#include "wificell.h"
//#include "dbopter.h"
#include "wificellarray.h"

using namespace std;

void level_threemeters(string pos);
void deal_signal();

int main(int argc, char *argv[])
{
//    level_threemeters("A6");

    deal_signal();

    return 0;
}

void deal_signal()
{
    SocketConnector sockConnector;
    int fd_cli = sockConnector.ConnectServer("192.168.1.131",3538);
    SocketTransfer sock_apple(fd_cli);
    while(1)
    {
        sock_apple.Send("iwinfo wlan0 scan");
        string str_sig = sock_apple.Recv();
        if (str_sig.empty())
            break;
        WifiCellArray cells(str_sig);

        ostringstream oss;//用于向string写入,和cout<<一样，仅仅重载了<<
        oss << cells.getSignalByMac("00:34:CB:E4:DC:54") << " " <<
                cells.getSignalByMac("00:34:CB:E4:DC:48") << " " <<
                cells.getSignalByMac("00:34:CB:E4:DC:4C") << " " <<

                cells.getSignalByMac("00:17:7B:31:0C:13") << " " <<
                cells.getSignalByMac("00:17:7B:9C:19:4D") << " " <<
                cells.getSignalByMac("00:17:7B:32:E0:1D") << " " <<

                cells.getSignalByMac("8C:AB:8E:A4:7E:50") << " " <<
                cells.getSignalByMac("00:6B:8E:E3:DE:18") << " " <<
                cells.getSignalByMac("C0:A0:BB:26:46:18") << " 0";
        string str_signal = oss.str();


        ofstream out("onedata.txt");
        if (out.is_open())
        {
            cout << str_signal << endl;
            out << str_signal;
            out.close();
        }

        system("hadoop jar /home/hadoop/KNN.jar");

        string str_pos;
        char char_pos[256];
        ifstream in("result.txt");
        if (! in.is_open())
            { cout << "Error opening file"; }
        while (!in.eof() )
        {
            in.getline (char_pos,100);
            cout << "pos:" <<char_pos << endl;
            SocketConnector sockConnector;
            int fd_to_ser = sockConnector.ConnectServer("127.0.0.1",6666);
            send(fd_to_ser,char_pos,strlen(char_pos),0);
        }
    }
}

//void level_threemeters(string pos)
//{
//    SocketConnector sockConnector;
//    int fd_cli = sockConnector.ConnectServer("192.168.1.131",3538);
////    int fd_cli = sockConnector.ConnectServer("127.0.0.1",3538);
//    SocketTransfer sockTransfer(fd_cli);
//    //training set
//    DbOpter dbopter_train;
//    dbopter_train.initDB("139.199.27.197","wifipos","iotiot128","wifi_training_set");
//    int num = 100;
//    while(num--)
//    {
//        sockTransfer.Send("iwinfo wlan0 scan");
//        string str = sockTransfer.Recv();
//        if (str.empty())
//            break;
//        WifiCellArray cells(str);

//        dbopter_train.insertWifiCellArray("level_threemeters",pos,cells);
//        cout << "num=" << num << endl;
//    }
//    //test set
//    DbOpter dbopter_test;
//    dbopter_test.initDB("139.199.27.197","wifipos","iotiot128","wifi_test_set");
//    num = 3;
//    while(num--)
//    {
//        sockTransfer.Send("iwinfo wlan0 scan");
//        string str = sockTransfer.Recv();
//        if (str.empty())
//            break;
//        WifiCellArray cells(str);

//        dbopter_test.insertWifiCellArray("level_threemeters",pos,cells);
//    }
//}
