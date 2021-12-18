#include <iostream>
#include <cmath>
using namespace std;

int m;

long long int p(long long int a, long long int b) {
    if (b == 1)return a % m;
    long long int x = p(a, b / 2);
    return  b % 2 == 0 ? (x * x) % m : (((x * x) % m)*a)%m;
}

int main() {
    int a, b;
    cin >> a >> b >> m;
    long long int x = p(a, b);
    cout << x << '\n';
}
