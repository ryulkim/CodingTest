#include <iostream>
#include <queue>
using namespace std;

int n, m, mv, mini;
bool arr[105][105];
bool check[105][105];
queue<pair<int,int>> posi;
queue<int> q;

void bfs() {
    int i = 0, j = 0;
    posi.push(make_pair(0, 0));
    q.push(1);
    check[0][0] = 1;
    while (1) {
        i = posi.front().first;
        j = posi.front().second;
        mv = q.front();
        if (i == n-1 && j == m-1) {
            mini = mv;
            break;
        }
        posi.pop();
        q.pop();
        if (i + 1 < n && arr[i + 1][j]&&!check[i+1][j]) {
            posi.push(make_pair(i + 1, j));
            check[i + 1][j] = 1;
            q.push(mv + 1);
        }
        if (j + 1 < m && arr[i][j + 1] && !check[i][j + 1]) {
            posi.push(make_pair(i, j + 1));
            check[i][j+1] = 1;
            q.push(mv + 1);
        }
        if (i - 1 >= 0 && arr[i - 1][j] && !check[i - 1][j]) {
            posi.push(make_pair(i - 1, j));
            check[i - 1][j] = 1;
            q.push(mv + 1);
        }
        if (j - 1 >= 0 && arr[i][j - 1] && !check[i][j - 1]) {
            posi.push(make_pair(i, j - 1));
            check[i][j-1] = 1;
            q.push(mv + 1);
        }
    }
    
}

int main() {
    string s;
    bool check[105][105] = { 0, };
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> s;
        for (int j = 0; j < m; j++) {
            arr[i][j] = s[j] - '0';
        }
    }
    bfs();
    cout << mini << '\n';
}
