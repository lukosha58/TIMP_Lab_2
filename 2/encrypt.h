#pragma once
#include "Exception.h"
#include <string>
#include <vector>
#include <iostream>
using namespace std;
class Encrypt
{
private:
    int key;
public:
    Encrypt() = delete;
    Encrypt(int k);
    wstring EncodeCipher(Encrypt ob, wstring wstr);
    wstring DecodeCipher(Encrypt ob, wstring wstr);
};