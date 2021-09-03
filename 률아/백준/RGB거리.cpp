#include <iostream>
#include <algorithm>
using namespace std;

int dp[3001];
int main() {
    int n, r, g, b;
    cin >> n;
    cin >> r >> g >> b;
    dp[0] = r;
    dp[1] = g;
    dp[2] = b;
    for (int i = 1; i < n; i++) {
        cin >> r >> g >> b;
        int x, y;
        //r
        x = dp[i * 3 - 2] + r;
        y = dp[i * 3 - 1] + r;
        dp[i * 3] = min(x, y);
        //g
        x = dp[i * 3 - 3] + g;
        y = dp[i * 3 - 1] + g;
        dp[i * 3 + 1] = min(x, y);
        //b
        x = dp[i * 3 - 3] + b;
        y = dp[i * 3 - 2] + b;
        dp[i * 3 + 2] = min(x, y);
    }
    int answer;
    int i = n - 1;
    answer = min(dp[i * 3], dp[i * 3 + 1]);
    answer = min(answer, dp[i * 3 + 2]);
    cout << answer << endl;
}
