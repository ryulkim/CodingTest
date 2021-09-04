#include <iostream>
using namespace std;

int dp[1001] = { 0, };
int main() {
    int n, max = 0;
    cin >> n;
    int arr[1001] = { 0, };
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        dp[i] = 1;
        for (int j = 0; j < i; j++) {
            if (arr[j]<arr[i] && (dp[j] + 1)>dp[i]) {
                dp[i] = dp[j]+1;
            }
        }
        if (dp[i] > max) {
            max = dp[i];
        }
    }
    cout << max << '\n';
}
