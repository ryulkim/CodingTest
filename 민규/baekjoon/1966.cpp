#include <iostream>
#include <list>
#include <algorithm>
#include <vector>
using namespace std;

bool sort_a(pair<int,int> i, pair<int,int> j)
{
 return i.first < j.first;
}

int solution(int m,int n)
{
 list<pair<int,int>> data0;
 int answer = 1; int check_data  = 1;

 for(int x = 0 ; x < m ; x++)
 {
  int n0 = 0; if(x == n) n0 = 1;
  int data1; cin >> data1; if(n0 > 0) check_data = data1;
  data0.push_back(pair<int,int>(data1,n0));
 }
  
 while(!data0.empty())
 {
  if(data0.front().first == max_element(data0.begin(), data0.end(),sort_a)->first)
  {
   if(data0.front().second > 0)
    break;

   answer++;data0.pop_front();
  }

  else{
   data0.push_back(data0.front());data0.pop_front();
  } 
 }

 return answer;
}


int main(void)
{
 ios_base::sync_with_stdio(false); 
 cin.tie(NULL); cout.tie(NULL);

 int all_case; cin >> all_case;
 for(int x = 0 ; x < all_case ; x++)
 {
   int m,n; cin >> m >> n; cout << solution(m,n) << "\n";
 }
 return 0;
}
