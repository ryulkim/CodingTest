#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <iostream>

using namespace std;

int main(void)
{
 char* name = "2_3.txt";
 int a = creat(name,0666);

 int b = open(name,S_IRUSR|S_IXUSR);
 int c = open(name,S_IRWXU|S_IXUSR);

 if(b < 0) cout << "error in file read\n";
 else{cout << "ok in file read\n";close(b);}

 if(c < 0) cout << "error in file write\n";
 else{cout << "ok in file write\n";close(c);}

 close(a);
 return 0;
}
