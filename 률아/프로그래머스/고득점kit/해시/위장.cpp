#include <string>
#include <vector>

using namespace std;
vector<vector<pair<string, int>>> v(30);

int solution(vector<vector<string>> clothes) {
    int answer = 0;
    int num = clothes.size();
    for (int i = 0; i < num; i++) {
        int idx = clothes[i][1][0] - 'a';
        int sz = v[idx].size();
        if (sz == 0) {
            v[idx].push_back({ clothes[i][1],1 });
        }
        for (int j = 0; j < sz; j++) {
            if (v[idx][j].first == clothes[i][1]) {
                v[idx][j].second += 1;
                break;
            }
            else if (v[idx][j].first != clothes[i][1] && (sz - 1) == j) {
                v[idx].push_back({ clothes[i][1],1 });
            }
        }
    }
    int sum = 1;
    for (int i = 0; i < 27; i++) {
        for (int j = 0; j < v[i].size(); j++) {
                sum *= (v[i][j].second + 1);
        }
                 
    }
    answer = sum-1;

    return answer;
}
