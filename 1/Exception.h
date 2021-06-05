#pragma once
#include <stdexcept>
#include <string>
using namespace std;
class Error : public invalid_argument
{    
public:
    Error (const string error):invalid_argument(error){};
};