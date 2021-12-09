#include "main_t.h"

const char* prompt = "mysh> ";
int a_mode = 0;
int first_connect = 1;




int main(){
  int i=0;
  pid_t pid;
 
  if(first_connect){
   chdir(getenv("HOME")); first_connect = 0;
  }

  while (1) {
   
   signal(SIGINT, siginal_control);
   signal(SIGQUIT, siginal_control);  
  	fputs(prompt, stdout);
	  fgets(cmdline, BUFSIZ, stdin);
	  cmdline[strlen(cmdline) -1] = '\0';
   int alpa = list_correction(cmdline[strlen(cmdline) -1]);

   if(alpa == 0)
    exit(0);

   if(alpa == 2)
    printf("\n");  
  
  }
 
  return 0;
}



