#include<signal.h>
#include<stdlib.h>
#include<stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include "helper.h"

extern Node * head;
Node * temp;
extern int N,BG;
extern char Name[100];
int fg(char **args)
{
  int count=0,pno,pid,status;
  pno=atoi(args[1]);
  temp=head;
  if(pno>N)
    {
      printf("Less Processes\n");
      return 1;
    }
  while(count<pno)
    {
      count++;
      temp=temp->next;
    }
  strcpy(Name,temp->pname);
  delete(temp->pid,0);
  BG=0;
  waitpid(temp->pid,&status,WCONTINUED);

  
 
  return 1;
    
  
}
