#include <iostream>
#include <string>
using namespace std;

int main(int argc, char **argv)
{
    string s = "deb http://mirror.mephi.ru/debian/ stretch main contrib non-free\ndeb-src http://mirror.mephi.ru/debian/ stretch main contrib non-free\ndeb http://security.debian.org/ stretch/updates main contrib non-free\ndeb-src http://security.debian.org/ stretch/updates main contrib non-free\ndeb http://mirror.mephi.ru/debian/ stretch-updates main contrib non-free\ndeb-src http://mirror.mephi.ru/debian/ stretch-updates main contrib non-free\ndeb http://mirror.mephi.ru/debian stretch-backports main contrib non-free\ndeb-src http://mirror.mephi.ru/debian stretch-backports main contrib non-free";
    while (s.find("mephi") != string::npos) {
        int n = s.find("mephi");
        s.replace(n, 5, "yandex");
    }
    cout << "Исправленный текст:" << endl;
    cout << s << endl;
    return 0;
}
