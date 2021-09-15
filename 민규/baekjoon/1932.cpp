#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> data0;

int main(void)
{
 int m; cin >> m;
 int index_1 ; cin >> index_1;
 data0.push_back(index_1);

 for(int x = 2; x <= m ; x++)
 {
  vector<int> data02;
  for(int y = 0 ; y < x ; y++)
  {
   int y_data0; cin >> y_data0;
   data02.push_back(y_data0);
   
   if(y == 0)
    data02.back() += data0.front();

   else if(y == x-1)
    data02.back() += data0.back();

   else
   {
    if(data0[y-1] > data0[y])
     data02.back() += data0[y-1];

    else data02.back() += data0[y];
   } 

   }
   data0 = data02;
  }

  int value = *max_element(data0.begin(),data0.end());
  cout << value << "\n";
  
 return 0;
}
