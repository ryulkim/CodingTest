#include <iostream>
#include <algorithm>
using namespace std;



int main(void)
{
 int a,b; cin >> a >> b;
 int x;
 for(x = min(a,b) ; x > 0 ; x--)
 {
  if(a%x == 0 && b%x == 0)
   break;
 }

 cout << x << "\n"; cout << a*b/x << "\n";
 return 0;
}
