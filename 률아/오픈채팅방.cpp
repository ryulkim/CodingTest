#include <string>
#include <vector>
#include <iostream>
#include <map>

using namespace std;

vector<string> solution(vector<string> record) {
    vector<string> answer;
    string info[2][100000];//i=> 0: 명령, 1: 아이디
    map<string, string> m;

    int idx = 0;
    string s = "";

    for (int i = 0; i < record.size(); i++) {
        for (int j = 0; j < record[i].length(); j++) {
            if (record[i][j] == ' '&&idx!=2) {
                info[idx][i] = s;
                idx++;
                s = "";
                continue;
            }
            s += record[i].at(j);
        }
        if (idx == 1) {
            info[1][i] = s;
        }
        if (s!=""&&idx==2) {
            if (m.count(info[1][i]) == 0) {
                m.insert(make_pair(info[1][i], s));
            }
            else {
                m[info[1][i]] = s;
            }
        }
        idx = 0;
        s = "";
    }
    for (int i = 0; i < record.size(); i++) {
        if (info[0][i] == "Change") {
            continue;
        }
        s = "";
        s += m[info[1][i]];
        if (info[0][i] == "Enter") {
            s += "님이 들어왔습니다.";
        }
        else if (info[0][i] == "Leave") {
            s += "님이 나갔습니다.";
        }
        answer.push_back(s);
    }
    return answer;
}
