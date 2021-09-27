#include <iostream>
#include <string>
using namespace std;

string solution(int n)
{
 int x = 666; int index = 0; string s = "666";

 while(true)
 {
  if(to_string(x).find(s) != string::npos)
   index++;
   

  if(n == index)
   return to_string(x);

  x++;
 }
 
 return s;
}

int main(void)
{
 int n; cin >>n; cout << solution(n) << "\n";
 return 0;
}
