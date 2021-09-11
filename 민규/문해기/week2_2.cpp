#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


vector<pair<int,int>> resource;
int m;
int inha_resource = 0;
int bi_resource = 0;

bool checking(pair<int,int>i , pair<int,int>j)
{
 return i.first - j.second < j.first -i.second;
}

int solution()
{ 
  inha_resource = 0;
  bi_resource = 0;

 while(!resource.empty())
  {
   inha_resource += resource.back().first;
   resource.pop_back();

   if(resource.empty()) break;
   bi_resource += resource.back().second;
   resource.pop_back();
  }
 
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
  cin >> m;
  for(int y = 0 ; y < m ;y++) //RES_INPUT
  {
   int i1,b1; cin >> i1 >> b1;
   resource.push_back(pair<int,int>(i1,b1));
  }  
  sort(resource.begin(),resource.end(),checking);
  cout << solution() << "\n";
 }
 return 0;
}
