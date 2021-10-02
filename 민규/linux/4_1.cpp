#include <stdio.h>
#include <sys/types.h>
#include <dirent.h>

int my_double_ls(char* dir_name)
{
  DIR *dir1;
  struct dirent *lane;     
  dir1 = opendir (dir_name);

  if (dir1 != NULL)
  {
    while (lane = readdir (dir1))
      puts (lane->d_name);

    (void) closedir (dir1);
  }
  else
    perror ("Couldn't open the directory");

  return 0;
}
