#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, m;
int arr[10];
bool chk[10];
vector<int> num;

void back(int level) {
    if (level == m) {
        for (int i = 1; i <= m; i++) {
            cout << arr[i] << ' ';
        }
        cout << '\n';
        return;
    }
    for (int i = 0; i < n; i++) {
        if (!chk[i]) {
            arr[level + 1] = num[i];
            chk[i] = 1;
            back(level + 1);
            chk[i] = 0;
        }
    }
}

int main() {
    cin >> n >> m;
    int x;
    for (int i = 0; i < n; i++) {
        cin >> x;
        num.push_back(x);
    }
    sort(num.begin(), num.end());
    arr[0] = 0;
    back(0);
}
