#include <iostream>
using namespace std;

int arr[21][22][22];
int result;

int w(int a, int b, int c) {
    
    if (a <= 0 || b <= 0 || c <= 0) {
        return 1;
    }
    else if (a > 20 || b > 20 || c > 20) {
        if (arr[20][20][20] != 0) {
            return arr[20][20][20];
        }
        else {
            result = w(20, 20, 20);
            arr[20][20][20] = result;
            return result;
        }
    }
    else if (arr[a][b][c] != 0) {
        return arr[a][b][c];
    }
    else if (a < b && b < c) {
        result = w(a, b, c - 1) + w(a, b - 1, c - 1) - w(a, b - 1, c);
    }
    else {
        result = w(a - 1, b, c) + w(a - 1, b - 1, c) + w(a - 1, b, c - 1) - w(a - 1, b - 1, c - 1);
    }
    arr[a][b][c] = result;
    return result;
}

int main() {
    int a, b, c;
    cin >> a >> b >> c;
    while (a != -1 || b != -1 || c != -1) {
        int num = w(a, b, c);
        cout << "w(" << a << ", " << b << ", " << c << ") = " << num << '\n';
        cin >> a >> b >> c;
    }
}
