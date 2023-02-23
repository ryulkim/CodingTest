#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


int main(){
  int n,m, ans=0;
  int a,b;
  bool combi[202][202]={0,};
    
  cin>>n>>m;
  for(int i=0;i<m;i++){
    cin>>a>>b;
    combi[a][b]=1;
    combi[b][a]=1;
  }
  for(int i=1;i<=n-2;i++){
    for(int j=i+1;j<=n-1;j++){
      for(int k=j+1;k<=n;k++){
        if(!combi[i][j]&&!combi[j][k]&!combi[i][k]){
          ans++;
        }
      }
    }
  }
  
  cout<<ans<<'\n';
}
