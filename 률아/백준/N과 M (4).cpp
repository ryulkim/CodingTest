#include <iostream>
using namespace std;

int n, m;
int arr[10];

void back(int level) {
    if (level == m) {
        for (int i = 1; i <= m; i++) {
            cout << arr[i] << ' ';
        }
        cout << '\n';
        return;
    }
    for (int i = arr[level]; i <= n; i++) {
        arr[level + 1] = i;
        back(level + 1);
    }
}

int main() {
    cin >> n >> m;
    arr[0] = 1;
    back(0);
}
