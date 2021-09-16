#include <iostream>
using namespace std;


int main(void)
{
 int a,b; cin >> a >> b;

 cout << a * (b%10) << "\n";
 cout << a * (b/10%10) << "\n";
 cout << a * (b/100) << "\n";
 cout << a*b << "\n";
 return 0;
}
