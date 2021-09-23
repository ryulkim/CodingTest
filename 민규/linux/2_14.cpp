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
 string name,mode; cin >> name >> mode;
 fstream a; name += ".txt";

 if(mode == "r")
  a.open(name,ios::in);

 else if(mode == "w")
  a.open(name,ios::out);
 
 else if(mode == "rw")
  a.open(name,ios_base::in | ios_base::out);
  
 else if(mode == "a")
  a.open(name,ios::out|ios::ate);

 else cout << "error" << "\n";

 a.close();
 return 0;
}
