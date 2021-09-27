#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

vector<pair<int,int>> data0;

bool sort_a(pair<int,int> i, pair<int,int> j)
{
 return i.first < j.first;
}

bool sort_b(pair<int,int> i, pair<int,int> j)
{
 return i.second < j.second;
}

int main(void)
{
 ios_base::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);
 int n; cin >> n;

 for(int x = 0 ; x < n ; x++)
 {
  int data1; cin >> data1;
  data0.push_back(pair<int,int>(data1,x));
 }
 
 sort(data0.begin(),data0.end(),sort_a);

 int y = 0;
 for(int x = 0 ; x < n ; x++){
  int z = data0[x].first;
  while(x<n && data0[x].first == z)
  {
   data0[x].first = y;x++;
  }
  x--;y++;
 }

 sort(data0.begin(),data0.end(),sort_b);

 for(int x = 0 ; x < n ; x++)
 {
  char s = (x == n-1)? '\n' : ' ';
  cout << data0[x].first << s;
 }

 return 0;
}
