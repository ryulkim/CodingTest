#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n, m, x, a, b;
    cin >> n >> m;
    int arr[100002] = { 0, };

    for (int i = 1; i <= n; i++) {
        cin >> x;
        arr[i] = x + arr[i - 1];
    }
    for (int i = 0; i < m; i++) {
        cin >> a >> b;
        cout << arr[b] - arr[a - 1]<<'\n';
    }
}
