#include <iostream>
using namespace std;

int n, num = 0;
int arr[17];

bool check(int level) {
    for (int i = 1; i < level; i++) {
        if (arr[i] == arr[level]) {
            return false;
        }
        if ((level - i) + arr[i] == arr[level] || arr[i] - (level - i) == arr[level]) {
            return false;
        }
    }
    return true;
}

void queen(int level) {
    if (!check(level)) {
        return;
    }
    else if (level == n) {
        num++;
        return;
    }
    for (int i = 1; i <= n; i++) {
        arr[level + 1] = i;
        queen(level + 1);
    }
}

int main() {
    cin >> n;
    queen(0);
    cout << num << '\n';
}
