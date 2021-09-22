#include <iostream>
#include <vector>
using namespace std;

vector<int> data0;
vector<pair<int,int>> data00(10001,pair<int,int>(0,0));

int main(void)
{
 vector<int> data1(10001,0);
 for(int x = 2; x < data1.size() ;x++)
 {
  int y = x;
  while(y < data1.size() && data1[y] > 1)
   y++;

  for(int z = 2; y*z < data1.size();z++)
   data1[y*z]++;
 }

 for(int x = 2; x < data1.size() ;x++)
  if(data1[x] == 0)
   data0.push_back(x);

 
 for(int x = 0; x < data0.size();x++){
  for(int y = x ; y < data0.size();y++)
  {
    if(data00[data0[x]+data0[y]].first == 0)
    {
     data00[data0[x]+data0[y]].first = data0[x]; data00[data0[x]+data0[y]].second = data0[y];
    }

    else if(data0[y] - data0[x] < data00[data0[x]+data0[y]].second - data00[data0[x]+data0[y]].first)
    {
     data00[data0[x]+data0[y]].first = data0[x]; data00[data0[x]+data0[y]].second = data0[y];
    }
  }
 }
  
 int all_case; cin >> all_case;
 for(int x = 0 ; x < all_case; x++)
 {
  int n; cin >> n; cout << data00[n].first << " " << data00[n].second << "\n";
 }

 return 0;
}
