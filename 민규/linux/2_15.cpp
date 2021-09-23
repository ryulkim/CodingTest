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
#include <string>
#include <iostream>
using namespace std;

int main(void)
{
 string name; cin >> name;
 fstream a,b; name += ".txt";  string s="";

 a.open(name,ios::out|ios::ate|ios::in);
 if(a.is_open())
 {
   while(getline(a,s))
    cout << s << "\n";
 }

 else
 {
  a.close(); a.open(name,ios::out|ios::ate);
  cin >> s; a << s;
 }

 a.close();
 return 0;
}
