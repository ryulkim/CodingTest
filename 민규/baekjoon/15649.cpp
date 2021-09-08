#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int n,m;

int solution(int i,vector<int> data0)
{
 if(i < m)
 {
  for(int x = 1 ; x <= n; x++)
  {
   auto x1 = find(data0.begin(), data0.end(),x);

   if(x1 == data0.end()){
    vector<int> data1;
    data1.resize((int)data0.size());
    copy(data0.begin(),data0.end(),data1.begin()); 
    data1.push_back(x);
    solution(i+1,data1);
   }
  }
 }

 else
 {
  for(auto x2 = data0.begin(); x2 != data0.end() ; x2++)
  {
   cout << *x2 << " ";
  }
  cout << "\n";
 }
  return 1; 
}


int main(void)
{
 cin >> n >> m;

 for(int x = 1 ; x <= n ; x++)
 { 
  vector<int> data1;
  data1.push_back(x);
  solution(1,data1);
 }
 
}
