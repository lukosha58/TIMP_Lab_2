#include "modAlphaCipher.h"
modAlphaCipher::modAlphaCipher(const wstring& skey)
{
    for (unsigned i=0; i<numAlpha.size(); i++) {
        alphaNum[numAlpha[i]]=i;
    }
    key = convert(getValidKey (skey));
}
wstring modAlphaCipher::encrypt(const wstring& open_text)
{
    vector<int> work = convert(getValid_Str (open_text));
    for(unsigned i=0; i < work.size(); i++) {
        work[i] = (work[i] + key[i % key.size()]) % alphaNum.size();
    }
    return convert(work);
}
wstring modAlphaCipher::decrypt(const wstring& cipher_text)
{
    vector<int> work = convert(getValid_Str (cipher_text));
    for(unsigned i=0; i < work.size(); i++) {
        work[i] = (work[i] + alphaNum.size() - key[i % key.size()]) % alphaNum.size();
    }
    return convert(work);
}
inline vector<int> modAlphaCipher::convert(const wstring& s)
{
    vector<int> result;
    for(auto c:s) {
        result.push_back(alphaNum[c]);
    }
    return result;
}
inline wstring modAlphaCipher::convert(const vector<int>& v)
{
    wstring result;
    for(auto i:v) {
        result.push_back(numAlpha[i]);
    }
    return result;
}
wstring modAlphaCipher::getValidKey(const wstring & s)
{
    locale loc("ru_RU.UTF-8");
    locale::global(loc);
    if (s.empty())
        throw Error(string("Пустой ключ"));
    wstring wst = s;
    for (int i = 0; i < wst.size(); i++) {
        if (iswalpha(wst[i])==0) {
            throw Error(string("Присутствуют не допустимые символы"));
            break;
        }
        if (iswlower(wst[i]))
            wst[i] = towupper(wst[i]);
    }
    return wst;
}
wstring modAlphaCipher::getValid_Str(const wstring & s)
{
    locale loc("ru_RU.UTF-8");
    locale::global(loc);
    if (s.empty())
        throw Error(string("Пустой ввод"));
    wstring wst = s;
    for (int i = 0; i < wst.size(); i++) {
        if (iswalpha(wst[i])==0) {
            throw Error(string("Присутствуют недопустимые символы."));
            break;
        }
        if (iswlower(wst[i]))
            wst[i] = towupper(wst[i]);
    }
    return wst;
}