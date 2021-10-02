#include <iostream>
#include <stdio.h>
#include <fstream>
#include <sys/types.h>
#include <sys/stat.h>
//#include <stat.h>
using namespace std;


int whatable(const char* file_a)
{
 struct stat data; stat(file_a,&data);

 if((data.st_mode & S_IRUSR) != 0)
  perror("OWNER READ");

 if((data.st_mode & S_IWUSR) != 0)
  perror("OWNER WRITE");

 if((data.st_mode & S_IXUSR) != 0)
  perror("OWNER EXECUTE");
 /////////////////////////////////

 if((data.st_mode & S_IRGRP) != 0)
  perror("GROUP READ");

 if((data.st_mode & S_IWGRP) != 0)
  perror("GROUP WRITE");

 if((data.st_mode & S_IXGRP) != 0)
  perror("GROUP EXECUTE"); 

 ///////////////////////////////////

 if((data.st_mode & S_IROTH) != 0)
  perror("OTHER READ");

 if((data.st_mode & S_IWOTH) != 0)
  perror("OTHER WRITE");

 if((data.st_mode & S_IXOTH) != 0)
  perror("OTHER EXECUTE");    

 return 0;
}
