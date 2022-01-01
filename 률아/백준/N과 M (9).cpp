#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> v;
int arr[10];
bool check[10];
int n, m;

void back(int level) {
    if (level == m) {
        for (int i = 0; i < m; i++) {
            cout << arr[i] << ' ';
        }
        cout << '\n';
        return;
    }
    int x = 0;
    for (int i = 0; i < n; i++) {
        if (check[i] == 0&&x!=v[i]) {
            arr[level] = v[i];
            x = v[i];
            check[i] = 1;
            back(level + 1);
            check[i] = 0;
        }
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
    back(0);
}
