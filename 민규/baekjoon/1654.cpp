#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n,m;
vector<long long> data0;

int solution(long long start, long long end)
{
 long long data1 = (start + end)/2; long long answer = 0;

 for(int x = 0 ; x < data0.size();x++)
  answer += (data0[x])/data1;

 if(start >= end){
  if(answer < m)
   return data1-1;

  return data1;
 }
 else if(answer < m)
  return solution(start,data1-1);

 else if(answer >= m)
  return solution(data1+1,end);

 return data1; 
}

int main(void)
{
 cin >> n >> m;
 for(int x = 0 ; x< n ; x++)
 {
  long long data1; cin >> data1;
  data0.push_back(data1);
 }
 
 sort(data0.begin(), data0.end());
 cout << solution(1,data0.back()) << "\n";
 return 0;
}
