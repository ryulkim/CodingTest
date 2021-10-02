

#include <iostream>
#include <cmath>
#include <vector>
#include <string>
using namespace std;

const string origin = "rwxrwxrwx";

int d_data(string data1)
{
 int answer = 0; int count = 400; int index = 1;
 int answer2 = 0;

 for(int x =  0 ; data1.size() ; x++)
 {
  if(data1[x] == origin[x])
   answer += count;

  count/=2; 
 }

 while(answer)
 {
  answer2 += index * answer%8;
  answer/=8;index*=8;
 }

 return answer2;
}


string e_data(int answer2)
{
 string answer = to_string(answer2);
 int index = 1; int data1 = 0; int count = 400;

 for(int x = answer.length()-1; x >= 0 ; x--)
 {
  data1 += index * (answer[x] - '0');
  index *= 10;
 }

 answer = ""; index = 0;

 while(index < origin.size())
 {
  if(data1 >= count)
  {
   answer.push_back(origin[index]); data1 -= count;
  }

  else answer.push_back('_');

  index++; count /= 2;
 }

 return answer;
}
