#include <iostream>
#include <vector>
using namespace std;

int n,m;
vector<pair<int,int>> data0; long double data1 = 0;

int main(void)
{
 ios_base::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);
 cin >> n >> m; 
 int value,count,answer = 0;

 for(int x = 0; x < n ;x++)
 {
  cin >> value >> count;

  if(value >= m)
   answer += count;

  else{
   answer += count/(m/value);

   if(count - (count/(m/value) *(m/value)))
    data1 += (long double)(count - (count/(m/value) *(m/value)))/(long double)(m/value);
  } 
 }
 
 cout << answer + (int)data1<< "\n";
 return 0;
}
