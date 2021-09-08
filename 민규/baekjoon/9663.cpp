#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
using namespace std;

int n;
int count0 = 0;
vector<vector<int>> data0;

int solution(vector<int> data1)
{
 if(data1.size() == n){
  count0++;
  return 1;
 }

 else
 for(int z = 0 ; z < n ; z++)
  {
   for(int y = 0 ; y < data1.size() ; y++)
    if(abs((int)data1.size() - y) == abs(z-data1[y]) || z == data1[y])
     goto exit; 
    
   data1.push_back(z);
   solution(data1);
   data1.pop_back();
   exit:;
  } 
  
 return 1; 
}


int main(void)
{
 cin >> n;
 
 for(int x = 0 ; x < n ; x++)
 {
  vector<int> data0;
  data0.push_back(x);
  solution(data0);
 }
 cout << count0 << endl;
 return 0;
}

