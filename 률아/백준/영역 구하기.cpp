#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int num = 0, m, n, mv=0;
vector<int> v;
int arr[105][105];
bool check[105][105];

void dfs(int i, int j) {
    mv++;
    arr[i][j] = 1;
    if (i + 1 < n && arr[i + 1][j] == 0) {
        dfs(i + 1, j);
    }
    if (j + 1 < m && arr[i][j + 1] == 0) {
        dfs(i, j + 1);
    }
    if (i - 1 >= 0 && arr[i - 1][j] == 0) {
        dfs(i - 1, j);
    }
    if (j - 1 >= 0 && arr[i][j - 1] == 0) {
        dfs(i, j - 1);
    }
}
void square(int lx, int ly, int rx, int ry){
    for(int i=lx;i<rx;i++){
        for(int j=ly;j<ry;j++){
            arr[i][j]=2;
        }
    }
}

int main() {
  int k,lx,ly,rx,ry;
  cin>>m>>n>>k;
  for (int i = 0; i < k; i++) {
      cin >> lx>>ly>>rx>>ry;
      square(lx,ly,rx,ry);
  }
/*  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cout<<arr[i][j]<<' ';
    }
    cout<<'\n';
  }*/

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (arr[i][j]==0) {
        num++;
        //cout<<i<<' '<<j<<'\n';
        dfs(i, j);
        v.push_back(mv);
        mv = 0;
      }
    }
  }
  
  sort(v.begin(), v.end());
  cout << num << '\n';
  for (int i = 0; i < v.size(); i++) {
      cout << v[i] << ' ';
  }
}
