#include <iostream>
using namespace std;

void dfs(bool (*arr)[51], bool(*check)[51], int i, int j, int m, int n) {
    check[i][j] = 1;
    if (i < m - 1 && arr[i + 1][j] == 1 && check[i + 1][j] == 0) {
        dfs(arr, check, i + 1, j, m, n);
    }
    if (i > 0 && arr[i - 1][j] == 1 && check[i - 1][j] == 0) {
        dfs(arr, check, i - 1, j, m, n);
    }
    if (j < n - 1 && arr[i][j + 1] == 1 && check[i][j + 1] == 0) {
        dfs(arr, check, i, j + 1, m, n);
    }
    if (j > 0 && arr[i][j - 1] == 1 && check[i][j - 1] == 0) {
        dfs(arr, check, i, j - 1, m, n);
    }
}


int main() {
    int t, m, n, k, x, y;
    cin >> t;
    for (int i = 0; i < t; i++) {
        cin >> m >> n >> k;
        bool arr[50][51] = { 0, };
        bool check[50][51] = { 0, };
        int num = 0;
        for (int j = 0; j < k; j++) {
            cin >> x >> y;
            arr[y][x] = 1;
        }
        for (int j = 0; j < n; j++) {
            for (int l = 0; l < m; l++) {
                if (arr[j][l] == 1 && check[j][l] == 0) {
                    dfs(arr, check, j, l, n, m);
                    num++;
                }
            }
        }
        cout << num << '\n';
    }
}
