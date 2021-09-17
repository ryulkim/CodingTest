#include <iostream>
#include <vector>
using namespace std;

vector<pair<int, int>> posi;
int arr[9][10] = { 0, };
bool check = false;

bool ins(int lev) {
    int a = posi[lev].first;
    int b = posi[lev].second;
    for (int i = 0; i < 9; i++) {
        if (i != a && arr[i][b] == arr[a][b]) {
            return false;
        }
        if (i != b && arr[a][i] == arr[a][b]) {
            return false;
        }
    }
    for (int i = a - (a % 3); i < (a - (a % 3)) + 3; i++) {
        for (int j = b - (b % 3); j < (b - (b % 3)) + 3; j++) {
            if (i != a && j != b && arr[i][j] == arr[a][b]) {
                return false;
            }
        }
    }
    return true;
}

void back(int lev) {
    if (lev != 0 && !ins(lev - 1)) {
        int a = posi[lev - 1].first;
        int b = posi[lev - 1].second;
        arr[a][b] = 0;

        return;
    }
    if (lev == posi.size()) {
        check = true;
        return;
    }
    int a = posi[lev].first;
    int b = posi[lev].second;
    for (int i = 1; i <= 10; i++) {
        if (i == 10) {
            arr[a][b] = 0;
        }
        else {
            arr[a][b] = i;
            back(lev + 1);
            if (check) {
                break;
            }
        }

    }
}

int main() {
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            cin >> arr[i][j];
            if (arr[i][j] == 0) {
                posi.push_back(make_pair(i, j));
            }
        }
    }
    back(0);
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            cout << arr[i][j] << ' ';
        }
        cout << '\n';
    }
}
