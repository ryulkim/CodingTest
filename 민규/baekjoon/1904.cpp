#include <iostream>
#include <string>
#include <vector>
using namespace std;
vector<int> num;

int main(void)
{
 num.assign(1000005, 0);
 num[1] = 1;
 num[2] = 2;

 for(int x = 3 ; x < 1000005; x++)
   num[x] = (num[x-1] + num[x-2])%15746;

 int n; cin >> n; 
 cout << num[n] << "\n";
 return 0;
}
