#ifndef STRINGUTILS_H
#define STRINGUTILS_H

#include <string>
#include <vector>

using namespace std;

class StringUtils
{
public:
    StringUtils();

    vector<string> Split(const string &src,const string &separator);
    string GetMiddleStr(const string &src,const string &str_start,const string &str_end);
};

#endif // STRINGUTILS_H
