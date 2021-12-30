#include <string>
#include <vector>
#include <algorithm>
using namespace std;

string binary(int num) {
    string s = "";

    while (num != 1) {
        s += num % 2 + '0';
        num /= 2;
    }
    s += num + '0';
    reverse(s.begin(), s.end());
    return s;
}

vector<int> solution(string s) {
    vector<int> answer;

    string t = "";
    int num = 0;
    int zero=0;

    while (s != "1") {
        num++;
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == '1') {
                t += "1";
            }
            else {
                zero++;
            }
        }
        s = binary(t.length());
        t = "";
    }
    answer.push_back(num);
    answer.push_back(zero);
    return answer;
}
