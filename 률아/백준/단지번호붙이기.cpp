#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int num = 0, mv = 0, n;
vector<int> v;
bool arr[30][30];
bool check[30][30];

void dfs(int i, int j) {
    mv++;
    check[i][j] = 1;
    if (i + 1 < n && arr[i + 1][j] == 1 && check[i + 1][j] == 0) {
        dfs(i + 1, j);
    }
    if (j + 1 < n && arr[i][j + 1] == 1 && check[i][j + 1] == 0) {
        dfs(i, j + 1);
    }
    if (i - 1 >= 0 && arr[i - 1][j] == 1 && check[i - 1][j] == 0) {
        dfs(i - 1, j);
    }
    if (j - 1 >= 0 && arr[i][j - 1] == 1 && check[i][j - 1] == 0) {
        dfs(i, j - 1);
    }
}

int main() {
    string s;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> s;
        for (int j = 0; j < n; j++) {
            arr[i][j] = s[j] - '0';
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (arr[i][j] && !check[i][j]) {
                num++;
                dfs(i, j);
                v.push_back(mv);
                mv = 0;
            }
        }
    }
    sort(v.begin(), v.end());
    cout << num << '\n';
    for (int i = 0; i < v.size(); i++) {
        cout << v[i] << '\n';
    }
}
