#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <string.h>
#include <sys/utsname.h>
extern int stdin_copy,stdout_copy;

char *input(void)
{
  
  int position = 0;
  char *buffer = malloc(sizeof(char) * 10000);
  int c;
  dup2(stdin_copy, 0);
  dup2(stdout_copy, 1);
  //close(stdin_copy);
  //close(stdout_copy);
 
  while (1) {
    // Read a character
    c = getchar();
    if(c==EOF)

      {	printf("\n");
	exit(0);
      }
    // If we hit EOF, replace it with a null character and return.
    if ( c == '\n') {
      buffer[position] = '\0';
      //printf("%s",buffer);
      return buffer;
    } else {
      buffer[position] = c;
    }
    position++;

    
  }
}
