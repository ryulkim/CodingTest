#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n,m; //f,t

vector<string> profe_say;
vector<vector<string>> stu_say;


bool find_stu(string &say0,int index)
{

 for(int x = 0 ; x < n ; x++)
 {
  index = 0;
  for(auto y = stu_say[x].begin(); y != stu_say[x].end(); y++){
 
   if(*y == "")
    index++;

   if(*y == say0 && distance(stu_say[x].begin(),y) == index)
   {
    *y = "";
    return true;
   }
  }
 }
 
 return false;
}

int solution()
{
 for(int x = 0 ; x < m; x++)
 {
   if(!find_stu(profe_say[x],0))
    return 0;
 }

 return 1; 
}

int main(void)
{
 ios_base::sync_with_stdio(false);
 cin.tie(NULL); 
 cout.tie(NULL);
 int t; cin >> t;
 for(int w = 0 ; w < t ; w++)
 {
  profe_say.resize(0); stu_say.resize(0);
  cin >> n >> m;

  for(int x = 0 ; x < m ; x++)
  {
   string say; cin >> say;
   profe_say.push_back(say);
  }

  for(int x = 0 ; x < n ; x++)
  {
   int k; cin >> k; vector<string> say;
   for(int y = 0; y < k ; y++)
   {
    string say0; cin >> say0;
    say.push_back(say0);
   } 
   stu_say.push_back(say);
  }

  cout << solution() << "\n";
 }
 return 0;
}
