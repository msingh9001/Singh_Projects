# Name: Mandeep Singh
# Date: 01/16/20
# Title: Lab2 - System Calls
# Description: This program creates exactly a process and forks to create a child and we see both get completed
#include <stdio.h>
#include <sys/types.h>  /* pid_t */
#include <unistd.h>     /* fork */
#include <stdlib.h>     /* atoi */
#include <errno.h>      /* errno */

int main(int argc, char *argv[]){
    pid_t pid;
    int i, n = atoi(argv[1]);
    printf("\n Before forking. \n");
    pid = fork();
#If pid is out of bouds, error catcher
    if(pid == -1)
        fprintf(stderr, "cant print, error %d \n", i);
#If the pid is not 0, then it is parent process and we print parent process
    if(pid){
        for(i = 0; i < 100; i++){
            printf("\t \t \t Parent Process %d \n",i);
            usleep(n);
        }
#If the pid is 0, then it is child process and we print child process
    }else{
        for (i = 0; i < 100; i++){
            printf("Child process %d\n",i);
            usleep(n);
        }
    }
    return 0;
}
