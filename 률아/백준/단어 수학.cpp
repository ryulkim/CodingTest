#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

long long int arr[30];

void argm(string s) {
    reverse(s.begin(), s.end());
    for (int i = 0; i < s.length(); i++) {
        arr[s[i] - 'A'] += pow(10, i);
    }
}

int main() {
    string s;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> s;
        argm(s);
    }
    sort(arr, arr + 28, greater<long long int>());
    int i = 0;
    long long int answer = 0;
    while (arr[i] != 0) {
        answer += arr[i] * (9 - i);
        i++;
    }
    cout << answer << '\n';
}
