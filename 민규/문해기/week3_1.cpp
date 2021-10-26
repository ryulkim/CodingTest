#include <iostream>
#include <vector>
using namespace std;


int dfs(vector<vector<int>> &data0, int len,int s0)
{
 data0[s0].front() += len;

 for(int x = 1 ; x < data0[s0].size() ; x++)
 {
  dfs(data0,data0[s0].front() + 1, data0[s0][x]);
 }

 return 0;
}

int solution(int n)
{
 vector<vector<int>> data0(n+1, vector<int>(1,0));
 for(int x = 1 ; x < n ; x++)
 {
  int a,b; cin >> a >> b; data0[a].push_back(b);
 } //0

 for(int x = 1 ; x <= n ; x++)
 {
  string s; cin >> s; data0[x].front() = s.length(); 
 } //name

 dfs(data0,0,1);

 for(int x = 1 ; x <= n ; x++)
 {
  cout << data0[x].front() << "\n";
 }

 return 0;
}

int main(void)
{
 int all_case; cin >> all_case;

 for(int x = 0 ; x < all_case ; x++)
 {
  int n; cin >> n; solution(n);
 }

 return 0;
}
