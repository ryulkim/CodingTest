#include <iostream>
#include <algorithm>
using namespace std;

int n, m, Max = 0;
int arr[10][10];
int test[10][10];

void dfs(int i, int j) {
    if (i - 1 >= 0 && test[i - 1][j] == 0) {//위
        test[i - 1][j] = 2;
        dfs(i - 1, j);
    }
    if (i + 1 < n && test[i + 1][j] == 0) {//아래
        test[i + 1][j] = 2;
        dfs(i + 1, j);
    }
    if (j - 1 >= 0 && test[i][j - 1] == 0) {//왼
        test[i][j - 1] = 2;
        dfs(i, j - 1);
    }
    if (j + 1 < m && test[i][j + 1] == 0) {//오
        test[i][j + 1] = 2;
        dfs(i, j + 1);
    }
}

void ins(int num) {
    if (num == 3) {
        int sum = 0;
        copy(&arr[0][0], &arr[0][0] + 100, &test[0][0]);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (arr[i][j] == 2) {
                    dfs(i, j);
                }
            }
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (test[i][j] == 0) {
                    sum += 1;
                }
            }
        }
        test;
        Max = max(sum, Max);
        return;
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (arr[i][j] == 0) {
                arr[i][j] = 1;
                ins(num + 1);
                arr[i][j] = 0;
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> arr[i][j];
        }
    }
    ins(0);
    cout << Max << '\n';
}
