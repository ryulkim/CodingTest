#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>>v(2187);
int zero, mi, one;

void divide(int y, int x, int size) {
    int check = v[y][x];
    for (int i = y; i < y + size; i++) {
        for (int j = x; j < x + size; j++) {
            if (check != v[i][j]) {
                size /= 3;
                divide(y, x, size);
                divide(y, x + size, size);
                divide(y, x + 2 * size, size);
                divide(y + size, x, size);
                divide(y + size, x + size, size);
                divide(y + size, x + 2 * size, size);
                divide(y + 2 * size, x, size);
                divide(y + 2 * size, x + size, size);
                divide(y + 2 * size, x + 2 * size, size);
                return;
            }
        }
    }
    if (check == 0) {
        zero++;
    }
    else if (check == 1) {
        one++;
    }
    else {
        mi++;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, x;
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> x;
            v[i].push_back(x);
        }
    }
    divide(0, 0, n);
    cout << mi << '\n';
    cout << zero << '\n';
    cout << one << '\n';
}
