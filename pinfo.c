#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <string.h>
#include <sys/utsname.h>

#define MAX_PATHNAME_LENGTH 200

int pinfo(char ** params, char * basePath)
{
	
    // Create path string: /proc/pid
    char procPath[MAX_PATHNAME_LENGTH];
    strcpy(procPath, "/proc/");
    
    // If pid given, use that, else get info for shell process
    if(params[1]) strcat(procPath, params[1]);
    else strcat(procPath, "self");
    
    // read process id and status
    // Create stat path string
    char statPath[MAX_PATHNAME_LENGTH];
    strcpy(statPath, procPath); strcat(statPath, "/stat");
    
    int errno = 0;
    FILE * stat = fopen(statPath, "r");
    if(errno)
    {
        fprintf(stderr, "Error reading %s: %s\n", statPath, strerror(errno));
        return ;
    }
    int pid; char status; char name[20];
    fscanf(stat, "%d", &pid); fscanf(stat, "%s", name); fscanf(stat, " %c", &status);
    
    fprintf(stdout, "pid: %d\n", pid);
    fprintf(stdout, "Process Status: %c\n", status);
    fclose(stat);

    // read number of virtual memory pages
    errno = 0;
    strcpy(statPath, procPath); strcat(statPath, "/statm");
    FILE * mem = fopen(statPath, "r");
    if(errno)
    {
        fprintf(stderr, "Error reading %s: %s\n", statPath, strerror(errno));
        return ;
    }
    int memSize; fscanf(mem, "%d", &memSize);
    fprintf(stdout, "Memory: %d\n", memSize);
    fclose(mem);

    // get path to executable
    char exePath[MAX_PATHNAME_LENGTH];
    strcpy(statPath, procPath); strcat(statPath, "/exe");
    errno = 0;
    // WARNING: READLINK DOES NOT ADD NULL TERMINATING BYTE
    readlink(statPath, exePath, sizeof(exePath));
    if(errno)
    {
        fprintf(stderr, "Error reading symbolic link %s: %s\n", statPath, strerror(errno));
        return;
    }
    
    // Substtute ~ for homepath
    int sameChars = 0, baseL = strlen(basePath);
    for(sameChars = 0; sameChars < baseL; sameChars++)
        if(basePath[sameChars] != exePath[sameChars]) break;;

    char relPath[MAX_PATHNAME_LENGTH];
    if(sameChars == baseL) // First part of path is common
    {
        relPath[0] = '~'; relPath[1] = '\0';
        strcat(relPath, (const char *)&exePath[baseL]);
    }
    else
    {
        strcpy(relPath, exePath);
        relPath[strlen(exePath)] = '\0';
    }

    // Clear exePath
    int i = 0;
    while(exePath[i]) exePath[i++] = '\0';

    fprintf(stdout, "Executable Path: %s\n", relPath);
    return 1;
}
