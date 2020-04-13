# Name: Mandeep Singh
# Date: 01/16/20
# Title: Lab2 - System Calls
# Description: This program creates exactly 7 processes
#include <stdio.h>
#include <sys/types.h>  /* pid_t */
#include <unistd.h>     /* fork */
#include <stdlib.h>     /* atoi */
#include <errno.h>      /* errno */

int main(int argc, char *argv[]){
    pid_t pid;
    int i, n = atoi(argv[1]);
    printf("Before forking. \n");
#Loops three times and creates a process which then forks to create child processes
    for(i = 0; i < 3; i++){
        if(fork() == 0){
            printf("Child ID: %d \tParent ID: %d\n", getpid(), getppid());
            exit(0);
#We want one child to have no further children
        }if(fork() == 0){
            printf("Child ID: %d \tParent ID: %d\n", getpid(), getppid());
#We want this child to have further children
        }else{
#We need to exit once loop finishes
            int status;
            waitpid(-1, &status, 0);
            break;
            
        }
    }
    return 0;
}
