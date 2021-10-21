#include <iostream>
#include <vector>
using namespace std;


int min_max(vector<int>& data_0)
{
 int last_index = data_0.size()-1;

 for(int x = 1 ; x <= last_index ; x++)
   if(data_0[x])
   {cout << x << " "; break;}

 for(int x = last_index; x > 0; x--)
   if(data_0[x])
    {cout << x << "\n"; break;}
 
 return 0;
}


int solution(int case_1)
{
 vector<int> data_0(1001,0);
 vector<int> list_0(0,0);

 for(int x = 0 ; x < case_1 ; x++)
 {
  int n; cin >> n;
  if(n == 1)
  {
   int data_00; cin >> data_00;
   list_0.push_back(data_00); data_0[data_00]++;
   min_max(data_0);
  }

  else if(list_0.size())
  {
   data_0[list_0.back()]--; list_0.pop_back();
  }
 }
 return 0;
}

int main(void)
{
 ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL); 
 int all_case; cin >> all_case;

 for(int x = 0; x < all_case; x++)
 {
  int case_1; cin >> case_1;
  solution(case_1);
 }

 return 0;
}
