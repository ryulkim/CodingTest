#include <iostream>
#include <vector>
using namespace std;
int m,n;

int solution(int n0, int len,string s)
{
 if(len == n){
  cout << s << "\n";
  return 0;
 }
  
 for(int x = n0; x <= m;x++){
  solution(x,len+1, s + to_string(x) + " "); 
 }

 return 0;
}

int main(void)
{
 ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
 cin >> m >> n;
 for(int x = 1; x <= m ;x++){
  solution(x,1,to_string(x) + " ");
 }

 return 0;
}
