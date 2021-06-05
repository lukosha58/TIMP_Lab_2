#pragma once
#include <stdexcept>
#include <string>
using namespace std;
class Error : public invalid_argument
{
public:
    static void Check_s(string str);
    static void Check_k(wstring str, string sKey);
    Error (const string error) : invalid_argument(error) {};
    Error ()=delete;
};