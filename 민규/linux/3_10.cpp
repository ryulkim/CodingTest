#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <iostream>
using namespace std;

long size_a;
int slowatch(char* file_name)
{
 FILE *f1; f1 = fopen(file_name,"r");
 if(f1== NULL){perror("file is no here");}
 time_t time_a = time(NULL);

 fseek(f1,0,SEEK_END);
 long size_b = ftell(f1);

 if(size_b != size_a)
  cout << time_a << " " << "file is change\n";
 
 return 0;
}
