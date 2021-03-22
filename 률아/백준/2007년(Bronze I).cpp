#include <iostream>
#include <string>
using namespace std;
int main() {
    int day[13] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
    string str[8] = { "MON","TUE","WED","THU","FRI","SAT","SUN" };
    int x, y;
    cin >> x >> y;
    int d = 0;
    for (int i = 0; i < x-1; i++) {
        d += day[i];
    }
    d += y;
    int idx = (d % 7) - 1;
    if (idx == -1)idx = 6;
    cout << str[idx];
}
