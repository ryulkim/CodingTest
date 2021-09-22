#include <iostream>
#include <vector>
#include <string>
#include <cmath>
using namespace std;

vector<string> answer = {"wrong", "right"};

int main(void)
{
 int x,y,z;
 do{
  bool check = true;
  cin >> x >> y >> z; int r = max(z,max(x,y));
  if(!(x*y*z))break;
  if(r == z) check = x*x + y*y - z*z;
  else if(r == x) check = z*z + y*y - x*x;
  else if(r == y) check = x*x + z*z - y*y;

  cout << answer[!check] << "\n";
 }while(x * y * z);

 return 0;
}
