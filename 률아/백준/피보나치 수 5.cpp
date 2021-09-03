#include <iostream>
using namespace std;

int main() {
    int one = 0, two = 1, answer=1;
    int n;
    cin >> n;
    if (n == 0) {
        cout << one << '\n';
    }
    else if (n == 1) {
        cout << two << '\n';
    }
    else {
        for (int i = 2; i <= n; i++) {
            answer = one + two;
            one = two;
            two = answer;
        }
        cout << answer << endl;
    }
}
