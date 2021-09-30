#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

vector<int> data0;

int main(void)
{
 data0.assign(1000001,0);

 int m ; cin >> m; data0[0] = 0;

 if(m==1) {cout << 0 << "\n"; return 0;}

 data0[1] = 1; data0[2] = 1; data0[3] = 1;

 for(int x = 4; x <= m ; x++){
  data0[x] = min(data0[x/2] + data0[2] + x%2, data0[x/3] + data0[3]+ x%3);
 }
  
 cout << data0[m] << "\n";
 return 0;
}
