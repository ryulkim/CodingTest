#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n, m, k, num;
    int i, j, x, y;
    int sum = 0;
    
    cin >> n >> m;
    vector<vector<int>> v(n,vector<int>(m,0));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> num;
            v[i][j]=num;
        }
    }
    cin >> k;
    for (int a = 0; a < k; a++) {
        cin >> i >> j >> x >> y;
        for (int b = i - 1; b < x; b++) {
            for (int c = j - 1; c < y; c++) {
                sum += v[b][c];
            }
        }
        cout << sum << endl;
        sum = 0;
    }
}
