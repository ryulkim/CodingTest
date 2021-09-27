#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<pair<int,int>> data0;

bool sort_a(pair<int,int> i, pair<int,int> j)
{
 if(i.first == j.first)
  return i.second < j.second;

 return i.first < j.first;
}

int main(void)
{
 int n; cin >> n;

 for(int x = 0 ; x < n ; x++)
 {
  int data1,data2; cin >> data1 >> data2;
  data0.push_back(pair<int,int>(data1,data2));
 }
 
 sort(data0.begin(),data0.end(),sort_a);

 for(int x = 0 ; x < n ; x++)
  cout << data0[x].first << " " << data0[x].second << "\n";

 return 0;
}
