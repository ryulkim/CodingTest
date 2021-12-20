#include <iostream>
#include <algorithm>
using namespace std;
int arr[10002][2];//행: 포도주, 열: 연속 개수
int glass[10002];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int n, x, M = 0, sec=0;
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> glass[i];
    
    arr[0][0] = glass[0]; arr[1][0] = glass[1]; arr[1][1] = glass[0] + glass[1];
    M = max(arr[0][0], arr[1][0]); M = max(M, arr[1][1]);

    for (int i = 2; i < n; i++) {
        if (sec < max(arr[i - 2][0], arr[i - 2][1])) {
            sec = max(arr[i - 2][0], arr[i - 2][1]);
        }
        arr[i][0] = sec + glass[i]; arr[i][1] = arr[i - 1][0] + glass[i];
        
        if (M < max(arr[i][0], arr[i][1]))
            M = max(arr[i][0], arr[i][1]);
    }
    cout << M << '\n';
}
