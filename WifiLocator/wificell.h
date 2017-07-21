#ifndef WIFICELL_H
#define WIFICELL_H

#include <string>
#include <time.h>

using namespace std;

//Cell 01 - Address: 8C:AB:8E:A4:CD:58
//          ESSID: "LeonOpenWrt"
//          Mode: Master  Channel: 10
//          Signal: -42 dBm  Quality: 68/70
//          Encryption: WPA2 PSK (CCMP)

class WifiCell
{
public:
    WifiCell();
    WifiCell(string cellstr);

    string getAddress() const;
    void setAddress(const string &value);

    string getSsid() const;
    void setSsid(const string &value);

    int getChannel() const;
    void setChannel(int value);

    int getSignal() const;
    void setSignal(int value);

    string getQuality() const;
    void setQuality(const string &value);

    unsigned long getTimestamp() const;
    void setTimestamp(unsigned long value);

private:
    string address;
    string ssid;
    int channel;
    int signal;
    string quality;
    unsigned long  timestamp;

    int stoi(string str);

};

#endif // WIFICELL_H
