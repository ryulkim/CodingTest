#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

vector<vector<vector<int>>> board;
vector<char> mark = {'W', 'B'};
vector<int> answer(2,64);
const int size_b = 8;

int solution2(int index,int start , int end,int mode)
{
 int answer0 = 0;
 for(int x = start ; x<= end; x++)
  answer0 += board[mode][index][x];

 answer[mode] = min(answer[mode],answer0);
 return 0;
}

int solution(string& s, int index ,int start , int end, int mode ,int mode0)
{
 int answer = 0;
 for(int x = start ; x <= end; x++)
 {
  if(s[x] != mark[mode])
   answer++;

  mode = !mode;
 }
 
 board[mode0][start].push_back(answer); 
 return 0;
}

int main(void)
{
 ios_base::sync_with_stdio(false); 
 cin.tie(NULL); cout.tie(NULL);
 int m,n;cin >> m >> n;
 board.assign(2, vector<vector<int>>(n-size_b+1,vector<int>(0,0)));
 int mode = 0;

 for(int x = 0 ; x < m ; x++)
 {
  string s; cin >> s;
  for(int y = size_b-1 ; y < n ; y++)
    {solution(s,x,y-7,y,mode,0); solution(s,x,y-7,y,!mode,1);}
  
  mode = !mode;
 }

 for(int x = 0; x < board[0].size();x++)
  for(int y = size_b-1; y < m; y++)
   {solution2(x,y-7,y,0); solution2(x,y-7,y,1);}    
  
  cout << min(answer[0],answer[1])<< "\n";
  return 0;
 }

  
