#include <iostream>
using namespace std;

int main() {
    int t, n;
    cin >> t;
    for (int i = 0; i < t; i++) {
        cin >> n;
        int arr[12] = { 0, };
        arr[1] = 1;
        arr[2] = 2;
        arr[3] = 4;
        for (int j = 4; j <= n; j++) {
            arr[j] = arr[j - 1] + arr[j - 2] + arr[j - 3];
        }
        cout << arr[n] << endl;
    }
}
