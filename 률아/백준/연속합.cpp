#include <iostream>
using namespace std;

int dp[100001];
int main() {
    int n, x, max = 0;
    cin >> n;
    cin >> x;
    dp[0] = x;
    max = x;
    for (int i = 1; i < n; i++) {
        cin >> x;
        dp[i] = x;
        if (dp[i - 1] + x > dp[i]) {
            dp[i] = dp[i - 1] + x;
        }
        if (max < dp[i]) {
            max = dp[i];
        }
    }
    cout << max << endl;
}
