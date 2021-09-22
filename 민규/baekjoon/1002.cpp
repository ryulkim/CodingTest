#include <iostream>
#include <cmath>
using namespace std;

int main(void)
{
 int all_case; cin >> all_case;

 for(int x =  0 ; x < all_case ; x++)
 {
  ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
  int x1,y1,r1,x2,y2,r2; cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;

  if(pow(x2-x1,2) + pow(y2-y1,2) == 0 && r1 == r2)
   cout << -1 << "\n";

  else if(pow(x2-x1,2) + pow(y2-y1,2) == pow(r1+r2,2) || pow(x2-x1,2) + pow(y2-y1,2) == pow(max(r1,r2) - min(r1,r2),2))
   cout << 1 << "\n";

  else if(pow(x2-x1,2) + pow(y2-y1,2) > pow(r1+r2,2) || pow(x2-x1,2) + pow(y2-y1,2) < pow(max(r1,r2) - min(r1,r2),2))
   cout << 0 << "\n";

  else cout << 2 << "\n";  
 } 
 return 0;
}
