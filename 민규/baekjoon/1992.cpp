#include <iostream>
#include <vector>
#include <numeric>
using namespace std;

vector<vector<int>>data0; string answer = "";
int solution(int x0, int y0, int m)
{
  bool check = true;
  if(m < 1) return 0;

  answer.push_back('(');
  int data1 = data0[x0][y0];
  for(int x = x0; x < x0 + m ; x++)
  {
   for(int y = y0 ; y < y0 + m ; y++)
   {
    if(data0[x][y] != data1)
    {
     check = false;
     solution(x0,y0,m/2); solution(x0,y0 + m/2,m/2);
     solution(x0 + m/2,y0,m/2); solution(x0 + m/2,y0 + m/2,m/2);
     goto loop1;
    }
   }
  } 

  loop1:; if(check) {answer.pop_back(); answer.push_back(char(data1 + 48));}
  else answer.push_back(')');
  return 0;
}


int main(void)
{
 int m; cin >> m;

 for(int x = 0 ; x < m ; x++)
 {
  vector<int> data1; 
  string data2; cin >> data2;
  for(int y  = 0 ; y < m ; y++)
  {
   data1.push_back(data2[y]-'0');
  }
  data0.push_back(data1);
 }

 solution(0,0,m); cout << answer << "\n";
 return 0;
}
