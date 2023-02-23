#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer;
    for(int i=0;i<commands.size();i++){
        vector<int> v;
        int a=commands[i][0];
        int b=commands[i][1];
        int c=commands[i][2];
        
        for(int j=a-1;j<b;j++){
            v.push_back(array[j]);
        }
        sort(v.begin(),v.end());
        answer.push_back(v[c-1]);
    }
    return answer;
}
