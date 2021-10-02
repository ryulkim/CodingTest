#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> data0(101,vector<int>(11,0));
const int size_a = 1000000000;
const int size_b = 10;


int main(void)
{
 int m; cin >> m;

 for(int x = 1; x < size_b ; x++)
 {
  data0[1][x] = 1;
  data0[1][10] += data0[1][x];
 }

 for(int x = 2; x <= m; x++)
 {
  for(int y =  0; y < size_b ; y++)
  {
   if(y == 0) data0[x][y] = (data0[x][y] + data0[x-1][1])%size_a;

   else if(y == size_b -1) data0[x][y] = (data0[x][y] + data0[x-1][8])%size_a;

   else data0[x][y] = (data0[x][y] + data0[x-1][y-1] + data0[x-1][y+1])%size_a;
  
   data0[x][10] = (data0[x][10] + data0[x][y])%size_a;
  } 
 }
  
 cout << data0[m][10] << "\n";
 return 0;
}
