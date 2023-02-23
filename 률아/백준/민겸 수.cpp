#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;


int main(){
  string s;
  string max="", min="";

  cin>>s;
  reverse(s.begin(), s.end());

  int len=s.length();

  string temp="";
  
  for(int i=0;i<len;i++){
    if(s[i]=='K'){
      if(temp!=""){
        max=temp+max;
      }
      temp="5";
    }
    else{
      if(temp!=""){
        temp+='0';
      }
      else{
        max="1"+max;
        temp="";
      }
    }
  }
  max=temp+max;

  temp="";
  for(int i=0;i<len;i++){
    if(s[i]=='K'){
      if(temp!=""){
        min=temp+min;
      }
      min='5'+min;
      temp="";
    }
    else{
      if(temp!=""){
        temp+='0';
      }
      else{
        temp="1";
      }
    }
  }
  min=temp+min;
  
  cout<<max<<'\n';
  cout<<min<<'\n';
}
