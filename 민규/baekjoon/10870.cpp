#include <iostream>
#include <time.h>
using namespace std;

int a1 = 0;
int a2 = 1;


int solution(int n)
{
 if(n <=0)
  return 0;

 else if(n <= 1)
  return a2; 

 else{
 int a3 = a1 + a2;
 a1 = a2;
 a2 = a3;
 return solution(n-1);
 }
}


int main()
{
 int n;
 //clock_t s1,e1;
 cin >> n;

 //s1 = clock();
 cout << solution(n) << endl;
 //e1 = clock();
 //cout << double(e1-s1) << endl;
 return 0;
}
