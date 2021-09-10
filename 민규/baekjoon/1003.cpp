#include <iostream>
#include <vector>
using namespace std;

vector<int> zero_co;
vector<int> one_co;

int fibonacci(int n) {
  zero_co[n] = zero_co[n-1] + zero_co[n-2];
  one_co[n] = one_co[n-1] + one_co[n-2];
  return 0;
}

int main(void)
{
 
 zero_co.assign(41,0);
 zero_co[0] = 1; zero_co[1] = 0;

 one_co.assign(41,0);
 one_co[0] = 0; one_co[1] = 1;

 for(int x = 2 ; x < 41 ; x++)
 {
  fibonacci(x);
 }

 int m; cin >> m;
 for(int x = 0 ; x < m ; x++)
 {
  int data; cin >> data;
  cout << zero_co[data] << " " << one_co[data] << "\n";
 }

 return 0;
}
