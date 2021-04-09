#include <iostream>
#include <string>
using namespace std;

int main(int argc, char **argv)
{
    cout << "Введите число от 1 до 100" << endl;
    int n;
    cin >> n;
    if (n >= 1 and n <=100) {
        string s1 = "В караване был";
        string s2 = " верблюд";
        if ((n > 10 and n < 20) or (n%10 > 4 and n%10 < 9) or (n%10 == 0)) {
            cout << s1.append("о ") + to_string(n) + s2.append("ов") << endl;
        } else if (n%10 == 1) {
            cout << s1 + " " + to_string(n) + s2 << endl;
        } else if (n%10 > 1 and n%10 < 5) {
            cout << s1.append("о ") + to_string(n) + s2.append("а") << endl;
        }
    } else {
        cout << "Введённое число не входит в диапазон от 1 до 100" << endl;;
    }
    return 0;
}
