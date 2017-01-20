#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <string.h>
#include <sys/utsname.h>


char **split(char *line)
{
  
  char **args = malloc(100 * sizeof(char*));
  char *arg;
  int position=0;
  // printf("%s",line);
  args[0]=NULL;
  arg = strtok(line," \'\"\t\r\n\a");
  while (arg != NULL) {
    args[position] = arg;
    position++;


    arg = strtok(NULL," \'\"\t\r\n\a");
  }
  args[position] = NULL;
 
  return args;
}

