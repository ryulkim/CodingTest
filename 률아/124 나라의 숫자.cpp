#include <string>
#include <vector>
#include <iostream>
#include <cmath>

using namespace std;

string solution(int n) {
    string answer = "";
    int m;
    int i=0;
    long long num=0;
    while(n>0){
        m=n%3;
        n=n/3;
        if(m==0){
        num+=4*pow(10,i);
        n--;
        }
        else if(m==1){
        num+=1*pow(10,i);
        }
        else{
        num+=2*pow(10,i);
        }
        i++;
    }
    
    answer=to_string(num);
    return answer;
}
