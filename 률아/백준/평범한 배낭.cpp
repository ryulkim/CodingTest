#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

int dp[100005];
int M = 0, k;

void bag(int w, int v) {
    queue<pair<int,int>> q;
    q.push(make_pair(w, v));

    for (int i = 1; i <= k; i++) {
        if (dp[i] != 0&&i+w<=k) {
            q.push(make_pair(i + w, dp[i] + v));
        }
    }
    while (!q.empty()) {
        int w1=q.front().first, v1=q.front().second;
        dp[w1] = max(dp[w1], v1);
        M = max(M, dp[w1]);
        q.pop();
    }
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, w, v;
    cin >> n >> k;

    for (int i = 0; i < n; i++) {
        cin >> w >> v;
        if (w <= k) {
            bag(w, v);
        }
    }
    cout << M << '\n';
}
