#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>

using namespace std;

int main(void)
{
 char* name = "2_5.txt";
 ifstream file_a(name);
 int count = 0; vector<string> data0;

 if(file_a.is_open())
 {
  string s,s1;
  while(getline(file_a,s))
  {
   count++; stringstream ss(s);
   while(getline(ss,s1,' '))
    data0.push_back(s1);
  }

  cout << count << " " <<  data0.size() << "\n";
 }
}
