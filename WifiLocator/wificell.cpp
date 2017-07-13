#include "wificell.h"

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
