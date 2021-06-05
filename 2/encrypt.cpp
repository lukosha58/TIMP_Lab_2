#include "encrypt.h"

Encrypt::Encrypt(int k)
{
    key=k;
}

wstring Encrypt::EncodeCipher(Encrypt ob, wstring wstr)
{
    wstring Uptshot;
    int row;
    if (wstr.length()%ob.key!=0)
        row=wstr.length()/ob.key+1;
    else
        row=wstr.length()/ob.key;

    int pointer = 0;
    wchar_t table[row][ob.key];
    for (int i = 0; i <row; i++) {
        for (int j = 0; j < ob.key; j++ ) {
            if (pointer < wstr.size()) {
                table[i][j] = wstr[pointer];
                pointer++;
            } else {
                table[i][j] =' ';
            }
        }
    }
    for (int i = 0; i < ob.key; i++) {
        for (int j = 0; j < row; j++ ) {
            Uptshot+=(table[j][i]);
        }
    }
    return Uptshot;
}

wstring Encrypt::DecodeCipher(Encrypt ob, wstring wstr)
{
    wstring Uptshot;
    int pointer = 0;
    int row;
    if (wstr.length()%ob.key!=0)
        row=wstr.length()/ob.key+1;
    else
        row=wstr.length()/ob.key;


    wchar_t table[row][ob.key];

    for (int i = 0; i < ob.key; i++) {
        for (int j = 0; j < row; j++ ) {
            if (pointer < wstr.size()) {
                table[j][i] = wstr[pointer];
                pointer++;
            } else {
                table[j][i] = ' ';
                pointer++;
            }
        }
    }
    for(int i = 0; i < row; i++) {
        for (int j = 0; j< ob.key; j++) {
            Uptshot +=(table[i][j]);
        }
    }
    return Uptshot;
}