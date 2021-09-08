#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

int m;
int Max = 250000;
vector<int> deci;

int solution_1(int m)
{
 for(int x=2 ; x <= sqrt(m) ; x++)
 {
  if(m%x == 0)
   return 0;
 }

 return 1;
}

int solution(int m)
{
 int s_index= deci.size(), e_index= 0;

 for(int x = 0; x < deci.size(); x++)
 {
  if(deci[x] > 2*m)
   break;

  if(deci[x] >= m+1 && s_index == deci.size())
   s_index = x;

  if(deci[x] <= 2*m)
   e_index = x; 
 }

 if(e_index - s_index + 1 > 0)
  return e_index - s_index + 1;

 else return 0; 
}

int main(void)
{
 for(int x = 1 ; x < Max ;x++)
 {
  if(solution_1(x))
   deci.push_back(x);
 }

 do{
 cin >> m;
 if(m==0)
  return 0;

 cout << solution(m) << "\n";
 }while(m > 0);

 return 1;
}
