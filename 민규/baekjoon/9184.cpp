#include <iostream>
#include <vector>
using namespace std;


vector<vector<vector<int>>> data0;

int w(int a, int b, int c)
{
 if(a <= 0 || b <= 0 || c <=0)
  return 1;

 else if(a > 20 || b > 20 || c >20)
  return data0[20][20][20];

 else if(a<b && b <c)
  return data0[a][b][c-1] + data0[a][b-1][c-1] - data0[a][b-1][c];

 else
  return data0[a-1][b][c] + data0[a-1][b-1][c] + data0[a-1][b][c-1] - data0[a-1][b-1][c-1];
}

int solution(int a, int b, int c)
{
 if(a <= 0 || b <= 0 || c <=0)
  return 1;

 else if (a > 20 || b > 20 || c >20)
  return data0[20][20][20];

  else return data0[a][b][c];
}


int main(void)
{
 ios_base::sync_with_stdio(false); 
 cin.tie(NULL); 
 cout.tie(NULL);
 data0.assign(21,vector<vector<int>>(21,vector<int>(21,0)));
 for(int x = 0 ; x <= 20 ; x++)
  for(int y = 0 ; y <= 20 ; y++)
   for(int z = 0; z <= 20 ; z++) 
     data0[x][y][z] = w(x,y,z); 
   
  while(true)
  {
   int a,b,c; cin >> a >> b >> c;

   if(a == -1 && b == -1 && c ==-1)
    break;

   else
    cout << "w(" << a << ", " << b << ", " << c << ") = " << solution(a,b,c) << "\n";  
  }  

 return 0;
}
