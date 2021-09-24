#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> data0;

int main(void)
{
 
 ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
 int m,n; cin >> m;

 for(int x = 0 ; x < m ; x++)
 {
  int data1; cin >> data1; data0.push_back(data1);
 }

 sort(data0.begin(),data0.end()); cin >> n;
 for(int x = 0 ; x < n ; x++)
 {
  int data1; cin >> data1; string a = (x == n-1)? "\n":" ";
  cout << upper_bound(data0.begin(),data0.end(),data1) - lower_bound(data0.begin(), data0.end(),data1) << a;
 }
 
 return 0;
}
