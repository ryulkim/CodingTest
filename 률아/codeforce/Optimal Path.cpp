#include <iostream>
using namespace std;

int main(){
  int t, n, m;
  cin>>t;
  for(int i=0;i<t;i++){
    cin>>n>>m;
    long long int num=0, answer=0;
    for(int j=0;j<m;j++){
      num++;
      answer+=num;
    }
    for(int j=1;j<n;j++){
      num+=m;
      answer+=num;
    }
    cout<<answer<<'\n';
  }
}
