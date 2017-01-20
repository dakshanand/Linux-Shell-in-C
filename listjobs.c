#include "helper.h"

extern Node * head;
Node * temp;
int listjobs(char **args)
{
  int count=0;
  temp=head;
  
  while(temp)
    {
      if(count)
      printf("[%d] %s [%d]\n",count,temp->pname,temp->pid);
      temp=temp -> next;
      count++;
    }
  return 1;
}
