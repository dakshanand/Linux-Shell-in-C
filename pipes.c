#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <string.h>
#include <sys/utsname.h>
#include "builtin.h"




int pipes (char *buffer)
{
  int i;
  pid_t pid;
  int in, fd [2],n=-1;

  /* The first process should get its input from the original file descriptor 0.  */
  in = 0;
  char *temp = NULL, *pipeCommands[1000], **args;
  int newPipe[2], oldPipe[2], pipesCount;
   

  do 
    {
      temp = strsep(&buffer, "|");

      if(temp != NULL) 
	{
	  if(strlen(temp) > 0) 
	    {
	      pipeCommands[++n] = temp;
	    }
	}
    } while(temp);
  n++;

  for (i = 0; i < n - 1; ++i)
    {
      pipe (fd);

      args=split(pipeCommands[i]);
      args=redirect(args);
      spawn_proc (in, fd [1], args);
      free(args);
     
      close (fd [1]);

      
      in = fd [0];
    }
 
  if (in != 0)
    dup2 (in, 0);
 
  args=split(pipeCommands[n-1]);
  args=redirect(args);
  
  
  int x=execute(args);
  free (args);
  return x;
}
extern char *built_str[];
extern int(*built_f[]) (char**);
int spawn_proc (int in, int out, char **args)
{
  pid_t pid;
  int i;


 
  if ((pid = fork ()) == 0)
    {

      if (in != 0)
        {
          dup2 (in, 0);
          close (in);
        }

      if (out != 1)
        {
          dup2 (out, 1);
          close (out);
        }
      //execlp("cd","cd",NULL);
      
      for (i = 0; i < 8; i++) {
	if (strcmp(args[0], built_str[i]) == 0) {
	  int len=0;
       
      
     
	  while(args[len++]!=NULL);
	  if (strcmp(args[len-2],"&")==0)
	    {
			
	      args[len-2]=NULL;
			
	    }
	  int x=(*built_f[i])(args);
	  execlp("sleep","sleep","0",NULL);
	  return x;
	 
	}
      }

      execvp(args[0],args);
     
    }

  return pid;
}
