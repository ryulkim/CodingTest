#include <iostream>
#include <list>
using namespace std;

list<int> data0;

int main(void)
{
 int m; cin >> m;
 for(int x = 1; x <= m ; x++)
  data0.push_back(x);

 while(data0.size() > 1)
 {
  data0.pop_front(); int a = data0.front();
  data0.push_back(a); data0.pop_front(); 
 }

 cout << data0.back() << "\n";
 return 0;
}
