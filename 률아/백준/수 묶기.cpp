#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n, x, num, sum = 0;
    vector<int> p;
    vector<int> m;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> x;
        if (x > 0) {
            p.push_back(x);
        }
        else {
            m.push_back(x);
        }
    }
    sort(p.begin(), p.end(), greater<int>());
    sort(m.begin(), m.end());
    for (int i = 0; i < p.size(); i++) {
        if (i + 1 < p.size() && p[i+1] != 1) {
            num = p[i++] * p[i];
        }
        else {
            num = p[i];
        }
        sum += num;
    }
    for (int i = 0; i < m.size(); i++) {
        if (i + 1 < m.size()) {
            num = m[i++] * m[i];
        }
        else {
            num = m[i];
        }
        sum += num;
    }
    cout << sum << '\n';
}
