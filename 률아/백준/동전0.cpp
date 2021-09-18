#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n, k, x, num = 0;
    vector<int> v;
    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        cin >> x;
        v.push_back(x);
    }
    for (int i = v.size() - 1; i >= 0; i--) {
        if (k == 0)break;
        if (v[i] <= k) {
            num += k / v[i];
            k %= v[i];
        }
    }
    cout << num << '\n';
}
