#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool cmp(string r1, string r2){
    return r1<r2;
}

bool solution(vector<string> phone_book) {
    bool answer = true;
    sort(phone_book.begin(),phone_book.end(),cmp);
    int len=phone_book.at(0).length();
    string s=phone_book.at(0);
    for(int i=1;i<phone_book.size();i++){
        if(phone_book.at(0) == "0"){
            /*numbers가 [0,0,0,0...]인 경우*/
            answer = false;
            break;
        }
        if(len>phone_book.at(i).length()){
            len=phone_book.at(i).length();
            s=phone_book.at(i);
            continue;
        }
        if(phone_book.at(i).find(s)!=string::npos){
            return false;
        }
    }
    return answer;
}
 
