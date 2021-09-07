#include <iostream>
#include <map>
#include <vector>
using namespace std;


vector<pair<int,int>> person;

int master_kg;
int master_cm;
int rank = 1;

int soltuion(int kg0, int cm0)
{ 
 int answer = 1;

 for(auto x= person.begin() ; x != person.end() ;x++)
 {
   if(x->first > kg0 && x->second > cm0)
    answer++;
 }
 return answer;
}

int main(void)
{
 int m;
 cin >> m;

 for(int x = 0; x < m ;x++)
 {
   int kg,cm;

   cin >> kg >> cm;
   person.push_back(make_pair(kg,cm));
 }

 for(auto x= person.begin() ; x != person.end() ;x++)
 {
  cout << soltuion(x->first,x->second) << endl;
 }

 return 0;
}
