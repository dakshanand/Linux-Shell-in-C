#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/types.h>



char **redirect(char **args)
{
  int len=0,in,out;
  while(args[len]!=NULL)
    {
    
      
      if(strcmp(args[len],">")==0)
	{
	 
	  args[len++]=NULL;
	  out = open(args[len],O_WRONLY|O_TRUNC |O_CREAT,0777);
	  dup2(out,STDOUT_FILENO);
	  close(out);
	  args[len++]=NULL;
	  
	  }

      else if(strcmp(args[len],">>")==0)
	{
	 
	  args[len++]=NULL;
	  out = open(args[len],O_APPEND |O_RDWR| O_CREAT,0777);
	  dup2(out,STDOUT_FILENO);
	  close(out);
	  args[len++]=NULL;
	  
	  }
	
      else if(strcmp(args[len],"<")==0)
	{
	 
	  args[len++]=NULL;
	  in = open(args[len],O_RDONLY);
	  dup2(in,STDIN_FILENO);
	  close(in);
	 
	  args[len++]=NULL;
	  
	  }

      
     
	else len++;
      
     

 
      }
 
  return args;
}
