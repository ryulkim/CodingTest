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
 char* name0 = "2_5.txt";
 char* name = "2_7.txt";
 ofstream file_a(name);
 ifstream file_0(name0);

 istreambuf_iterator<char> begin_source(file_0);
 istreambuf_iterator<char> end_source;
 ostreambuf_iterator<char> begin_dest(file_a); 
 copy(begin_source, end_source, begin_dest);
 
 file_a.close();file_0.close();
 return 0;
}
