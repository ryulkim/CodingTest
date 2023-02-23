#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;


vector<int> v;

void prime(){
    sort(v.begin(),v.end());
    int lim=sqrt(v.back());
    int n=v.size();

    for(int i=2;i<=lim;i++){
        for(int j=0;j<n;j++){
            if(v[j]!=0&&v[j]%i==0&&v[j]!=i){
                v[j]=0;
            }
        }
    }
}

void number(string s, string rest){
    int n=rest.size();
    if(s!=""){
        v.push_back(atoi(s.c_str()));
    }
    
    for(int i=0;i<n;i++){
        number(s+rest[i],rest.substr(0,i)+rest.substr(i+1));
    }
}



int solution(string numbers) {
    int answer = 0;
    number("", numbers);
    prime();

    sort(v.begin(), v.end());
    v.erase(unique(v.begin(), v.end()), v.end());
    int n = v.size();

    for (int i = 0; i < n; i++) {
        if (v[i] >= 2) {
            answer++;
        }
    }

    return answer;
}
