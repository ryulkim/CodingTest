#include <iostream>
using namespace std;

bool wizard(string s) {
  int sz = s.size();
  int check[28]={0,};
  int idx;

  for (int j = 0; j < sz; j++) {
    if(s[j]>='A'&&s[j]<='Z'){ //대문자
      idx=s[j]-'A';
    }
    else if(s[j]>='a'&&s[j]<='z'){ //소문자
      idx=s[j]-'a';
    }
    else{
      continue;
    }
    check[idx]+=1;
    check[25-idx]+=1;
  }

  for (int j = 0; j < 26; j++) {
    if(check[j]%2==1){ //홀수
      return false; 
    }
  }
  
  return true; 
}

int main() {
  int n;
  string s;
  cin >> n;

  for (int i = 0; i < n; i++) {
    cin >> s;

    if(wizard(s)==1){
      cout<<"Yes"<<'\n';
    }
    else{
      cout<<"No"<<'\n';
    }
    
  }
}
