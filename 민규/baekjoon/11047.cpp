#include <iostream>
#include <vector>
using namespace std;



vector<int> data0;

int main(void)
{
 int m,cash; cin >> m >> cash;
 int answer = 0;

 for(int x= 0 ; x < m ; x++)
 {
  int m_a; cin >> m_a;
  data0.push_back(m_a);
 }

 while(cash > 0 && data0.size()  > 0)
 {
    
  if(data0.back() <= cash)
  {
    answer += cash/data0.back();
    cash -= data0.back()*(cash/data0.back());
  }

  data0.pop_back();
 }

 cout << answer << "\n";
 return 0;
}
