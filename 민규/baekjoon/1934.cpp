#include <iostream>
#include <algorithm>
using namespace std;

int main(void)
{
 int all_case; cin >> all_case;

 for(int y = 0 ; y < all_case ; y++){
  int a,b; cin >> a >> b;
  int x;
  for(x = min(a,b) ; x > 0 ; x--)
  {
   if(a%x == 0 && b%x == 0)
    break;
  }
  cout << a*b/x << "\n";
 }

 return 0;
}
