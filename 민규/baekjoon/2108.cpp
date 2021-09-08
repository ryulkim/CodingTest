#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

vector<int> data0;
vector<pair<int,int>> data02;
int sum = 0;

bool sorting(pair <int,int> p, pair <int,int> p2)
{
 if(p.second == p2.second)
  return p.first < p2.first;

 return p.second > p2.second; 
}

int solution()
{
 int d_min = *min_element(data0.begin(), data0.end());


 int a_data0 = round(sum/(double)data0.size());
 cout << a_data0 << "\n";

 int b_data0 = data0[data0.size()/2];
 cout << b_data0 << "\n";

 int c_data0;
 if(data0.size() == 1)
  c_data0 = data0[0];

 else
 {
  auto x1 = data02.begin();
  auto x2 = x1+1;

  if(x1->second > x2->second)
   c_data0 = x1->first;

  else 
   c_data0 = x2->first;
 }
 cout << c_data0 << "\n";

 int d_data0 = *max_element(data0.begin(),data0.end()) - d_min;
 cout << d_data0 << "\n";
 return 1;
}

int main(void)
{
 int m;
 cin >> m;

 for(int x = 0 ; x < m ;x++)
 { 
  int m2;
  cin >> m2;
  data0.push_back(m2);
  sum += m2;
  
  bool count = 1;
  for(auto x = data02.begin() ; x != data02.end() ; x++)
  {
   if(x->first == m2)
   {
    x->second++;
    count = false;
    break;
   }
  }
   if(count)
    data02.push_back(pair<int,int>(m2,1));
   
 }
 
 sort(data0.begin(), data0.end());
 sort(data02.begin(), data02.end(),sorting);
 solution();
 return 0;
}
