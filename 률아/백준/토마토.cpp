#include <iostream>
#include <queue>
using namespace std;

int m, n, mv;
int zero = 0, grow = 0;
int arr[1005][1005];
queue<pair<int, int>> posi;
queue<int> q;


void bfs() {
    while (!q.empty()) {
        int i = posi.front().first;
        int j = posi.front().second;
        mv = q.front();
        posi.pop();
        q.pop();
        if (i + 1 < n && arr[i + 1][j] == 0) {
            arr[i + 1][j] = 1;
            grow++;
            posi.push(make_pair(i + 1, j));
            q.push(mv + 1);
        }
        if (j + 1 < m && arr[i][j + 1] == 0) {
            arr[i][j + 1] = 1;
            grow++;
            posi.push(make_pair(i, j + 1));
            q.push(mv + 1);
        }
        if (i - 1 >= 0 && arr[i - 1][j] == 0) {
            arr[i - 1][j] = 1;
            grow++;
            posi.push(make_pair(i - 1, j));
            q.push(mv + 1);
        }
        if (j - 1 >= 0 && arr[i][j - 1] == 0) {
            arr[i][j - 1] = 1;
            grow++;
            posi.push(make_pair(i, j - 1));
            q.push(mv + 1);
        }
    }

}

int main() {
    int x, sum;
    cin >> m >> n;
    sum = m * n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> x;
            arr[i][j] = x;
            if (x == -1) {
                zero++;
            }
            if (x == 1) {
                grow++;
                posi.push(make_pair(i, j));
                q.push(0);
            }
        }
    }
    bfs();
    if (sum == zero + grow) {
        cout << mv << '\n';
    }
    else {
        cout << -1 << '\n';
    }
}
