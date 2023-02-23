#include <iostream>
#include <vector>
using namespace std;
int dp[10003] = { 0, };
vector<int> coin;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, k, x;
    dp[0] = 1;
    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        cin >> x;
        coin.push_back(x);
    }

    for (int i = 0; i < n; i++) {
        for (int j = coin[i]; j <= k; j++) {
            dp[j] += dp[j - coin[i]];
        }
    }

    cout << dp[k] << '\n';
}
