#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


int main(){
  vector<pair<int, int>> v;
  int a, n, m, answer=0;
  int dp[105]={0,};
  
  cin>>a;
  for(int i=0;i<a;i++){
    cin>>n>>m;
    v.push_back(make_pair(n,m));
  }
  sort(v.begin(),v.end());

  for(int i=0;i<v.size();i++){
    dp[i]=1;
    for(int j=0;j<i;j++){
      if(v[i].second>v[j].second){
        if(dp[i]<dp[j]+1){
          dp[i]=dp[j]+1;
        }
        if(answer<dp[i]){
          answer=dp[i];
        }
      }
    }
  }
  cout<<a-answer<<'\n';
}
