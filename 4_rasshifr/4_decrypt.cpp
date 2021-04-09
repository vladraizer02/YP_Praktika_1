#include <iostream>
#include <string>
#include <locale>
#include <cctype>
#include <codecvt>
using namespace std;

string decrypt(const string text, const int key);

int main(int argc, char **argv)
{
    string s;
    cout << "Введите строку для расшифровки" << endl;
    getline(cin, s);
    cout << "Введите ключ" << endl;
    int n;
    cin >> n;
    string s_new;
    s_new = decrypt(s, n);
    if (s_new == "ОШИБКА") {
        cout<<s_new<<endl;
    } else {
    cout<<"Расшифрованный текст: "<<s_new<<endl;
    }
    return 0;
}

string decrypt(string text, const int key)
{
    int key2 = key%32;
    locale loc("ru_RU.UTF-8"); // русская локаль для корректной смены регистра
    wstring_convert<codecvt_utf8<wchar_t>, wchar_t> codec; //кодек UTF-8
    wstring ws = codec.from_bytes(text); // перекодируем из UTF-8 в UTF-32
    for(int i = 0; i < ws.size(); i++) {
        if (ws[i] > 1039 and ws[i] < 1104) {
            ws[i] = toupper(ws[i],loc);
        } else {
            text = "ОШИБКА";
            return text;
        }
    }
    for(int i = 0; i < ws.size(); i++) {
        if (ws[i] - key2 < 1040) {
            ws[i] = ws[i] - key2 + 32;
        } else {
            ws[i] = ws[i] - key2;
        }
    }
    text = codec.to_bytes(ws); // перекодируем из UTF-32 в UTF-8
    return text;
}
