#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool cmp(int r1,int r2){
    return r1>r2;
}

string solution(string s) {
    string answer = "";
    int size=s.length();
    vector<int> v;
    for(int i=0;i<size;i++){
        v.push_back(int(s.at(i)));
    }
    sort(v.begin(),v.end(),cmp);
    for(int i=0;i<size;i++){
        answer+=char(v.at(i));
    }
    return answer;
} 
