#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int m;
vector<int> data1;

int calcul(vector<vector<int>> &data0,int n,int len)
{
 data1[n] = len;

 if(data0[n].size() == 1)
  data0[0].push_back(len);

 while(data0[n].size() > 1)
 {
  calcul(data0,data0[n].back(),len + data0[data0[n].back()][0]);
  data0[n].pop_back(); 
 }

 return 0;
}

int solution(int m)
{
 vector<vector<int>> data0; data0.assign(m+1,vector<int>(1,0));
 data1.assign(m+1,0);
 
 for(int x = 1 ; x < m ; x++)
 {
   int a,b,c; cin >> a >> b >> c;
   data0[b][0] = c;
   data0[a].push_back(b);
 }

 calcul(data0,1,0);
 
 auto max_index = max_element(data0[0].begin(), data0[0].end());
 int max_a = *max_index; *max_index = 0;
 int max_b = *max_element(data0[0].begin(), data0[0].end());

 cout << max_a + max_b << "\n";
 return 0;
}

int main(void)
{
 int all_case; cin >> all_case;

 for(int x =  0; x < all_case ; x++)
 {
  cin >> m; solution(m);
 }

 return 0;
}
