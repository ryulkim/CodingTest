#include <iostream>
#include <string>
#include <cmath>
#include <algorithm>
using namespace std;

bool failure[11] = { false };

bool check(string str) {
    for (int i = 0; i < str.length(); i++) {
        if (failure[str[i] - '0']) {
            return false;
        }
    }
    return true;
}

int main() {
    int n, m, x;
    string cmp = "";

    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        cin >> x;
        failure[x] = 1;
    }
    if (n == 100) {
        cout << 0 << endl;
    }
    else {
        int minimum = abs(n - 100);
        for (int i = 0; i < 1000000; i++) {
            string str = to_string(i);
            if (check(str)) {
                int num = abs(n - i) + str.length();
                minimum = min(minimum, num);
            }
        }
        cout << minimum << endl;
    }
}
