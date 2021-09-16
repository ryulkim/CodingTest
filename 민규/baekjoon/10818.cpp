#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> data0;

int main(void)
{
 int m; cin >> m;

 for(int x = 0; x < m ; x++)
 {
  int a; cin >> a; data0.push_back(a); 
 }

 cout << *min_element(data0.begin(),data0.end()) << " " << *max_element(data0.begin(),data0.end()) << "\n";
 return 0;
}
