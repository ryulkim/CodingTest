#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int t, n;
    cin >> t;
    for (int i = 0; i < t; i++) {
        int arr[2][100004] = { 0, };
        int dp[2][100004] = { 0, };
        int M = 0;
        cin >> n;

        for (int i = 0; i < 2; i++) {
            for (int j = 2; j < n + 2; j++) {
                cin >> arr[i][j];
            }
        }

        for (int j = 2; j < n + 2; j++) {
            for (int i = 0; i < 2; i++) {
                int k, value;
                k = (i == 0 ? 1 : 0);
                dp[i][j] = arr[i][j] + max(dp[k][j - 1], dp[k][j - 2]);
                M = max(M, dp[i][j]);
            }
        }
        cout << M << '\n';
    }
}
