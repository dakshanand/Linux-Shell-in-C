#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <string.h>
#include <sys/utsname.h>


int pwd(char **args)

{


char pwd[100];
getcwd(pwd,100);
printf("%s\n",pwd);
return 1;
}
