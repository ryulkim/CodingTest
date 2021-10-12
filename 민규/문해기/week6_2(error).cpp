#include <iostream>
#include <vector>
#include <cmath>
using namespace std;


int answer = 0;


void print_view(vector<vector<int>>& data0)
{
 for(int x = 1 ; x < data0.size() ; x++)
 {
  for(int y  = 1 ; y < data0.size(); y++)
   cout << data0[x][y] << " ";
  
  cout << "\n";
 }
}

int bfs(vector<vector<int>> &data0, int i, int j, vector<int>& safe1, int count)
{
 int x,y;
 try{
 if(i == safe1.front() && j == safe1.back())
   {answer =  min(answer,count);  answer = (answer == 0)? count : answer; return 0;}

 for(x = i-1 ; x <= i+1; x++)
  for(y = j-1 ; y <= j+1; y++)
  {
   
   if(x < 1 || x >= data0.size() || y < 1 || y >= data0.size() || data0[x][y] > 0)
    continue;

    data0[x][y] = 1;    
    bfs(data0,x,y,safe1,count+1);
    //data0[x][y] = 0;
  }
 }
 catch(exception &e)
 {
  cout << x << " " << y << "\n";
 }
 
 return 0;
}


bool same_line(int x_vector, int y_vector)
{
 if(x_vector == 0 || y_vector == 0 || abs(x_vector) == abs(y_vector))
  return true;
 
 return false;
}

int solution(int n)
{
 
 vector<vector<int>> data0(n+1, vector<int>(n+1,0)); bool check_border = false;
 vector<int> inha1(2,0), safe1(2,0), sword1(2,0), gun1(2,0), not_angle(2,0);
 cin >> inha1.front() >> inha1.back() >> safe1.front() >> safe1.back();
 cin >> sword1.front() >> sword1.back() >> gun1.front() >> gun1.back();
 not_angle.front() = sword1.front() - gun1.front(); not_angle.back() = sword1.back() - gun1.back();
 answer = 0;
 
 for(int x = 1 ; x <= n ; x++)
  for(int y  = 1 ; y <= n; y++)
  {
   int gun_x = x - gun1.front(), gun_y = y - gun1.back();
   int sword_x = x - sword1.front(), sword_y = y - sword1.back();

   if(same_line(sword_x, sword_y) && abs(sword_x) <= 1 && abs(sword_y) <= 1)
    data0[x][y] = 1;  
   
   if(gun_x * not_angle.back() -  gun_y * not_angle.front() == 0  && gun_x * not_angle.front() >=0 && gun_y * not_angle.back() >= 0)
    if(abs(not_angle.front()) <= abs(gun_x) && abs(not_angle.back()) <= abs(gun_y))
    continue;
                   
   if(same_line(gun_x,gun_y))
    data0[x][y] = 1;
  }
 
 data0[sword1.front()][sword1.back()] = 2; data0[gun1.front()][gun1.back()] = 3;
 data0[inha1.front()][inha1.back()] = 4; data0[safe1.front()][safe1.back()] = 5;

 //data0[inha1.front()][inha1.back()] = 1;
 //bfs(data0, inha1.front() , inha1.back(), safe1, 0);
 //data0[inha1.front()][inha1.back()] = 0;

 print_view(data0);
 return answer;
}

int main(void)
{
 ios_base::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);
 int all_case; cin >> all_case;

 for(int x = 0 ; x < all_case ; x++){
  int n; cin >> n;
  cout <<solution(n) << "\n";
 }

 return 0;
}
