#include <iostream>
#include <queue>
using namespace std;

vector<vector<int>> v(101);
bool checked[101] = { 0, };
queue<int> q;

void bfs(int n) {
    q.push(n);
    int x;
    while (!q.empty()) {
        x = q.front();
        checked[x] = 1;
        q.pop();
        for (int i = 0; i < v[x].size(); i++) {
            if (checked[v[x][i]] == 0) {
                q.push(v[x][i]);
            }
        }
    }
}

int main() {
    int n, m, u, w;
    int sum = 0;
    cin >> n >> m;

    for (int i = 0; i < m; i++) {
        cin >> u >> w;
        v[u].push_back(w);
        v[w].push_back(u);
    }
    bfs(1);
    for (int i = 2; i <= n; i++) {
        if (checked[i] == 1) {
            sum++;
        }
    }
    cout << sum << endl;
}
