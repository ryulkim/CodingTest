#include <iostream>
#include <stdio.h>
#include <fstream>
#include <sys/types.h>
#include <sys/stat.h>
#include <vector>
#include <fcntl.h>


int setperm(char* file_name, mode_t data0)
{
 struct stat data1; stat(file_name,&data1);
 FILE *f1; f1 = fopen(file_name,"r");
 if(f1== NULL)
 {
  creat(file_name,data0);
 }

 else
  chmod(file_name,data0);


 fclose(f1);
 return 0;
}
