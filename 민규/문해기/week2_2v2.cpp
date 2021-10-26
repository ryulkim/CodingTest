#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
using namespace std;

struct cmp{
 bool operator()(pair<int,int> i, pair<int,int> j)
 {
  return i.first - j.second < j.first - i.second;
 }
};

int solution(int n)
{
 int answer = 0;
 priority_queue<pair<int,int>, vector<pair<int,int>>, cmp> data0;
 
 for(int x = 0 ; x < n ; x++)
 {
  int inha,bi; cin >> inha >> bi; int check1 = (inha-bi > 0)? 1:-1;
  data0.push(pair<int,int>(inha, bi));
 }

 bool check = true;

 while(data0.size())
 {
  if(check)
   answer += data0.top().first;

  else{
   answer -=  data0.top().second;
  } 

  check = !check;
  data0.pop();
 }

 return answer; 
}

int main(void)
{
 int all_case; cin >> all_case;

 for(int x = 0 ; x < all_case ; x++)
 {
  int n; cin >> n; cout << solution(n) << "\n";
 }

 return 0;
}





