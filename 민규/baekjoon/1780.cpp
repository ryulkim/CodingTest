#include <iostream>
#include <vector>
#include <numeric>
using namespace std;

vector<vector<int>>data0; vector<int> score = {0,0,0};
int solution(int x0, int y0, int m)
{
  bool check = true;
  if(m < 1) return 0;

  int data1 = data0[x0][y0];
  for(int x = x0; x < x0 + m ; x++)
  {
   for(int y = y0 ; y < y0 + m ; y++)
   {
    if(data0[x][y] != data1)
    {
     check = false;
     solution(x0,y0,m/3); solution(x0,y0 + m/3,m/3); solution(x0,y0 + 2*m/3,m/3);
     solution(x0 + m/3,y0,m/3); solution(x0 + m/3,y0 + m/3,m/3); solution(x0 + m/3,y0 + 2*m/3,m/3);
     solution(x0 + 2*m/3,y0,m/3); solution(x0 + 2*m/3,y0 + m/3,m/3); solution(x0 + 2*m/3,y0 + 2*m/3,m/3);
     goto loop1;
    }
   }
  } 

  loop1:; if(check) {score[data1+1]++;}
  return 0;
}


int main(void)
{
 int m; cin >> m;

 for(int x = 0 ; x < m ; x++)
 {
  vector<int> data1; 
  for(int y  = 0 ; y < m ; y++)
  {
   int data2; cin >> data2; data1.push_back(data2);
  }
  data0.push_back(data1);
 }

 solution(0,0,m); cout << score[0] << "\n" << score[1] << "\n" << score[2] << "\n";
 return 0;
}
