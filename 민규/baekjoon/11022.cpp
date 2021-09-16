#include <iostream>
using namespace std;


int main(void)
{
 int m; cin >> m;

 for(int x = 1 ; x <= m ; x++)
 {
  int a,b; cin >> a >> b;
  cout <<  "Case #" << x << ": " << a << " + " << b << " = " << a+b << "\n";
 }

 return 0;
}
