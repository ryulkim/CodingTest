#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> data0;

int solution(int n,int start, int end)
{
 if(data0[(start + end)/2] == n)
  return 1;

 else if(start >= end)
  return 0; 
  
 else if(data0[(start + end)/2] > n)
  return solution(n,start,((start+end)/2)-1);

 else return solution(n,((start+end)/2)+1,end); 
}


int main(void)
{
 
 ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
 int m,n; cin >> m;

 for(int x = 0 ; x < m ; x++)
 {
  int data1; cin >> data1; data0.push_back(data1);
 }
 sort(data0.begin(),data0.end()); cin >> n;

 for(int x = 0 ; x < n ; x++)
 {
  int data1; cin >> data1; cout << solution(data1,0,m-1) << "\n";
 }

 return 0;
}
