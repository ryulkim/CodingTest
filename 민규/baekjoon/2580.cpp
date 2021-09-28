#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> data0;
vector<pair<int,int>> blank;
const int size_b = 9;

int solution()
{
 if(blank.size() == 0)
 {
  for(int x = 0 ; x < size_b ; x++){
   for(int y = 0 ; y < size_b ; y++)
    cout << data0[x][y] << " ";
 
   cout << "\n";
  }
  exit(0);
 }

 vector<int> answer(10,1);
 pair<int,int> a = blank.back(); 
 
 for(int x = 0 ; x < size_b; x++)
  answer[data0[a.first][x]]--;
 
 for(int x = 0 ; x < size_b; x++)
   answer[data0[x][a.second]]--;
 
 for(int x = (a.first/3)*3; x <= (a.first/3)*3+2 ;x++)
  for(int y = (a.second/3)*3; y <= (a.second/3)*3+2 ;y++)
   answer[data0[x][y]]--;
  
  for(int x = 1;x <= size_b;x++) 
   if(answer[x] > 0)
    {
      data0[a.first][a.second] = x; blank.pop_back(); 
      solution();
      data0[a.first][a.second] = 0; blank.push_back(a);
    }
  
  return 0;
}

int main(void)
{
 ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
 data0.assign(size_b,vector<int>(size_b,0));
 
 for(int x = 0 ; x < size_b ; x++)
  for(int y = 0 ; y < size_b ; y++)
  {
   int data2; cin >> data2;

   if(data2 == 0)
    blank.push_back(pair<int,int>(x,y));
   
   data0[x][y] = data2;
  }
 
 solution(); return 0;
}
