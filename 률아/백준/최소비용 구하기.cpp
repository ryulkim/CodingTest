#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <string.h>
using namespace std;

vector<pair<int,int>> v[1002];
long long int bus[1002]={0,};
bool chk[1002]={0,};

void bfs(int start){
  priority_queue<pair<int,int>> pq;
  pq.push({0,start});
  
  while(!pq.empty()){
    int val=-pq.top().first;
    int idx=pq.top().second;
    pq.pop();
    
    if(bus[idx]<val){
      continue;
    }
    for(int i=0;i<v[idx].size();i++){
      int des=v[idx][i].first;
      
      if(bus[des]>bus[idx]+v[idx][i].second){
        bus[des]=bus[idx]+v[idx][i].second;
        pq.push({-bus[des], des});
      }
    }
    chk[idx]=1;
  }
}

int main(){
  int n, r, a, b, c;
  int f,s;
  cin>>n>>r;

  memset(bus,0x7f,sizeof(bus));
  
  for(int i=0;i<r;i++){
    cin>>a>>b>>c;
    v[a].push_back(make_pair(b,c));
  }
  cin>>f>>s;

  bus[f]=0;
  bfs(f);
  cout<<bus[s]<<'\n';
}
