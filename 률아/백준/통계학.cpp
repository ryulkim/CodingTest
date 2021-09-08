#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <cmath>

#define pp pair<int,int>
using namespace std;

map<int, int> m;

bool cmp(const pp& a, const pp& b) {
    if (a.second == b.second)return a.first < b.first;
    return a.second > b.second;
}

int main() {
    int n, x;
    vector<int> v;
    
    double sum = 0;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> x;
        sum += x;
        v.push_back(x);
        if (m.count(x) > 0) {
            m[x]++;
        }
        else {
            m.insert(pair<int, int>(x, 1));
        }
    }
    
    cout << floor(sum / n+0.5) << '\n';

    sort(v.begin(), v.end());
    cout << v[n / 2] << '\n';
    
    vector<pp> vec(m.begin(), m.end());
    sort(vec.begin(), vec.end(), cmp);
    
    if (vec.size()>1&&vec[0].second == vec[1].second) {
        cout << vec[1].first << '\n';
    }
    else {
        cout << vec[0].first << '\n';
    }

    cout << v[n - 1] - v[0] << '\n';
    
}
