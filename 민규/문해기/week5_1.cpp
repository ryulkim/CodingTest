#include <iostream>
#include <vector>
using namespace std;

int solution(int m)
{
 vector<int> data2; data2.push_back(0);
 vector<int> data3; data3.push_back(1);
 int answer = m;

 for(int x = 1; x <= m ;x++)
 {
  int data1; cin >> data1; 
  if(x > 1 && data1 == data2[1]){
    data3.push_back(x-1);
  }
    
  data2.push_back(data1);
 }

 for(int x = 0; x < data3.size() ; x++)
 {
  data2[0] = data2[data3[x]];
  bool check = true;

  for(int y = data3[x]+1; y < data2.size() ; y++)
   if(data2[y] != data2[y % data3[x]])
   {
    check = false; break;
   }
  
  if(check)
  {
   answer = data3[x]; break;
  }
 }

 for(int y = 1; y <= answer; y++)
  cout << data2[y] << " ";
 cout << "\n";

 return 0;
}

int main(void)
{
 ios_base::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);
 int all_case; cin >> all_case;

 for(int x =  0 ;x < all_case ; x++)
 {
  int m ; cin >> m;solution(m);
 }
 return 0;
}
