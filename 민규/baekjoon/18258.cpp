#include <iostream>
#include <list>
using namespace std;

list<int> data0;

int main(void)
{
 int m; cin >> m;
 ios_base::sync_with_stdio(false); 
 cin.tie(NULL); cout.tie(NULL);

 for(int x = 0 ; x< m ; x++)
 {
  string s; cin >> s;

  if(s=="push")
  {
   int a; cin >> a;data0.push_back(a);
  }

  else if(s=="pop")
  {
   if(data0.empty())
    cout << -1 << "\n";

   else
   {
    cout << data0.front() << "\n"; data0.pop_front();
   }
  }

  else if(s=="size")
   cout << data0.size() << "\n";

  else if(s=="empty")
  {
   if(data0.empty())
    cout << 1 << "\n";

   else cout << 0 << "\n"; 
  } 

  else if(s=="front") 
  {
   if(data0.empty())
    cout << -1 << "\n";

   else
   {
    cout << data0.front() << "\n";
   }
  }

  else
  {
   if(data0.empty())
    cout << -1 << "\n";

   else
   {
    cout << data0.back() << "\n";
   }
  }
 }


 return 0;
}
