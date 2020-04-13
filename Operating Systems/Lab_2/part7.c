# Name: Mandeep Singh
# Date: 01/16/20
# Title: Lab2 - System Calls
# Description: This program creates a child process that runs the ls linux command instead of making a duplicate
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <errno.h>
int main(int argc, char *argv[]) {
    pid_t  pid;
    int i, n = atoi(argv[1]);
    printf("\nBefore forking.\n");
#Call fork
    pid = fork();
#Error catcher
    if (pid == -1)
        fprintf(stderr, "can't fork, error %d\n", errno);
#If child pid, then run ls linux command
    else if(pid == 0)
        execlp("/bin/ls", "ls", NULL);
#If parent pid, wait for child to finish and then print child process complete
    else{
        wait(NULL);
        printf("Child Process Complete\n");
        exit(0);
    }
    return 0;
}
