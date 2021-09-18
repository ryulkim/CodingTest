#include <vector>
#include <iostream>
using namespace std;

vector<string> data1 = {"factor" ,"multiple", "neither"};

int main(void)
{
 while(true)
 { 
  int a,b; cin >> a >> b;

  if(a == 0 && b == 0)
   break;

  if(b%a == 0)
   cout << data1[0] << "\n"; 
  
  else if(a%b == 0)
   cout << data1[1] << "\n";

  else
   cout << data1[2] << "\n"; 
 }

 return 0;
}
