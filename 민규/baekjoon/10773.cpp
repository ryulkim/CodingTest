#include <iostream>
#include <vector>
using namespace std;

vector<int> data0;


int main(void)
{
 int m; cin >> m; int answer = 0;
 for(int x = 0 ; x< m ; x++)
 {
  int n; cin >> n;
  
  if(n == 0)
  {
   answer -= data0.back(); data0.pop_back();
  }

  else
  {
   answer += n; data0.push_back(n);
  }
 }

 cout << answer << "\n";
 return 0;
}
