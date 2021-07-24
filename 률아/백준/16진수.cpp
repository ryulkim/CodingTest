#include <iostream>
using namespace std;

int main() {
    string s;
    int temp = 1;
    int res = 0;
    cin >> s;
    for (int i = s.length() - 1; i >= 0; i--) {
        if (s[i] >= 'A') {
            s[i] -= 55;
        }
        else {
            s[i] -= '0';
        }
        res += int(s[i]) * temp;
        temp *= 16;
    }
    cout << res;
}
