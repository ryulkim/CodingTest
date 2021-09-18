#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> data0;

int main(void)
{
 int m; cin >> m; int answer =0;

 for(int x =  0 ; x < m ;x++)
 {
  int a; cin >> a;
  data0.push_back(a);
 }

 sort(data0.begin() , data0.end());

 for(auto x = data0.begin() ; x != data0.end(); x++)
 {
  answer += (*x) * m; m--;
 }

 cout << answer << "\n";
 return 0;
}
