#include <iostream>
#include <string>
#include <locale>
#include <cctype>
#include <codecvt>
using namespace std;

string encrypt(const string text, const int key);

int main(int argc, char **argv)
{
    string s;
    cout << "Введите строку для зашифровки" << endl;
    getline(cin, s);
    cout << "Введите ключ" << endl;
    int n;
    cin >> n;
    string s_new;
    s_new = encrypt(s, n);
    cout<<"Зашифрованный текст: "<<s_new<<endl;
    return 0;
}

string encrypt(string text, const int key)
{
    int key2 = key%32;
    locale loc("ru_RU.UTF-8"); // русская локаль для корректной смены регистра
    wstring_convert<codecvt_utf8<wchar_t>, wchar_t> codec; //кодек UTF-8
    wstring ws = codec.from_bytes(text); // перекодируем                                       
    for(int i = 0; i < ws.size(); i++) {
        if (ws[i] > 1039 and ws[i] < 1104) {                           
            ws[i] = toupper(ws[i],loc);
        } else {
            ws.erase(i, 1);
            i -= 1;
        }
    }
    for(int i = 0; i < ws.size(); i++) {
        if (ws[i] - 1039 + key2 > 32) {
            ws[i] = ws[i] + key2 - 32;
        } else {
            ws[i] = ws[i] + key2;
        }
    }
    text = codec.to_bytes(ws); // перекодируем из UTF-32 в UTF-8
    return text;
}
