#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int m;
vector<int> color;
vector<vector<int>> index0 = {{1,2} , {0,2} , {0,1}};

int  main(void)
{
 cin >> m;
 int r,g,b; cin >> r >> g >> b;
 color.push_back(r); color.push_back(g); color.push_back(b);

 for(int x = 1 ;x < m ; x++)
 {
  cin >> r >> g >> b;
  r += color[index0[0][0]] < color[index0[0][1]]? color[index0[0][0]] : color[index0[0][1]];
  g += color[index0[1][0]] < color[index0[1][1]]? color[index0[1][0]] : color[index0[1][1]];
  b += color[index0[2][0]] < color[index0[2][1]]? color[index0[2][0]] : color[index0[2][1]];
  color[0] = r; color[1] = g; color[2] = b;
 }
 
 cout << *min_element(color.begin(), color.end()) << "\n";
 return 0;
}
