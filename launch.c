#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <string.h>
#include <sys/utsname.h>
#include <signal.h>
#include "helper.h"

char Name[100];
extern int BG=1,N;

extern Node head;
pid_t pid, wpid;
int launch(char **args)
{
  	
  int status,bg=0,len=0;
	
  pid = fork();
  
  if (pid == 0) {
    // Child process

	
    while(args[len++]!=NULL);
	
    if (strcmp(args[len-2],"&")==0)
      {	
	bg=1;
	args[len-2]=NULL;
	N++;
		
		
			
      }
    if (execvp(args[0], args) == -1) {
     
      perror("error");
    }
    exit(EXIT_FAILURE);
  } else if (pid < 0) {
    // Error forking
    perror("error");
  } else {
    // Parent process
    while(args[len++]!=NULL);
	
    if (strcmp(args[len-2],"&")==0)
      {	
	bg=1;
			
	printf("%s [%d]\n",args[0],pid);
	args[len-2]=NULL;
	insert(pid,args[0]);
	//setpgid(pid,pid);
    	N++;		
				
			
			
			
		
			
      }
    //printf("%d\n",bg);
    if (!bg)
      {	
	BG=0;
	strcpy(Name,args[0]);
       
	wpid = waitpid(pid, &status, WCONTINUED);
      }
		
		

    

  }
 
  return 1;
}
