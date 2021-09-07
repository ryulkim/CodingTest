#include <iostream>
using namespace std;

int main() {
    int a = 1, b = 2, c, n;
    cin >> n;
    if (n == 1) {
        cout << 1 << endl;
    }
    else if (n == 2) {
        cout << 2 << endl;
    }
    else {
        for (int i = 3; i <= n; i++) {
            c = (a+ b) % 15746;
            a = b;
            b = c;
        }
        cout << c << endl;
    }
}
