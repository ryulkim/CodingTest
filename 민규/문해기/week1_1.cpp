#include <iostream>
#include <cmath>
using namespace std;

int solution()
{
 string s;int n; cin >> s; cin >> n;
 
 for(int pos = 0; pos < n; pos++)
 {
  int pos_x = pos; int pos_x2 = n*2 - pos-1; bool check = true;

  while(pos_x < s.length())
  {
   cout << s[pos_x];
   pos_x += n*2; 
   
   if(pos_x2 < s.length())
    cout << s[pos_x2];

   else break;
   pos_x2 += n*2; 
  }
 }
 
 cout << "\n";
 return 0;
}

int main(void)
{
 ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
 int all_case = 0; cin >> all_case;

 for(int x = 0 ; x < all_case ; x++)
  solution();

 return 0;
} 









