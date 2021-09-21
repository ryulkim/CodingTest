#include <iostream>
#include <vector>
#include <numeric>
using namespace std;

vector<vector<int>>data0;
int white_answer = 0; int blue_answer = 0;

int main(void)
{
 int m; cin >> m;

 for(int x = 0 ; x < m ; x++)
 {
  vector<int> data1;
  for(int y  = 0 ; y < m ; y++)
  {
   int data2; cin >> data2;
   data1.push_back(data2);
  }
  data0.push_back(data1);
 }

 int m0 = 1;
 while(m0*2 <= m)
 {
  int x0 = 0, y0 = 0; 

  for(int x = x0; x < m; x+=m0*2)
  {
   for(int y  = y0 ; y < m; y+=m0*2)
   {
    if(data0[x][y] + data0[x][y+m0] + data0[x+m0][y] + data0[x+m0][y+m0] == 0)
     data0[x][y] == 0;

    else if(data0[x][y] * data0[x][y+m0] * data0[x+m0][y] * data0[x+m0][y+m0] == 1)
     data0[x][y] = 1;

    else
    {
     if(data0[x][y] == 1)blue_answer++; else if(data0[x][y] == 0)white_answer++;
     if(data0[x+m0][y] == 1)blue_answer++; else if(data0[x+m0][y] == 0)white_answer++;
     if(data0[x][y+m0] == 1)blue_answer++; else if(data0[x][y+m0] == 0)white_answer++;
     if(data0[x+m0][y+m0] == 1)blue_answer++; else if(data0[x+m0][y+m0] == 0)white_answer++;
     data0[x][y] = 3; 
    }  
   }
  }
  m0*=2;
 }
 
 if(data0[0][0] == 1)blue_answer++;else if(data0[0][0]==0)white_answer++;
 cout << white_answer << "\n" << blue_answer << "\n";
 return 0;
}
