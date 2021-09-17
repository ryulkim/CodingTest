#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, x1;
vector<int> x;
vector<int> b(100);
vector<int> oper;
vector<int> num;
bool check = 0;

void back(int lv) {
    if (lv == n) {
        num.push_back(x1);
        return;
    }
    for (int i = 0; i < 4; i++) {
        
        if (oper[i] == 0) {
            check = 0;
            continue;
        }
        check = 1;
        oper[i]--;
        x1 = b[lv - 1];
        if (i == 0) {
            x1 += x[lv];
        }
        else if (i == 1) {
            x1 -= x[lv];
        }
        else if (i == 2) {
            x1 *= x[lv];
        }
        else {
            x1 /= x[lv];
        }
        b[lv] = x1;
        back(lv + 1);
        
        oper[i]++;
        
    }
}

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> x1;
        x.push_back(x1);
    }
    for (int i = 0; i < 4; i++) {
        cin >> x1;
        oper.push_back(x1);
    }
    x1 = x[0];
    b[0] = x[0];
    back(1);
    sort(num.begin(), num.end());
    cout << num[num.size() - 1] << endl;
    cout << num[0] << endl;
}
