#include "stringutils.h"
#include <iostream>

//Cell 01 - Address: 8C:AB:8E:A4:CD:58
//          ESSID: "LeonOpenWrt"
//          Mode: Master  Channel: 10
//          Signal: -42 dBm  Quality: 68/70
//          Encryption: WPA2 PSK (CCMP)

StringUtils::StringUtils()
{

}

vector<string> StringUtils::Split(const string &src, const string &separator)
{
    vector<string> rul;
    string str("");
//    cout << "src=" << src << endl;
    int src_size = src.size();
    int separator_size = separator.size();
    for (int i=0;i<src_size;i++)
    {
        int j;
        for(j=0;j<separator_size;j++)
        {
            if(src[i+j]!=separator[j])
                break;
        }
        //equal the separator
        if(j==separator_size)
        {
            if(!str.empty())
            {
                rul.push_back(str);
                str.clear();
                i+=(j-1);
            }
            continue;
        }
        str.push_back(src[i]);
    }
    if(!str.empty())
        rul.push_back(str);
    return rul;
}

string StringUtils::GetMiddleStr(const string &src, const string &str_start, const string &str_end)
{
    int src_size = src.size();
    int str_start_size = str_start.size();
    int str_end_size = str_end.size();
    for(int i=0;i<src_size;i++)
    {
        int j;
        for(j=0;j<str_start_size;j++)
            if(src[i+j]!=str_start[j])
                break;
        if (j == str_start_size)
        {

        }
    }
}
