#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;


vector<int> blackjack;
int answer = 0;
int m;

int solution(int n,int count, int value)
{
 if(count >= 3){
  if(value > answer && value <= m)
   answer = value;
 }

 else
  for(int x = n+1; x < blackjack.size() ; x++)
   solution(x,count+1,value + blackjack[x]);
  
  return 1;
}


int main(void)
{
 int n;

 cin >> n >> m;

 for(int x =  0 ; x < n ; x++)
 {
  int n_data;
  cin >> n_data;
  blackjack.push_back(n_data);
 }
 sort(blackjack.begin(), blackjack.end());
 solution(-1,0,0);
 cout << answer << endl;
 return 0;
}
