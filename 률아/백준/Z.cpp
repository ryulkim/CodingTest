#include <iostream>
#include <cmath>
using namespace std;

int num, r, c, check;

void divide(int y, int x, int sz) {
    if (y == r && x == c) {
        cout << num << '\n';
        return;
    }
    if (y + sz > r && x + sz > c&&y<=r&&x<=c) {
        if (sz != 1) {
            sz /= 2;
            divide(y, x, sz);
            divide(y, x + sz, sz);
            divide(y + sz, x, sz);
            divide(y + sz, x + sz, sz);
        }
    }
    else {
        num += sz * sz;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n >> r >> c;
    divide(0, 0, 1 << n);
}
