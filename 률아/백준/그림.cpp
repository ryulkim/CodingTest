#include <iostream>
using namespace std;

bool arr[500][501];
bool check[500][501];

int n, m;
int num, maxim = 0, sz = 0;

void dfs(int i, int j) {
    sz++;
    check[i][j] = 1;
    if (i + 1 < n && arr[i + 1][j] == 1 && check[i + 1][j] == 0) {
        dfs(i + 1, j);
    }
    if (j + 1 < m && arr[i][j + 1] == 1 && check[i][j + 1] == 0) {
        dfs(i, j + 1);
    }
    if (i - 1 >= 0 && arr[i - 1][j] == 1 && check[i - 1][j] == 0) {
        dfs(i - 1, j);
    }
    if (j - 1 >= 0 && arr[i][j - 1] == 1 && check[i][j - 1] == 0) {
        dfs(i, j - 1);
    }
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> arr[i][j];
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (arr[i][j] && !check[i][j]) {
                dfs(i, j);
                num++;
            }
            if (maxim < sz) {
                maxim = sz;
            }
            sz = 0;
        }
    }
    cout << num << '\n';
    cout << maxim << '\n';
}
