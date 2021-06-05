#include <iostream>
#include <modAlphaCipher.h>
#include <codecvt>

using namespace std;

int main ()
{
    locale loc("ru_RU.UTF-8");
    locale::global(loc);
    bool Check = true;
    wstring regime,Neregime,wstr,wstr_key;
    cout << "1 - шифрование\n";
    cout << "2 - расшифрование\n";
    cout << "0 - завершить работу\n";
    do {
        cout << "Укажите режим работы:";
        wcin >> regime;
        if (regime == L"1") {
            cout << "Введите строку для шифрования:";
            wcin.get();
            getline(wcin,wstr);
            cout << "Введите ключ:";
            getline(wcin,wstr_key);
            try {
                modAlphaCipher cipher(wstr_key);
                wstring cipherText = cipher.encrypt(wstr);
                wstring_convert<codecvt_utf8<wchar_t>, wchar_t> codec;
                cout<<codec.to_bytes(cipherText)<<endl;
            } catch (Error & ex) {
                cout << "Ошибка: "<<ex.what() << endl;

            }
        }
        if (regime == L"2") {
            cout << "Введите строку для расшифрования:";
            wcin.get();
            getline(wcin,wstr);
            cout << "Введите ключ:";
            getline(wcin,wstr_key);
            try {
                modAlphaCipher cipher(wstr_key);
                wstring OpenText = cipher.decrypt(wstr);
                wstring_convert<codecvt_utf8<wchar_t>, wchar_t> codec;
                cout<<codec.to_bytes(OpenText)<<endl;
            } catch (Error & ex) {
                cout << "Ошибка: "<<ex.what() << endl;
            }
        }
        if (regime == L"0") {
            Check = false;
            break;
        }

    } while (Check != false);
    return 0;
}