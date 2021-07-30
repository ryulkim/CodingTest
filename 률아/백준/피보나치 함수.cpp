#include <iostream>
using namespace std;

int main() {
    int t, n;
    int one, zero;
    
    cin >> t;
    for (int i = 0; i < t; i++) {
        cin >> n;
        int first_one = 0, first_zero = 1;
        int sec_one = 1, sec_zero = 0;
        if (n == 0) {
            one = 0; zero = 1;
        }
        else if (n == 1) {
            one = 1; zero = 0;
        }
        else {
            for (int j = 2; j <= n; j++) {
                one = first_one + sec_one;
                zero = first_zero + sec_zero;
                first_one = sec_one;
                first_zero = sec_zero;
                sec_one = one;
                sec_zero = zero;
            }
        }
        cout << zero << ' ' << one << '\n';
        
    }
}
