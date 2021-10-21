#include <iostream>
#include <vector>
#include <list>
using namespace std;

int solution(int n, int m)
{
 list<string> pro_fe;
 
 for(int x = 0 ; x < m ; x++)
 {
  string s1; cin >> s1; pro_fe.push_back(s1);
 }

 list<list<string>> stu_de;

 for(int x = 0; x < n; x++)
 {
  stu_de.push_back(list<string>());
  int n1; cin >> n1;
  for(int y = 0; y < n1; y++)
  {
   string s1; cin >> s1; stu_de.back().push_back(s1);
  }
 } //input
  
 
 while(pro_fe.size())
 {
  bool check = true; 
  for(auto x = stu_de.begin(); x != stu_de.end(); x++)
  {
   if((*x).size() && pro_fe.front() == x->front())
   {
    check = false; (*x).pop_front();
   }
  }

  pro_fe.pop_front();

  if(check)
   return 0;
 }

 return 1;
}

int main(void)
{
 ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL); 
 int all_case; cin >> all_case;
 
 for(int x = 0 ; x < all_case ; x++)
 {
  int n,m; cin >> n >> m;
  cout << solution(n,m) << "\n";
 }

 return 0;
}


