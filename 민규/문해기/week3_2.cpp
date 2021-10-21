#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int answer = 0;
int dfs(vector<vector<int>> &data0,int s0)
{
 //cout << data0[s0][0] << " "  << data0[s0][2] << "\n";
 int stat = max(data0[s0][1], data0[s0][2]);
 answer = max(answer, data0[s0][1] + data0[s0][2]);
 stat += data0[s0].front();

 for(int x = 3 ; x < data0[s0].size(); x++)
 {
  if(data0[data0[s0][x]][2] == 0)
   data0[data0[s0][x]][2] = stat;

  else
   data0[data0[s0][x]][1] = stat;
 }

 return 0;
}

int solution(int n)
{
 answer = 0;
 vector<vector<int>> data0(n+1,vector<int>(3,0));
 
 for(int x = 1; x < n ; x++)
 {
  int a,b,c; cin >> a >> b >> c;
  data0[b].push_back(a);
  data0[b][0] = c;
 }

 for(int x = n ; x > 0 ; x--)
 {
  dfs(data0,x);
 }

 cout << answer << "\n";
 return 0;
}

int main(void)
{
 ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
 int all_case; cin >> all_case;

 for(int x = 0 ; x < all_case ; x++)
 {
  int n; cin >> n; solution(n);
 }

 return 0;
}
