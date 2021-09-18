#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;

vector<int> data0;


int gcd(int a, int b)
{
 int r = b;
 while(a%b)
 {
  r = a%b; a = b; b = r;  
 }

 return r;
}

int main(void)
{
 int all_case; cin >> all_case;
 vector<int> data1;

 for(int y = 0 ; y < all_case ; y++){
  int a; cin >> a; data0.push_back(a);
 }
 sort(data0.begin(),data0.end(),greater<int>());

 for(auto x = data0.begin(); x != data0.end(); x++)
  *x -= data0.back();
 
 data0.pop_back();
 while(data0.size() > 1)
 {
  int b = data0.back(); data0.pop_back();
  int a = data0.back(); data0.pop_back();
  data0.push_back(gcd(a,b));
 }

  for(int y = 1 ; y <= sqrt(data0.back()); y++)
  {
   if(data0.back()%y == 0){
    data1.push_back(y);
    if(y != data0.back()/y)
     data1.push_back(data0.back()/y);
   }
  }

  sort(data1.begin(), data1.end());
  for(int z = 1; z < data1.size() ; z++)
   cout << data1[z] << " ";
 
 cout << "\n";
 return 0;
}
