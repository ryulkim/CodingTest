#include <iostream>
using namespace std;

int arr[10];
int n, m;

bool check(int level) {
    for (int i = 1; i < level; i++) {
        if (arr[i] == arr[level]) {
            return false;
        }
    }
    return true;
}

void bac(int level) {
    if (!check(level)) {
        return;
    }
    else if (level == m) {
        for (int i = 1; i <= m; i++) {
            cout << arr[i] << ' ';
        }
        cout << '\n';
        return;
    }

    for (int i = 1; i <= n; i++) {
        arr[level + 1] = i;
        bac(level + 1);
    }
}

int main() {
    cin >> n >> m;

    bac(0);


}
