#include <iostream>
#include <string>
using namespace std;

string n_string;
int n;

int main(void)
{
 cin >> n;
 n_string = to_string(n);
 int answer = 0;

 for(int x = 0; x < n ; x++)
 {
  string x_string = to_string(x);
  int value = x;

  for(int y = 0 ; y < x_string.length() ; y++)
   value = value + int(x_string[y] - '0');

  if(n == value)
  {
   answer = x;
   cout << answer << endl;
   return 0;
  } 
 }
  
 cout << 0 << endl;
 return 1;
}
