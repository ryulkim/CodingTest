#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> work1 = {2,1};
vector<int> data2;

int calcul(int value, int having){
 int answer = 0;
 for(auto x = data2.begin(); x != data2.end() ; x++)
 {
  if(*x < value){
   if(having < value - *x)
    return -1;
    
   answer += work1[1] * (value - *x); having -= value - *x;
  } 
 
  else
  {
   answer += work1[0] * (*x - value); having += *x - value;
  }
 }
 
 return answer;
}

int main(void)
{
int m,n,having0;
cin >> m >> n >> having0;

for(int x =  0 ; x < m ; x++)
 for(int y  = 0 ; y < n ; y++)
 {
  int data00; cin >> data00;
  data2.push_back(data00);
 }

sort(data2.begin(),data2.end(),greater<int>());
int start = 0, end = data2[0];
int answer = 256 * m * n, value_answer = 256;

int k = end;
while(start <= end){
 int value = (int)((start + end)/2);
 int multi = calcul(value,having0);

 if(multi >= 0){
  if(answer > multi or (answer == multi and value_answer < value)){
   answer = multi;
   value_answer = value;
  }

  start = value + 1;
 }

 else {k = min(k, value); end = value - 1;}  
}

for(int value = 0 ; value < k ; value++){
 int multi = calcul(value,having0);

 if(multi >= 0)
  if(answer > multi or (answer == multi and value_answer < value)){
   answer = multi;
   value_answer = value;
  }
}

 cout << answer <<  " "  << value_answer;
 return 0;
}
