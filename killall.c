#include<signal.h>
#include<stdlib.h>
#include<stdio.h>
#include "helper.h"

extern Node * head;
Node * temp;
extern int N;
int killall(char **args)
{ 
 int count=0;
  temp=head;
  
  while(temp)
    {
      if(count)
	kill(temp->pid,15);
      temp=temp -> next;
      count++;
    }
  return 1;  
}
