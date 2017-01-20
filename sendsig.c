#include<signal.h>
#include<stdlib.h>
#include<stdio.h>
#include "helper.h"

extern Node * head;
Node * temp;
extern int N;
int sendsig(char **args)
{
  int count=0,pno,pid,sig;
  pno=atoi(args[1]);
  sig=atoi(args[2]);
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
  pid=temp->pid;
  kill(pid,sig);
  return 1;
    
  
}
