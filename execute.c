#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <string.h>
#include <sys/utsname.h>
#include "builtin.h"

char *built_str[] = {
  "cd",
  "quit",
  "killallbg",
  "pwd",
  "listjobs",
  "sendsig",
  "fg", 
  "pinfo",
};


int (*built_f[]) (char **) = {
  &cd,
  &Exit,
  &killall,
  &pwd,
  &listjobs,
  &sendsig,
  &fg,
  &pinfo,

};

int execute(char **args)
{
  int i;

  if (args[0] == NULL) {
    // An empty command was entered.
    return 1;
  }

  for (i = 0; i < 8; i++) {
    if (strcmp(args[0], built_str[i]) == 0) {
		int len =0;
		while(args[len++]!=NULL);
		if (strcmp(args[len-2],"&")==0)
		{
			
			args[len-2]=NULL;
			
		}
      return (*built_f[i])(args);
    }
  }

  return launch(args);
}

