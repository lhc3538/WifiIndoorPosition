#include "wificell.h"
#include "stringutils.h"

#include <vector>
#include <iostream>

//Cell 01 - Address: 8C:AB:8E:A4:CD:58
//          ESSID: "LeonOpenWrt"
//          Mode: Master  Channel: 10
//          Signal: -42 dBm  Quality: 68/70
//          Encryption: WPA2 PSK (CCMP)

WifiCell::WifiCell()
{

}

WifiCell::WifiCell(string cellstr)
{
    StringUtils stringUtils;
    vector<string> str_line = stringUtils.Split(cellstr,"\n");

    vector<string> str_value = stringUtils.Split(str_line[0],": ");
    setAddress(str_value[1]);
    cout << "mac:" << getAddress() << endl;

    str_value = stringUtils.Split(str_line[1],": ");
    setSsid(str_value[1]);
    cout << "ssid:" << getSsid() << endl;

    str_value = stringUtils.Split(str_line[2],": ");
    setChannel(stoi(str_value[2]));
    cout << "channel:" << getChannel() << endl;

    string str_mid = stringUtils.GetMiddleStr(str_line[3],": "," dBm");
    setSignal(stoi(str_value[2]));
    cout << "signal:" << getSignal() << endl;

    str_value = stringUtils.Split(str_line[3],": ");
    setQuality(str_value[2]);
    cout << "Quality:" << getQuality() << endl;
}

string WifiCell::getAddress() const
{
    return address;
}

void WifiCell::setAddress(const string &value)
{
    address = value;
}

string WifiCell::getSsid() const
{
    return ssid;
}

void WifiCell::setSsid(const string &value)
{
    ssid = value;
}

int WifiCell::getChannel() const
{
    return channel;
}

void WifiCell::setChannel(int value)
{
    channel = value;
}

int WifiCell::getSignal() const
{
    return signal;
}

void WifiCell::setSignal(int value)
{
    signal = value;
}

string WifiCell::getQuality() const
{
    return quality;
}

void WifiCell::setQuality(const string &value)
{
    quality = value;
}
