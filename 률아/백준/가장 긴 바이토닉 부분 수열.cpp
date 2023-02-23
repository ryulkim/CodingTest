#include <iostream>
#include <vector>
using namespace std;

vector<int> v;
int front[1005];
int back[1005];

int main() {
    int n, x;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> x;
        v.push_back(x);
    }
    for (int i = 0; i < n; i++) {//앞부분
        int max = 0;
        for (int j = 0; j <= i; j++) {
            if (v[i] == 1) {
                front[i] = 1;
                continue;
            }
            if (i == j) {
                front[i]++;
            }
            else {
                if (v[j]<v[i] && front[j]>max) {
                    max = front[j];
                }
            }
        }
        front[i] += max;
    }
    for (int i = n - 1; i >= 0; i--) {//뒷부분
        int max = 0;
        for (int j = n - 1; j >= i; j--) {
            if (v[i] == 1) {
                back[i] = 1;
                continue;
            }
            if (i == j) {
                back[i]++;
            }
            else {
                if (v[j]<v[i] && back[j]>max) {
                    max = back[j];
                }
            }
        }
        back[i] += max;
    }
    int max = 0;
    for (int i = 0; i < n; i++) {
        if ((front[i] + back[i]) > max) {
            max = front[i] + back[i];
        }
    }
    cout << max - 1 << '\n';
}
