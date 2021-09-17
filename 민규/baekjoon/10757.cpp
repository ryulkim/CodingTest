#include <iostream>
#include <string>
using namespace std;

int main(void)
{
 string a,b; cin  >> a >> b;
 string s = "";
 
 int index = 0;
 while(a.length() >0 || b.length() > 0)
 {
  char a0,b0;

  if(a.length() == 0) a0 = '0';
  else {a0 = a.back(); a.pop_back();};

  if(b.length() == 0) b0 = '0';
  else {b0 = b.back(); b.pop_back();};

  int m = int(a0 - '0') + int(b0 - '0') + index;
  s.push_back(m%10 + '0');
  index = m/10;
 }

 if(index > 0) s.push_back(index + '0');
 for(int x = s.length()-1; x >=0 ; x--)
  cout << s[x];

 cout << "\n";
 return 0;
}
