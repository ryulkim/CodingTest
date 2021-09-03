#include <iostream>
using namespace std;

int dp[5001] = { 0, };
int main() {
    int n;
    cin >> n;
    dp[3] = 1;
    dp[5] = 1;
    for (int i = 6; i <= n; i++) {
        int three, five;
        if (dp[i - 3] > 0) {
            three = dp[i - 3] + 1;
            dp[i] = three;
        }
        if (dp[i - 5] > 0) {
            five = dp[i - 5] + 1;
            if (dp[i]==0||dp[i] > five) {
                dp[i] = five;
            }
        }
    }
    if (dp[n] == 0) {
        cout << -1 << endl;
    }
    else {
        cout << dp[n] << endl;
    }
}
