#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    map<string, int>M;
    vector<string> v;
    int n, m, sum = 0;
    string s;
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> s;
        M.insert(make_pair(s, 1));
    }
    for (int i = 0; i < m; i++) {
        cin >> s;
        if (M.count(s) != 0) {
            sum++;
            v.push_back(s);
        }
    }
    cout << sum << endl;
    sort(v.begin(), v.end());
    for (int i = 0; i < sum; i++) {
        cout << v[i] << endl;
    }
}
