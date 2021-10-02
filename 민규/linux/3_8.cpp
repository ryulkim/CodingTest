#include <iostream>
#include <stdio.h>
#include <fstream>
#include <sys/types.h>
#include <sys/stat.h>
#include <vector>
#include <fcntl.h>
#include <unistd.h>
using namespace std;


int remove(char* file_name)
{
 int mode_a = W_OK;

  if(access(file_name,mode_a) == 0)
  {
   cout << "check one more time\n";
   char data1; cin >> data1;
  }
  
  remove(file_name);
  return 0;
}
