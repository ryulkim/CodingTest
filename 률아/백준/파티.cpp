#include <iostream>
#include <vector>
#include <queue>
#include <string.h>
using namespace std;

vector<pair<int, int>> v[1005];//[i]: j, 시간
int dis[1005][1005]={0,};
int times[1005]={0,};
int n;

void dick(int start, int des){
  priority_queue<pair<int,int>> pq;//시간, j
  pq.push({0,start});
  dis[start][start]=0;

  while(!pq.empty()){
    int time=-pq.top().first;
    int d=pq.top().second;
    pq.pop();

    if(dis[start][d]<time){
      continue;
    }
    dis[start][d]=time;

    for(int i=0;i<v[d].size();i++){
      pq.push({-(v[d][i].second+dis[start][d]),v[d][i].first});
    }
  }
}

int max(int x){
  for(int i=1;i<=n;i++){
    times[i]=dis[x][i]+dis[i][x];
  }

  int m=0;
  for(int i=1;i<=n;i++){
    if(m<times[i]){
      m=times[i];
    }
    //cout<<times[i]<<'\n';
  }
  return m;
}

int main(){
  int m,x,a,b,c;
  cin>>n>>m>>x;

  memset(dis,0x7f,sizeof(dis));
  
  for(int i=0;i<m;i++){
    cin>>a>>b>>c;
    v[a].push_back({b,c});
  }

  for(int i=1;i<=n;i++){
    dick(i,i);
  }
  
  cout<<max(x)<<'\n';
}
