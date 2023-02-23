#include <iostream>
#include <vector>
using namespace std;

vector<int> tr[100005];
int par[100005]={0,};
bool chk[100005]={0,};
int n;

void dfs(int start){

  chk[start]=1;
  
  int sz=tr[start].size();
  for(int i=0;i<sz;i++){
    int child=tr[start][i];
    if(chk[child]){
      continue;
    }
    par[child]=start;
    dfs(child);
  }
}

int main(){
  int a, b;
  cin>>n;
  
  for(int i=0;i<n-1;i++){
    cin>>a>>b;
    tr[a].push_back(b);
    tr[b].push_back(a);
  }
  dfs(1);

  for(int i=2;i<=n;i++){
    cout<<par[i]<<'\n';
  }
}
