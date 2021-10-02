#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

vector<vector<int>> data0;
int m; int answer = 1000000;
vector<int> index01;

int solution()
{
 int answer_a = 0, answer_b = 0;

 for(int x = 0 ; x < m;x++)
 {
  for(int y = x+1; y < m; y++)
  {
   if((index01[x]== 0) && (index01[y] == 0))
    answer_a += data0[x][y];

   else if((index01[x] ==1) && (index01[y] == 1))
    answer_b += data0[x][y];
  }
 }
 
 return abs(answer_a - answer_b);
}


int main(void)
{
 cin >> m;
 data0.assign(m, vector<int>(m,0));

 for(int x = 0; x < m ; x++)
 {
  if(x < m/2)
   index01.push_back(0);

  else index01.push_back(1); 

  for(int y  = 0 ; y <  m ; y++)
  {
   int data1; cin >> data1;data0[min(x,y)][max(x,y)] += data1;
  }
 }
   
 do{

 answer = min(answer, solution());

	}while(next_permutation(index01.begin(),index01.end()));

 cout << answer << "\n";
	return 0;
}
