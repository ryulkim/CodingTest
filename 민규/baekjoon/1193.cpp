#include <iostream>
#include <vector>
#include <cmath>
using namespace std;


int main(void)
{
 int m;cin >> m;
 int bound_index = 1;
 int alpa_index = 1;
 int son = 1, mother = 1;

 for(1; pow(bound_index,2) + bound_index < 2*m ;bound_index++)
  continue;

 alpa_index = bound_index*(bound_index+1)/2 -m;
 
 if(bound_index%2)
 {
  son = 1; mother = bound_index;
   for(int x= 0 ; x < alpa_index ; x++)
   {
    mother--;son++;
   }
 }

 else
 {
   son = bound_index; mother = 1;
   for(int x= 0 ; x < alpa_index ; x++)
   {
    mother++;son--;
   }
 }
 
 cout <<  son << "/" << mother << "\n";
 return 0;
}
