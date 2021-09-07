#include <iostream>
#include <cmath>
using namespace std;

int m;

int solution(int data)
{
  for(int x = 2 ; x <= m; x++)
   {
    if(m%x == 0)
    {
     cout << x << endl;
     m /=x;
     return 1;
    }
   }
   return 0; 
}

int main(void)
{ 
 cin>> m;

  while(solution(m)){
   }

 return 0;
}
