#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


vector<pair<int,int>> resource;
int m;


bool checking(pair<int,int>i , pair<int,int>j)
{
 return i.first > j.first;
}


int solution()
{
 int inha_resource = 0;
 int bi_resource = 0;

 for(int x = resource.size()-1 ; x > resource.size()-1 - (int)m/2; x--)
   bi_resource += resource[x].second;

 for(int x = 0 ; x < m - (int)m/2; x++)
   inha_resource += (resource[x].first+ resource[x].second);
 
 return inha_resource - bi_resource;
}



int main(void)
{
 ios_base::sync_with_stdio(false); 
 cin.tie(NULL); 
 cout.tie(NULL);

 int t; cin >> t;
 for(int x = 0 ; x < t ; x++) //CASE
 {
  resource.resize(0);

  cin >> m;
  for(int y = 0 ; y < m ;y++) //RES_INPUT
  {
   int i1,b1; cin >> i1 >> b1;
   resource.push_back(pair<int,int>(i1-b1,b1));
  }
   
  sort(resource.begin(),resource.end(),checking);
  cout << solution() << "\n";
 }
 return 0;
}
