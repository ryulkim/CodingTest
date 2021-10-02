#include <iostream>
#include <vector>
using namespace std;

vector<int> data0;
vector<int> hanoi(21,0);

int solution(int n,int start, int end)
{
 if(n < 1) return 0;
 int index0 = (end ==3)? (start == 1)? 2 : 1 : (end == 2)? (start == 1)? 3 : 1 : (start == 2)? 3 : 2;   
 
 solution(n-1,start,index0);
 cout << start << " " << end << "\n";
 solution(n-1,index0,end);
 return 0;
}

int main(void)
{
 hanoi[0] = 1; hanoi[1] = 1;

 for(int x = 2; x < 21 ;x++)
  hanoi[x] = hanoi[x-1]*2 + 1;
 
 int m; cin >> m; cout << hanoi[m] << "\n";
 solution(m,1,3);
 return 0;
}
