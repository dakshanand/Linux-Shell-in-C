#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <string.h>
#include <sys/utsname.h>

extern char home[100];

int cd(char **args)
{
  	if (!args[1])
		 chdir(home);

	
    else if (chdir(args[1]) != 0) {
      fprintf(stderr, "Invalid Directory\n");
    }
  
  return 1;
}

