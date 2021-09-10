#include <iostream>
using namespace std;

int arr[10];
int n, m;


void bac(int level) {
    if (level == m) {
        for (int i = 1; i <= m; i++) {
            cout << arr[i] << ' ';
        }
        cout << '\n';
        return;
    }
    for (int i = arr[level]; i < n; i++) {
        arr[level + 1] = i + 1;
        bac(level + 1);
    }
}

int main() {
    cin >> n >> m;
    arr[0] = 0;

    bac(0);
}
