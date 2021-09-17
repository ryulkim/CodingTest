#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;


void error_checking(vector<vector<int>> &data1, int x)
{
  for(int y = 1; y < (int)data1[x].size() ;y++)
  { 
   data1[data1[x][y]][0] += (data1[x][0] + 1);
   error_checking(data1,data1[x][y]);
  }
}

int solution(int n)
{
 vector<vector<int>> data1;
 
 
 data1.assign(n+1,vector<int>(1,0));
 for(int x = 1 ; x < n ; x++)
 {
  int a,b; cin >> a >> b;
  data1[a].push_back(b);
 }

 for(int x = 1; x <= n ; x++)
 {
  string s; cin >> s;
  data1[x][0] = s.length();
 }

 error_checking(data1,1);

 for(int x = 1 ; x <= n ; x++)
  cout << data1[x][0] << "\n"; 
 
 return 0;
}

int main(void)
{
 ios_base::sync_with_stdio(false); 
 cin.tie(NULL); cout.tie(NULL);
 int all_case; cin >> all_case;

 for(int x = 0; x < all_case ; x++)
 {
  int n; cin >> n;
  solution(n);
 }

 return 0;
}
