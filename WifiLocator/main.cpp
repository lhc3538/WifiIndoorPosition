#include <iostream>
#include "socketconnector.h"
#include "../Common/sockettransfer.h"
#include "stringutils.h"
#include "wificell.h"

using namespace std;

int main(int argc, char *argv[])
{
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

    SocketConnector sockConnector;
    int fd_cli = sockConnector.ConnectServer("192.168.1.131",3538);
//    int fd_cli = sockConnector.ConnectServer("127.0.0.1",3538);
    SocketTransfer sockTransfer(fd_cli);

    while(1)
    {
        sockTransfer.Send("iwinfo wlan0 scan");
        string str = sockTransfer.Recv();
        vector<string> str_cells = StringUtils().Split(str,"\n\n");
        for(int i=0;i<str_cells.size();i++)
        {
//            cout << str_cells[i] << ";;;;;" << endl;
            WifiCell wifiCell(str_cells[i]);
        }
    }

    return 0;
}
