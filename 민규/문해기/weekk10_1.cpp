#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <list>
using namespace std;

vector<int> reversed_room;
int end_point;
int answer;
#define max_size_0 10000
#define max_size_1 4
vector<int> index_room(max_size_0,0);

int loutine(list<int>& data_0,int time_a)
{
 int len_0 = data_0.size(); list<int> data_02;
 
 for(int x = 0; x < len_0 ; x++)
 {
  int data_01 = data_0.front(); data_0.pop_front();
    
  if(data_01 == end_point) 
   {answer = min(answer, time_a); return time_a;}

  if(data_01 + 1 < max_size_0 && index_room[data_01 + 1] < 1)
   {data_02.push_back(data_01 + 1); index_room[data_01 + 1] = 1;}

  if(data_01 - 1 >= 0 && index_room[data_01 - 1] < 1)
   {data_02.push_back(data_01 - 1); index_room[data_01 - 1] = 1;}

  if(index_room[reversed_room[data_01]] < 1)
   {data_02.push_back(reversed_room[data_01]);
   index_room[reversed_room[data_01]] = 1;}
 }

 return loutine(data_02,time_a + 1);
}


int solution(int n)
{
 int start_point; cin >> start_point >> end_point; answer = abs(end_point - start_point); 
 index_room.assign(max_size_0,0); list<int> data0(1,start_point);
 index_room[start_point] = 1; loutine(data0,0);

 return answer;
}


int main(void)
{
 ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL); 

 int len_check = 10; string line_check = "000";
 for(int x = 0 ; x < max_size_0 ; x++)
 {
  if(x >= len_check)
  {
   len_check *= 10; line_check.pop_back();
  }

  string data0 = to_string(x); int data0_length = data0.length()-1;
  reverse(data0.begin(), data0.end());
  string data1 = data0 + line_check;
 
  int reversed_alli = stoi(data1);
  reversed_room.push_back(reversed_alli);
 } //check

 int all_case; cin >> all_case;
 
 for(int x =  0 ; x < all_case ; x++)
 {
  cout << solution(all_case) << "\n";
 }
 
 return 0;
}
