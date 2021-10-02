#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

const int mode_size = 4;
vector<int> data0;
vector<int> mode0(mode_size,0);
int m, max0 = -1000000000 ,min0 = 1000000000;

int solution(int len, int value)
{
 if(len == m)
 {
  max0 = max(max0, value); min0 = min(min0, value);
  return 0;
 }

 if(mode0[0] > 0)
 {
  mode0[0]--;solution(len+1,value + data0[len]);mode0[0]++;
 }

 if(mode0[1] > 0)
 {
  mode0[1]--;solution(len+1,value - data0[len]);mode0[1]++;
 }

 if(mode0[2] > 0)
 {
  mode0[2]--;solution(len+1,value * data0[len]);mode0[2]++;
 }

 if(mode0[3] > 0)
 {
  mode0[3]--;solution(len+1,value / data0[len]);mode0[3]++;
 }

 return 0;
}


int main(void)
{
 cin >> m;
 for(int x  = 0 ; x < m ;x++)
 {
  int data1; cin >> data1;
  data0.push_back(data1);
 }

 for(int x  = 0 ; x < mode_size;x++)
 {
  int data1; cin >> data1;
  mode0[x] = data1;
 }
 
 solution(1,data0[0]);
 cout << max0 << "\n" << min0 << "\n";
 return 0;
}
