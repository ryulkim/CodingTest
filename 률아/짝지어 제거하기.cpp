#include <iostream>
#include <string>
#include <stack>
using namespace std;

int solution(string s)
{
    int answer=-1;
    stack<int> str;
    int len=s.length();
    for(int i=0;i<len;i++){
        if(str.empty()||str.top()!=s[i]){
            str.push(s[i]);
        }
        else{
            str.pop();
        }
    }
    
    if(str.empty()){
        answer=1;
    }
    else{
        answer=0;
    }
 
    return answer;
}
