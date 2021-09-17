#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;

int main(void)
{
 int a,b,c; cin >> a >> b >> c;
 
 if(b >= c)
  cout << -1 << "\n";

 else
  cout << a/(c-b) + 1 << "\n";
 
 return 0;
}
