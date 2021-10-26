#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

priority_queue<pair<int,int>> data0;
vector<int> data1;

int main(void)
{
 ios_base::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);
 int m,n;
 cin >> n >> m; //n =  block,  m = human
 data1.assign(n,0); int answer = 0;
 for(int x = 0 ; x < n ; x++)
 {
  int t1,c1; cin >> t1 >> c1;
  data0.push(pair<int,int>(-t1,-x));
  answer = max(answer,t1); data1[x] = c1;
 }

 for(int x = n; x < m ; x++)
 {
  int t1,c1; cin >> t1 >> c1;
  t1 -= data0.top().first; int x1 = -data0.top().second;

  data1[x1] += c1;
  data0.pop();
  data0.push(pair<int,int>(-t1,-x1));
  answer = max(answer,t1);
 }

 cout << answer << "\n";
 for(int x = 0 ; x < data1.size() ;x++)
  cout << data1[x] << "\n";
 
 return 0;
}
