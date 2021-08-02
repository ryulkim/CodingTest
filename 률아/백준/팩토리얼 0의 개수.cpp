#include <iostream>
using namespace std;

int main() {
    int n, temp;
    int num = 0;
    cin >> n;
    for (int i = 2; i <= n; i++) {
        if (i % 5 == 0) {
            temp = i;
            while (temp % 5 == 0) {
                num++;
                temp /= 5;
            }
        }
    }
    cout << num << "\n";
}
