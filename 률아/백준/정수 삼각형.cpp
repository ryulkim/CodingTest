#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int n, x;
    cin >> n;
    int dp[500][501] = { 0, };
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= i; j++) {
            cin >> x;
            if (i - 1 >= 0 && j - 1 >= 0) {
                dp[i][j] = dp[i - 1][j - 1];
            }
            if (i - 1 >= 0 && j < i) {
                dp[i][j] = max(dp[i][j], dp[i - 1][j]);
            }
            dp[i][j] += x;
        }
    }
    int maxim = 0;
    for (int i = 0; i < n; i++) {
        if (maxim < dp[n - 1][i]) {
            maxim = dp[n - 1][i];
        }
    }
    cout << maxim << '\n';
}
