#include <iostream>
#include <vector>
using namespace std;


int main(void)
{
 int a,b,v; cin >> a >> b >> v;
 int answer = 0;

 while(v){
  int day0 = v/a + !!(v%a);
  answer += day0; 
  if(a*day0 - b*(day0-1) >= v)
   break;

  else v -= (a-b)*day0; 
 }
 
 cout << answer << "\n";
 return 0;
}
