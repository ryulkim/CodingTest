#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

vector<int> v;
int arr[10];
int n, m;

void back(int level, int i) {
    if (level == m) {
        for (int j = 1; j <= m; j++) {
            cout << arr[j] << ' ';
        }
        cout << '\n';
        return;
    }
    for (; i < n; i++) {
        arr[level + 1] = v[i];
        back(level + 1, i);
    }
}

int main() {
    int x;

    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> x;
        v.push_back(x);
    }
    sort(v.begin(), v.end());
    back(0,0);
}
