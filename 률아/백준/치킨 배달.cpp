#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

int city[50][52];
int n, m;
int minn = 1000000;
pair<int, int> chick[15];

int distance(int i, int j) {//해당 집에서 가장 가까운 치킨거리 구하기
    int result = 1000;
    for (int a = 0; a < m; a++) {
        result = min(result, abs(chick[a].first - i) + abs(chick[a].second - j));
    }
    return result;
}

void distanceSum() {//최소 치킨 거리 합 구하기
    int sum = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (city[i][j] == 1) {
                sum += distance(i, j);
            }
        }
    }
    minn = min(minn, sum);
}

void chicken(int i, int j, int num) {//남을 치킨집 정하기
    if (num == m) {
        distanceSum();
        return;
    }
    for (; i < n; i++) {
        for (; j < n; j++) {
            if (city[i][j] == 2) {
                chick[num] = make_pair(i,j);
                chicken(i,j+1,num + 1);
            }
        }
        j = 0;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> city[i][j];
        }
    }
    chicken(0, 0, 0);
    cout << minn << '\n';
}
