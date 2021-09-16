#include <iostream>
using namespace std;


int main(void)
{
 int m,n; cin >> m >> n;
 
 n -= 45;
 if(n < 0){
  n += 60; m -= 1;
 }

 if(m < 0)
  m = 23;

 cout << m << " " << n << "\n";
 return 0; 
}
