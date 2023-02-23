#include <iostream>
#include <algorithm>
using namespace std;

int n, m;
int M = 0;
int arr[501][501];
bool check[501][501];

void dfs(int a, int b, int cnt, int sum) {
    sum += arr[a][b];
    if (cnt == 4) {
        M = max(M, sum);
        return;
    }
    check[a][b] = 1;
    if ((a - 1) >= 0 && !check[a - 1][b]) {//위
        dfs(a - 1, b, cnt + 1, sum);
        check[a - 1][b] = 0;
    }
    if ((a + 1) < n && !check[a + 1][b]) {//아래
        dfs(a + 1, b, cnt + 1, sum);
        check[a + 1][b] = 0;
    }
    if ((b - 1) >= 0 && !check[a][b - 1]) {//왼쪽
        dfs(a, b - 1, cnt + 1, sum);
        check[a][b - 1] = 0;
    }
    if ((b + 1) < m && !check[a][b + 1]) {//오른쪽
        dfs(a, b + 1, cnt + 1, sum);
        check[a][b + 1] = 0;
    }
}

void shapeN(int a, int b) {
    int sum;
    if ((a + 1) < n && (b + 2) < m) {
        sum = (arr[a][b] + arr[a + 1][b + 1] + arr[a][b + 1] + arr[a][b + 2]);
        M = max(M, sum);
    }
}

void shapeJ(int a, int b) {
    int sum;
    if ((a - 1) >= 0 && (a + 1) < n && (b + 1) < m) {
        sum = (arr[a][b] + arr[a + 1][b + 1] + arr[a][b + 1] + arr[a - 1][b + 1]);
        M = max(M, sum);
    }
}

void shapeK(int a, int b) {
    int sum;
    if ((a - 1) >= 0 && (a + 1) < n && (b + 1) < m) {
        sum = (arr[a][b] + arr[a + 1][b] + arr[a][b + 1] + arr[a - 1][b]);
        M = max(M, sum);
    }
}

void shapeH(int a, int b) {
    int sum;
    if ((a - 1) >= 0 && (b + 2) < m) {
        sum = (arr[a][b] + arr[a][b + 1] + arr[a][b + 2] + arr[a - 1][b + 1]);
        M = max(M, sum);
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
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            dfs(i, j, 1, 0);
            check[i][j] = 0;
            shapeN(i, j);
            shapeJ(i, j);
            shapeK(i, j);
            shapeH(i, j);
        }
    }
    cout << M << '\n';
}
