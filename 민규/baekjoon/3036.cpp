#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <list>
using namespace std;

list<int> data0;
int mother = 1; int son = 1;

int gcd(int a0, int b0)
{
 int a= max(a0,b0); int b = min(a0,b0); int r = b;
 while(a%b)
 {
  r = a%b; a = b; b = r;  
 }

 return r;
}

int main(void)
{
 int m; cin >> m;
 for(int x = 0 ; x < m ; x++)
 {
  int n; cin >> n ;
  data0.push_back(n);
 }

 while(data0.size() > 1)
 {
  int a = data0.front(); data0.pop_front(); mother *= a;
  int b = data0.front(); son *= b;
  int r = gcd(mother, son); mother /= r; son /= r;
  cout << mother << "/" << son << "\n";
 }

 return 0;
}

