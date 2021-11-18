#include <iostream>
#include <limits>
#include <algorithm>
using namespace std;

int d[105][105];
int inf = 1e9;

int main() {
    int n, m, a, b, c;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        fill(d[i], d[i] + 1 + n, inf);
    }
    for (int i = 1; i <= m; i++) {
        cin >> a >> b >> c;
        d[a][b] = min(d[a][b], c);
    }
    for (int i = 1; i <= n; i++) {
        d[i][i] = 0;
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            for (int k = 1; k <= n; k++) {
                if (j == k)continue;
                d[j][k] = min(d[j][k], d[j][i] + d[i][k]);
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (d[i][j] >= inf) {
                cout << 0 << ' ';
            }
            else {
                cout << d[i][j] << ' ';
            }
        }
        cout << "\n";
    }
}
