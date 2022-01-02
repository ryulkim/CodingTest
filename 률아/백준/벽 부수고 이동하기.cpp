#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

bool arr[1005][1005];
int check[1005][1005][2];
int n, m;

typedef struct {
    int x, y;
}S;

S moveDir[4] = { {1,0},{0,1},{-1,0},{0,-1} };

bool inside(int i, int j) {
    return (i >= 0 && i < n&& j >= 0 && j < m);
}

int bfs() {
    queue<pair<pair<int, int>, int>> q;//i j block
    q.push({ {0, 0}, 1 });
    check[0][0][1] = 1;

    while (!q.empty()) {
        int i = q.front().first.first;
        int j = q.front().first.second;
        int b = q.front().second;
        q.pop();

        if (i == n - 1 && j == m - 1) {
            return check[i][j][b];
        }

        for (int a = 0; a < 4; a++) {
            int ni = i + moveDir[a].x;
            int nj = j + moveDir[a].y;

            if (inside(ni, nj)) {
                if (arr[ni][nj] == 1 && b) {//벽이고, 블록을 아직 안뚫었을 경우
                    check[ni][nj][b - 1] = check[i][j][b] + 1;
                    q.push({ {ni,nj}, b - 1 });
                }
                if (arr[ni][nj] == 0 && check[ni][nj][b] == 0) {//방문 안한 길일 경우
                    check[ni][nj][b] = check[i][j][b] + 1;
                    q.push({ {ni,nj}, b });
                }
            }
        }
    }
    return -1;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int M = 100000;
    char x;

    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> x;
            arr[i][j] = x - '0';
        }
    }
    cout << bfs() << '\n';
}
