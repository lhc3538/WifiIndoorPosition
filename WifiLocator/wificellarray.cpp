#include "wificellarray.h"
#include "stringutils.h"

WifiCellArray::WifiCellArray(string ori_str)
{
    vector<string> str_cells = StringUtils().Split(ori_str,"\n\n");
    for(int i=0;i<str_cells.size();i++)
    {
        WifiCell wifiCell(str_cells[i]);
        wifiCells.push_back(wifiCell);
        macMapSignal[wifiCell.getAddress()] = wifiCell.getSignal();
    }
}

int WifiCellArray::getSignalByMac(string mac)
{
    if (macMapSignal[mac] != 0)
        return macMapSignal[mac];
    else
        return -96;
}
