#include <iostream>
#include <cstring>
using namespace std;

bool arr[21] = { 0, };

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int m, x;
    string s;
    cin >> m;
    for (int i = 0; i < m; i++) {
        cin >> s;
        if (s == "add") {
            cin >> x;
            arr[x - 1] = 1;
        }
        else if (s == "check") {
            cin >> x;
            arr[x-1]?(puts("1")):(puts("0"));
        }
        else if (s == "remove") {
            cin >> x;
            arr[x - 1] = 0;
        }
        else if (s == "toggle") {
            cin >> x;
            arr[x-1]?arr[x-1]=0:arr[x-1]=1;
        }
        else if (s == "all") {
            memset(arr, true, sizeof(arr));
        }
        else if (s == "empty") {
            memset(arr, false, sizeof(arr));
        }
    }
}
