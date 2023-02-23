#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void star(int i, int j, int n){
  if(i/n%3==1&&j/n%3==1){
    cout<<' ';
    return;
  }
  if(n==1){
    cout<<'*';
    return;
  }
  star(i,j,n/3);
}

int main(){
  int n, x;
  cin>>n;

  for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){
      star(i,j,n);
    }
    cout<<'\n';
  }
}
