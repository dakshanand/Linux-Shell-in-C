#include <sys/wait.h>
#include <unistd.h>
#include <sys/types.h>
#include <pwd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <signal.h>


int execute(char **);
char **split(char *);
int launch(char **);
char *input(void);
void loop(void);


typedef struct node{
  pid_t pid;
  char pname[100];
  struct node *next;
 }Node;


