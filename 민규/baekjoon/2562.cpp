#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> data0;

int main(void)
{

 for(int x = 0; x < 9 ; x++)
 {
  int a; cin >> a; data0.push_back(a); 
 }

 cout << *max_element(data0.begin(),data0.end()) << " " << max_element(data0.begin(),data0.end()) - data0.begin() +1 << "\n";

 return 0;
}
