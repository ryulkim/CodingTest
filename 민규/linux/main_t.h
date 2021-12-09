#include <string.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <linux/limits.h>
#include <dirent.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <time.h>
#include <unistd.h>
#include <signal.h>
#include <fcntl.h>

#define MAX_CMD_ARG 10
#define BUFSIZ 256
void fatal(char *str);
char* cmdvector[MAX_CMD_ARG];
char  cmdline[BUFSIZ];
char dir_cur[PATH_MAX];

int list_correction(char* mode);
void new_pwd();
void new_mkdir(char* dir);
void new_cd(char* dir);
void new_sleep(char* time_a);
void new_pid();
int new_cat(char*, char*);
void siginal_control(int sig);
void pipe_control(char*, char*);
void read_mode(char *);
void write_mode(char *);
void write_mode2(char *, char *);

int main();

