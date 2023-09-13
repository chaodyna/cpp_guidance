#include <iostream>
using namespace std;

int main() {
    int a;
    int out = 0;
    while (cin >> a) { // 注意 while 处理多个 case
        if(a == 0) {
            break;
        }
        while(a > 2) {
            out += a / 3;
            a = a / 3 + a % 3;
        }
        if(a == 2) {
            out++;
            a = 0;
        }
        cout << out << endl;
    }
}
