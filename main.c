#include "helper.h"

Node * head;
Node * end;
int stdin_copy;
int stdout_copy;
int main()
{
head = (Node *)malloc(sizeof(Node));
head -> next = NULL;
end = head;	
stdin_copy = dup(0), stdout_copy = dup(1);
loop();
return 0;

}
