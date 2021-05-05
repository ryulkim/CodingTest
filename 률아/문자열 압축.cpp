#include <string>
#include <vector>

using namespace std;

int solution(string s) {
    int answer = s.size();
    //int len=0;
    int num = 1;
    string result = "";
    string e = "";
    string pre = "";
    for (int i = 1; i <= s.size(); i++) {
        int j = 0;
        while( j < s.size()) {
            for (int k = 0; k < i&&j<s.size(); k++) {
                if (k == 0) {
                    e = s[j++];
                }
                else {
                    e += s[j++];
                }
            }
            if (pre != e ) {
                if (num != 1) {
                    result += to_string(num);
                    result += pre;
                }
                else if (num == 1) {
                    result += pre;
                }
                pre = e;
                num = 1;
            }
            else if (pre == e) {
                num++;
            }
        }
        if (num != 1) {
            result += to_string(num);
            result += e;
        }
        else if (num == 1) {
            result += e;
        }
        if (answer > result.length()) {
            answer = result.length();
        }
        result = "";
        e = "";
        pre = "";
        num = 1;
    }
    return answer;
}
