#include  "main_t.h"



void siginal_control(int sig){
  if(sig == SIGINT)
  {
    printf("\n");main();
  }

  else if(sig == SIGQUIT)
  {
   printf("\n");main();
  }
}

void fatal(char *str){
	perror(str);
	exit(1);
}

void new_pwd()
{
 printf("%s\n",getcwd(dir_cur,PATH_MAX));
}

void new_mkdir(char* dir)
{
 int result = mkdir(dir, 0777);
 
 if(result)
  perror(dir);
}

void new_cd(char* dir)
{
 int result = chdir(dir);

 if(result)
  perror(dir);
}

void new_sleep(char* time_a)
{
  sleep(atoi(time_a));
}

void new_pid()
{
  printf("current %d parent %d\n", getpid(), getppid());
}

void read_mode(char* name)
{
 FILE* fp = fopen(name,"r");
   char buf[BUFSIZ] = {'0'};
   int n;
   while(n = fgets(buf,sizeof(buf),fp) > 0)
   {
    for(int x = 0 ; x < BUFSIZ ; x++)
    {
     if(buf[x] != '\n' && buf[x] != '0')
      printf("%c", buf[x]);  
      
     else break; 
    }

    printf("\n");
   }
   
   fclose(fp);
}

void write_mode(char* name)
{
//FILE *fp = fopen(name, "w");
  int fp0 = creat(name,0777);
  FILE* fp = fopen(name,"w");
  char buf[BUFSIZ] = {'0'};
  
  if(fp < 0){return 0;}

  else
  {
   int n; int c;
   
   int x = 0;
   for(x = 0 ; x < BUFSIZ ; x++)
   {
    scanf("%c", &buf[x]);
  
    if(buf[x] == '\0' || buf[x] == '\n')
     break;
   }

   fprintf(fp, buf); 
   fclose(fp);
  }
}

void write_mode2(char* s_name, char* e_name0)
{  
  char* e_name = strtok(e_name0, "|>");
  char alpa = '@';
   
  while(e_name0 != NULL)
  {
   e_name = e_name0;
   if(e_name[0] == 'g')
    alpa = e_name[sizeof(e_name) - 2];

   e_name0 = strtok(NULL, "|> ");
  } 
   
  FILE *fp = fopen(s_name,"r");
  char buf[BUFSIZ] = {'0'};
  
  int fp0 = creat(e_name,0777);
  FILE* fp2 = fopen(e_name,"w");
   while(fgets(buf,sizeof(buf),fp) != NULL)
   {
    if(alpa == '@')
     fprintf(fp2, buf);

    else
    {
     char* g_name = strtok(buf, " ");
     char* g_name0 = g_name;
     
     while(g_name != NULL)
     {
       g_name0 = g_name;
       g_name = strtok(NULL, " ");
     }

     if(g_name0[0] == alpa)
      fprintf(fp2, g_name0);
    }
   }

  fclose(fp);
  fclose(fp2);
}


int new_cat(char* mode, char* name0)
{
 
 char* name = strtok(name0, " >");
 name0 = strtok(NULL," ");
 name0 = strtok(NULL,"\n");

 if(strcmp(mode,"<") == 0)
 {
  if(name0 != NULL)
  {
   write_mode2(name, name0);
  }

  else read_mode(name);
 }

 else if(strcmp(mode,">") == 0)
 {
  write_mode(name);
 }
 
 else
 {
   read_mode(mode);
 }

}

void pipe_control(char* s_name, char* e_name)
{
  char* back_a = strtok(NULL, " ");
  pid_t pid = NULL;

  if(back_a != NULL && strcmp(back_a,"&") == 0)
   pid = fork();

  if(pid == NULL || pid == 0){
   FILE *fp = popen("ls -l","r");
   char buf[BUFSIZ] = {'0'};
   
   int fp0 = creat(e_name,0777);
   FILE* fp2 = fopen(e_name,"w");

   while(fgets(buf,BUFSIZ,fp) != NULL)
    fprintf(fp2, buf);

   pclose(fp);
   fclose(fp2);
  }
}


int list_correction(char *mode)
{
 char* cmdline0 = strtok(cmdline," ");

 if(strcmp(cmdline0,"pwd") == 0){
   new_pwd();  
  }
 
 else if(strcmp(cmdline0,"mkdir") == 0){
   cmdline0 = strtok(NULL," ");
   new_mkdir(cmdline0);
  }
 
 else if(strcmp(cmdline0,"cd") == 0)
 {
  cmdline0 = strtok(NULL," ");
  new_cd(cmdline0);
 }

 else if(strcmp(cmdline0,"exit") == 0)
 {
  return 0;
 }

 else if(strcmp(cmdline0,"sleep") == 0)
 {
  pid_t pid = fork();

  if(mode != '&')
  {
    cmdline0 = strtok(NULL," ");
    new_sleep(cmdline0);
  }

  if(mode == '&')
  {
   if(pid == 0){ 
    cmdline0 = strtok(NULL," ");
    new_sleep(cmdline0);
   }
  }
 }

 else if(strcmp(cmdline0,"pid") == 0)
 {
  new_pid();
 }

 else if(strcmp(cmdline0,"cat") == 0)
 { 
  cmdline0 = strtok(NULL," ");
  char* cmdline1 = strtok(NULL,"\n");
  new_cat(cmdline0, cmdline1);
 }

 else
 {
  char* cmdline1 = strtok(NULL," ");
  
  while(strcmp(cmdline1,">") != 0)
   cmdline1 = strtok(NULL," ");

  char* cmdline2 = strtok(NULL," ");
  pipe_control(cmdline0, cmdline2);
 }

 return 1;
}
