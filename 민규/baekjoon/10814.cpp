#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

vector<pair<int,string>> data0;

bool sort_a(pair<int,string> i, pair<int,string> j)
{
 return i.first < j.first;
}

int main(void)
{
 int n; cin >> n;

 for(int x = 0 ; x < n ; x++)
 {
  int data1; string data2; cin >> data1 >> data2;
  data0.push_back(pair<int,string>(data1,data2));
 }
 
 stable_sort(data0.begin(),data0.end(),sort_a);

 for(int x = 0 ; x < n ; x++)
  cout << data0[x].first << " " << data0[x].second << "\n";

 return 0;
}
