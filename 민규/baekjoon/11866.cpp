#include <iostream>
#include <list>
using namespace std;

list<int> data0; int m;

list<int>::iterator what_data(int n)
{
 auto y = data0.begin();
 for(int x= 0 ; x < n ;x++)
  y++;

 return y;
}

int index01(int n)
{
 if(n == 0) return m;
 return n;
}

int main(void)
{
 int n; cin >> m >> n;

 for(int x = 1; x <= m ; x++)
  data0.push_back(x);

 int answer = index01(n%data0.size())-1;cout << "<"; 
 while(data0.size() > 1)
 {
   cout << *what_data(answer) << ", "; data0.erase(what_data(answer));
   answer = (answer + n-1)%data0.size();
 }
  
 cout << data0.back() << ">\n"; 
}
