#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> data0;

int main(void)
{
 int answer = 10;
 data0.assign(43,0);

 for(int x = 0; x < 10 ; x++)
 {
  int a; cin >> a;
  if(data0[a%42] > 0)
   answer--;

  data0[a%42]++; 
 }

 cout << answer << "\n";
 return 0;
}
