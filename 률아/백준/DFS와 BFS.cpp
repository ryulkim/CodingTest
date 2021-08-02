#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int num;
vector<vector<int>> g(1001);
bool dfs_check[1001];
bool bfs_check[1001];
queue<int> q;

void dfs(int n) {
    dfs_check[n] = 1;
    cout << n << ' ';
    for (int i = 0; i < g[n].size(); i++) {
        if (dfs_check[g[n][i]] == 0) {
            dfs(g[n][i]);
        }
    }

}
void bfs(int n) {
    q.push(n);
    bfs_check[n] = 1;

    while (!q.empty()) {
        n = q.front();
        q.pop();
        cout << n << ' ';
        for (int i = 0; i < g[n].size(); i++) {
            if (bfs_check[g[n][i]] == 0) {
                q.push(g[n][i]);
                bfs_check[g[n][i]] = 1;
            }
        }
    }
}

int main() {
    int m, v;
    cin >> num >> m >> v;
    int u, w;

    for (int i = 0; i < m; i++) {
        cin >> u >> w;
        g[u].push_back(w);
        g[w].push_back(u);
    }
    for (int i = 1; i <= num; i++) {
        sort(g[i].begin(), g[i].end());
    }
    dfs(v);
    cout << "\n";
    bfs(v);
}
