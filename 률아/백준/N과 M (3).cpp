#include <iostream>
using namespace std;

int n, m;
int arr[9];

void back(int level) {
    if (level == m) {
        for (int i = 1; i <= m; i++) {
            cout << arr[i] << ' ';
        }
        cout << '\n';
        return;
    }
    for (int i = 1; i <= n; i++) {
        arr[level + 1] = i;
        back(level + 1);
    }
}

int main() {
    cin >> n >> m;

    back(0);
}
