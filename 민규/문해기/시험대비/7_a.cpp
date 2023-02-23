#include <iostream>
#include <vector>
using namespace std;

int count = 0;
vector<int> map0;

int dfs(vector<vector<int>> &data0, int start)
{
 for(int x = 0 ; x < data0[start].size() ; x++)
 {
  if(!map0[data0[start][x]])
  {
   map0[data0[start][x]]++; count++;
   dfs(data0,data0[start][x]);
  }
 }

 return count;
}

int solution(int n , int m)
{
 vector<int> answer(n+1,0);
 vector<vector<int>> data0(n+1,vector<int>(0,0));
 for(int x = 0 ; x < m ; x++)
 {
  int a,b; cin >> a >> b;
  data0[a].push_back(b);
 }

 for(int x = 1; x <= n ; x++)
 {
  count = 0; map0 = vector<int>(n+1,0);
  answer[x] = dfs(data0,x);
  cout << answer[x] << " ";
 }

 cout << "\n";
 return 0;
}


int main(void)
{
 ios_base::sync_with_stdio(false); cin.tie(NULL);cout.tie(NULL);

 int all_case; cin >> all_case;

 for(int x = 0 ; x < all_case ; x++)
 {
  int n,m; cin >> n >> m;
  solution(n,m);
 }

 return 0;
}
