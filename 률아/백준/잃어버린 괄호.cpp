#include <iostream>
#include <stack>
using namespace std;

int main() {
    string s, temp = "";
    stack<int> num;
    stack<char> arith;
    cin >> s;
    int sum = 0;
    for (int i = 0; i < s.length(); i++) {
        if (s[i] == '+' || s[i] == '-') {
            arith.push(s[i]);
            num.push(atoi(temp.c_str()));
            temp = "";
        }
        else {
            temp += s[i];
        }
    }
    num.push(atoi(temp.c_str()));
    int hap = 0;
    while (!num.empty()) {
        if (arith.empty()) {
            sum =sum+hap+num.top();
            num.pop();
        }
        else {
            char top = arith.top();
            if (top == '+') {
                hap += num.top();
                arith.pop();
                num.pop();
            }
            else if (top == '-') {
                hap += num.top();
                arith.pop();
                num.pop();
                sum -= hap;
                hap = 0;
            }
        }
    }
    cout << sum << endl;
}
