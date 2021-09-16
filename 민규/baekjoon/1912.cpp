#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> data0;

int main(void)
{
 
 int m; cin >> m;
 int data01; cin >> data01; data0.push_back(data01);
 int answer = data0.back();

 for(int x = 1 ; x < m ; x++)
 {
  cin >> data01;

  if(data0.back() >= 0)
   data0.back() += data01; 
   
  else{
   data0.pop_back(); data0.push_back(data01);
  }  

  answer = (data0.back() > answer)? data0.back() : answer;         
 }

 cout << answer << "\n";
 return 0;
}
