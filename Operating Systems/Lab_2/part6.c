# Name: Mandeep Singh
# Date: 01/16/20
# Title: Lab2 - System Calls
# Description: This program creates exactly 2 threads
#include <stdio.h>
#include <sys/types.h>  /* pid_t */
#include <unistd.h>     /* fork */
#include <stdlib.h>     /* atoi */
#include <errno.h>      /* errno */
#include <pthread.h>    /* pthread_t */

void *parentProcess(){
    for(int i = 0; i < 100; i++)
        printf("Parent Process %d \n",i);
}

void *childProcess(){
    for (int i = 0; i < 100; i++)
        printf("Child process %d\n",i);
}
    
int main(int argc, char *argv[]){
    pthread_t tid[2];
#Creating 2 threads each that executes a function
    pthread_create(&tid[0], NULL, parentProcess, (void *)&tid[0]);
    pthread_create(&tid[1], NULL, childProcess, (void *)&tid[1]);
#By using join, we add thread to main process so it completes the thread process before exiting
    pthread_join(tid[0], NULL);
    pthread_join(tid[1], NULL);
    return 0;
}
