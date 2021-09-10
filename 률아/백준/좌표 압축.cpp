#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    vector<int> v1;
    vector<int> v2;//sort
    int n, x;

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> x;
        v1.push_back(x);
    }
    v2 = v1;
    sort(v2.begin(), v2.end());
    v2.erase(unique(v2.begin(), v2.end()), v2.end());

    for (int i = 0; i < n; i++) {
        auto it = lower_bound(v2.begin(),v2.end(),v1[i]);
        cout << it - v2.begin() << ' ';
    }
    cout << '\n';
}
