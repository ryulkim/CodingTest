#include <string>
#include <vector>
using namespace std;

vector<pair<string,bool>> arr[27];
using namespace std;


string solution(vector<string> participant, vector<string> completion) {
    string answer = "";
    for (int i = 0; i < completion.size(); i++) {
        arr[completion[i][0] - 'a'].push_back({ completion[i],0 });
    }
    while (participant.size() > 1) {
        string s = participant.back();
        int index = s[0] - 'a';
        int parti_sz = participant.size();
        int sz = arr[index].size();
        for (int i = 0; i < sz; i++) {
            if (arr[index][i].first == s && arr[index][i].second == 0) {
                arr[index][i].second = 1;
                participant.pop_back();
                break;
            }
        }
        if (participant.back() == s && participant.size() == parti_sz) {
            answer = s;
            return answer;
        }
    }
    answer = participant.back();
    return answer;
}
