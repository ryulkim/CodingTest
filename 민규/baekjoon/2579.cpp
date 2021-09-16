#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int m;
vector<int> data0;

int main(void)
{
 cin >>m; data0.push_back(0);

 for(int x =  0 ; x < m ; x++)
 {
  int y = 0; cin >> y; data0.push_back(y);
 }

  vector<int> data1; data1.push_back(data0.back()); data1.push_back(data0.back());data0.pop_back();
  while(!data0.empty()){
   vector<int> data2;
   int error_checking = data1.front();
   for(int x = 0 ; x < 2 && !data0.empty() ;x++)
   {
     data2.push_back(data0.back()); data0.pop_back();
    
     if(x==0){
      if(data1.size() > 2)
       error_checking  += data2.front();
      
      if(data1.front() > data1[1])
       data2.back() += data1.front();

      else data2.back() += data1[1];
     } 

      else
      {      
       error_checking += data2.back();

       if(data1.back() > data1[1])
        data2.back() += data1.back();

       else data2.back() += data1[1];
      }
   }

   data1 = data2;
   data1.push_back(error_checking); 
 } 

 cout << *max_element(data1.begin(), data1.end()) << "\n";
 return 0;
}
