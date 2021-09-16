#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;


vector<string> data0;

bool sort_a(string i, string j)
{
 if(i.length() == j.length())
  return i < j;

 else return i.length() < j.length();
}


int main(void)
{
 int m; cin >> m;

 for(int x = 0; x < m ; x++)
 {
  string s1; cin >> s1;
  data0.push_back(s1);
 }

 sort(data0.begin(), data0.end(),sort_a);
 string s2 = data0.front(); cout << s2 << "\n";

 for(auto x = data0.begin()+1 ; x != data0.end() ; x++){
  if(s2 != *x)
   cout << *x << "\n";

  s2 = *x; 
 }

 return 0;
}



