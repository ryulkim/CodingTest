#include <iostream>
#include <vector>
using namespace std;

vector<vector<char>> data0;

int solution(int m, int x0, int y0, int mode)
{
   if(mode == 0)
    for(int x = x0 ; x < x0 + m ; x++)
     for(int y = y0 ; y < y0 + m ; y++)
      data0[x][y] = ' ';

    else if(m > 1)
    {
     solution(m/3,x0,y0,1);solution(m/3, x0 +m/3, y0,1);solution(m/3, x0 + 2*m/3, y0,1);
     solution(m/3,x0,y0+m/3,1);solution(m/3,x0 + m/3, y0 +m/3,0);solution(m/3,x0 +2*m/3,y0 +m/3,1);
     solution(m/3,x0,y0+2*m/3,1);solution(m/3,x0 + m/3,y0 + 2*m/3,1);solution(m/3,x0 +2*m/3,y0 +2*m/3,1);
    }  
   
  return 0;
}

int main(void)
{
 int m; cin >> m; data0.assign(m,vector<char>(m,'*'));
 solution(m,0,0,1);

 for(int x = 0 ; x < m ; x++){
   for(int y = 0; y < m; y++)
      cout << data0[x][y];
   
   cout << "\n";
 } 

 return 0;
}
