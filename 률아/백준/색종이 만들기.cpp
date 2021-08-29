#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> v(128);
int blue, white;

void divide(int y, int x, int size) {
    int check = v[y][x];
    for (int i = y; i < y + size; i++) {
        for (int j = x; j < x + size; j++) {
            if (check != v[i][j]) {
                int half_size = size / 2;
                divide(y, x, half_size);
                divide(y, x + half_size, half_size);
                divide(y + half_size, x, half_size);
                divide(y + half_size, x + half_size, half_size);
                return;
            }
        }
    }
    if (check == 0) {
        white++;
    }
    else {
        blue++;
    }
}

int main() {
    int n, x;
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> x;
            v[i].push_back(x);
        }
    }
    divide(0, 0, n);
    cout << white << endl;
    cout << blue << endl;
}
