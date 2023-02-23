#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
using namespace std;

int d;

long long int change_ten(vector<int> v){
  int len=v.size();
  long long int num=0;
  for(int i=0;i<len;i++){
    num+=v[i]*pow(d,len-1-i);
  }
  return num;
}

int main(){
  long long int n;

  vector<int> v;
  long long int answer=-1;
  cin>>n>>d;

  //진법 내의 숫자 구하기
  for(int i=0;i<d;i++){
    v.push_back(i);
  }
  
  //진법 내의 숫자 중 구할 수 있는 조합 계산
  do{
    if(v[0]==0)continue;
    int num=change_ten(v);
    if(num>n&&(answer==-1||answer>num)){
      answer=num;
    };
  }while(next_permutation(v.begin(), v.end()));
  
  cout<<answer<<'\n';
  
}
