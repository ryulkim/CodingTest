#include <iostream>
#include <algorithm>
using namespace std;

int LCS[1005][1005];

int main() {
    string fir, sec;
    cin >> fir >> sec;
    fir = ' ' + fir; sec = ' ' + sec;
    int fl = fir.length();
    int sl = sec.length();
   
    int M = 0;
    for (int i = 1; i < fl; i++) {
        for (int j = 1; j < sl; j++) {
            if (fir[i] != sec[j]) {
                LCS[i][j] = max(LCS[i - 1][j], LCS[i][j - 1]);
            }
            else {
                LCS[i][j] = LCS[i - 1][j - 1] + 1;
            }
            M = max(M, LCS[i][j]);
        }
    }
    cout << M << '\n';
}
