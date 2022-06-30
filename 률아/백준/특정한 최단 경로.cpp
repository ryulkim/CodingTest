#include <iostream>
#include <vector>
#include <queue>
#include <string.h>
#define INF 213906214
using namespace std;

vector<pair<int, int>> v[1005];//[i]: j, 시간

int n,m;

void dick(int start, int des, int dis[]){
  
  priority_queue<pair<int,int>> pq;//시간, j
  pq.push({0,start});
  dis[start]=0;

  while(!pq.empty()){
    int time=-pq.top().first;
    int d=pq.top().second;
    pq.pop();

    if(dis[d]<time){
      continue;
    }
    dis[d]=time;

    for(int i=0;i<v[d].size();i++){
      pq.push({-(v[d][i].second+dis[d]),v[d][i].first});
    }
  }

}

int answer(int startTox[], int xToy, int yTodes[], int x, int y){
  if(startTox[x]>=INF){
    return -1;
  }
  if(xToy>=INF){
    return -1;
  }
  if(yTodes[n]>=INF){
    return -1;
  }
  return startTox[x]+xToy+yTodes[n];
}

int main(){
  int a,b,c,x,y;
  int startTox[805]={0,};
  int xToy[805]={0,};
  int yTodes[805]={0,};
  int xTodes[805]={0,};
  cin>>n>>m;
  
  memset(startTox,0x7f,sizeof(startTox));
  memset(xToy,0x7f,sizeof(xToy));
  memset(yTodes,0x7f,sizeof(yTodes));
  memset(xTodes,0x7f,sizeof(yTodes));
  
  for(int i=0;i<m;i++){
    cin>>a>>b>>c;
    v[a].push_back({b,c});
    v[b].push_back({a,c});
  }
  cin>>x>>y;

  dick(1,x,startTox);
  dick(x,y,xToy);
  dick(y,n,yTodes);
  dick(x,n,xTodes);
  
  int first=answer(startTox,xToy[y],yTodes,x,y);
  int sec=answer(startTox,xToy[y],xTodes,y,x);

  if(first==-1){
    if(sec==-1){
      cout<<-1<<'\n';
    }
    else{
      cout<<sec<<'\n';
    }
  }
  else if(sec==-1){
    if(first==-1){
      cout<<-1<<'\n';
    }
    else{
      cout<<sec<<'\n';
    }
  }
  else if(first>sec){
    cout<<sec<<'\n';
  }
  else{
    cout<<first<<'\n';
  }
}
