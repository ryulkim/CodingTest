#include <iostream>
#include <vector>
using namespace std;

vector<int> v;
int s, num = 0;

void f(int k, int sum) {
    if (k == 0) {
        if (sum == s) {
            num++;
        }
        return;
    }
    f(k - 1, sum);
    f(k - 1, sum + v[k - 1]);
}

int main() {
    int n, x;
    cin >> n >> s;
    for (int i = 0; i < n; i++) {
        cin >> x;
        v.push_back(x);
    }
    f(n, 0);
    if (s == 0) {
        num--;
    }
    cout << num << "\n";
}
