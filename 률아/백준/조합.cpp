#include <iostream>
#include <algorithm>
using namespace std;
string dp[101][105];

string addNum(string a, string b) {
    string result = "";
    int carry = 0;
    int i = 0;
    int al = a.length(), bl = b.length();

    while (i < al || i < bl) {
        int sum = 0;
        if (i < al && i < bl) {
            sum = a[al - i - 1] + b[bl - i - 1] - '0' - '0'+carry;
            result += sum % 10 + '0';
            carry = sum / 10;
        }
        else if (i < al) {
            sum= a[al - i - 1] + carry - '0';
            result += sum % 10 + '0';
            carry = sum / 10;
        }
        else {
            sum = b[bl - i - 1] + carry - '0';
            result += sum % 10 + '0';
            carry = sum / 10;
        }
        i++;
    }
    if (carry != 0) {
        result += carry + '0';
    }
    reverse(result.begin(), result.end());

    return result;
}

string pascal(int n, int m) {
    if (n == m || m == 0) {
        return "1";
    }
    if (dp[n][m] != "") {
        return dp[n][m];
    }
    dp[n][m] = addNum(pascal(n - 1, m - 1), pascal(n - 1, m));
    return dp[n][m];
}

int main() {
    int n, m;
    cin >> n >> m;

    cout << pascal(n, m) << '\n';
}
