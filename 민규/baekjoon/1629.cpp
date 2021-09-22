#include <iostream>
#include <vector>
using namespace std;


long long int a,b,c; vector<int> data0;
int main(void)
{
 cin >> a >> b >> c; int answer = 1;
 
 while(b > 1)
 {
  if(b%2) {answer = answer * a % c;b--;}
  a = a * a % c ; 
  b/=2;
 }

 answer = a * answer % c; cout << answer << "\n"; 
}
