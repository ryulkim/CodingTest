#include <iostream>
using namespace std;

int arr[1026][1026] = { 0, };

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, m, x, ax, ay, bx, by;
    cin >> n >> m;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> x;
            arr[i][j] = arr[i][j - 1] + x;
        }
    }
    for (int i = 0; i < m; i++) {
        int sum = 0;
        cin >> ax >> ay >> bx >> by;
        for (int j = ax; j <= bx; j++) {
            sum += (arr[j][by] - arr[j][ay - 1]);
        }
        cout << sum << '\n';
    }
}
