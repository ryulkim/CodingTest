#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
  int n, x;
  vector<int> v;
  cin>>n;

  for(int i=0;i<n;i++){
    cin>>x;
    v.push_back(x);
  }

  sort(v.begin(), v.end());

  for(int i=0;i<n;i++){
    cout<<v[i]<<'\n';
  }
}
