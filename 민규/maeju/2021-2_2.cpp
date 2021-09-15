#include <string>
#include <iostream>
#include <vector>

using namespace std;

char start0 = '(';
char end0 = ')';


bool solution(string s)
{
 int index = 0;

  for(int x = 0; x < s.length() ;x++)
  { 
    if(index == 0 && s[x] == end0)
     return false;

    else if(s[x] == start0)
    index++;

    else index--;
  }
  
  if(index == 0)
   return true; 
 
  return false;
}


