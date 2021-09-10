#include <iostream>
#include <string>
#include <vector>
using namespace std;
vector<long long int> num;

int main(void)
{
 num.assign(101, 0);
 num[1] = 1;
 num[2] = 1;
 num[3] = 1;
 num[4] = 2;
 num[5] = 2;

 for(int x = 6 ; x < 101; x++)
   num[x] = (num[x-1] + num[x-5]);
  
 int m ; cin >> m;
 for(int x = 0 ; x < m ; x++)
 {
  int n; cin >> n; 
  cout << num[n] << "\n";
 }
 return 0;
}
