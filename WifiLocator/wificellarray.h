#ifndef WIFICELLARRAY_H
#define WIFICELLARRAY_H

#include <vector>
#include <map>
#include "wificell.h"

using namespace std;

class WifiCellArray
{
public:
    WifiCellArray(string ori_str);

    int getSignalByMac(string mac);

private:
    vector<WifiCell> wifiCells;
    map<string,int> macMapSignal;
};

#endif // WIFICELLARRAY_H
