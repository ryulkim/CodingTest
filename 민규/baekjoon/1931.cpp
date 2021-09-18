#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<pair<int,int>> data0;


bool sort_a(pair<int,int>a, pair<int,int> b)
{
 if(a.second == b.second)
  return a.first < b.first;

 return a.second < b.second;
}

int main(void)
{
 int m; cin >> m; int answer = 0;

 for(int x = 0 ; x < m ; x++)
 {
  int a,b; cin >> a >> b; 
  data0.push_back(pair<int,int>(a,b));
 }

 sort(data0.begin(), data0.end(),sort_a);

 int check = -1;
 for(auto x = data0.begin() ; x != data0.end() ; x++)
 {
  if(x->first >= check)
  {
   answer++; check = x->second;
  }
 }

 cout << answer << "\n";
 return 0; 
}
