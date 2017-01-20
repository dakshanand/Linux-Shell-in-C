#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <string.h>
#include <sys/utsname.h>
#include "helper.h"
char home[100];

extern Node head;
Node * lead, * follow;
extern pid_t pid, wpid;
extern char Name[100];
int BG,N=0,status;
void handler(int signum)
{
	pid_t proc_id;
	char ret[100];
	strcpy(ret,"");
	
	(proc_id = waitpid(-1, &status, WNOHANG));
		
	if(proc_id>0&&N)
	  delete(proc_id,1);
	
	
}

//Ctrl-Z
void sigstop(int p){

	if(BG)
	return;
	insert(pid,Name);
	
	N++;
	
        
	//signal(SIGTSTP,&sigstop);
	
	kill (pid,19);
	
	kill (pid,18);

	
   

}

// Ctrl+C
void sigkill(int p){
   return;

 
}

void loop(void)
{

 
  
  char *line, *command,*user,host[100];

  gethostname(host,sizeof(host));
  user=getenv("USER");
  signal(SIGCHLD,&handler);
  signal(SIGTSTP,&sigstop);      //for Ctrl+Z
  signal(SIGINT,&sigkill);       //for Ctrl+C
  

  int status;
	getcwd(home,100);
  do {
    char pwd[100];
	getcwd(pwd,100);
	
		printf("<%s@%s:%s>",user,host,replace_str(pwd,home,"~"));
	
    line = input();
	
  	while (line) 
	{	
	 
    	command = strsep(&line,";");
	
		status=pipes(command);
		//free(command);
		if(!status)
		  return ;
  	}
    
    free(line);
  
  } while (status);
}
