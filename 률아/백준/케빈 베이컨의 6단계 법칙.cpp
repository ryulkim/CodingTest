#include <iostream>
#include <limits>
#include <algorithm>
using namespace std;

int arr[101][102];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, m, a, b;
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        fill(arr[i], arr[i] + n, numeric_limits<int>::max());
    }
    for (int i = 0; i < m; i++) {
        cin >> a >> b;
        arr[a - 1][b - 1] = 1;
        arr[b - 1][a - 1] = 1;
        arr[i][i] = 0;
    }
    int rel = 999999;
    int per=0;
    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (arr[i][k] + arr[k][j]>0&&arr[i][j] > arr[i][k] + arr[k][j]) {
                    arr[i][j] = arr[i][k] + arr[k][j];
                }
            }
        }
    }
    for (int i = 0; i < n; i++) {
        int sum = 0;
        for (int j = 0; j < n; j++) {
            sum += arr[i][j];
        }
        if (rel > sum) {
            rel = sum;
            per = i + 1;
        }
    }
    cout << per << '\n';
}
