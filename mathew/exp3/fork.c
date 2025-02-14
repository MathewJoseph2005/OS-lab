#include<stdio.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<unistd.h>
#include<stdlib.h>
int main()
{
  pid_t childpid=fork();
if(childpid==-1)
{
printf("Child creation unsuccessfull\n");
}
else if(childpid==0)
{
printf("Child creation is sucessfull\n");
printf("PID");
}
 else
 {
   printf("parent process\n");
   printf("PID %d\n",getpid());
   printf("child PID %d\n",childpid);
   wait(NULL);
   printf("Child finished");
   exit(0);
 }
}
