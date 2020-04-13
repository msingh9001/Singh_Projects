//Name: Mandeep Singh
//Date: 01/27/20
//Title: Lab3 - Pthreads and inter-process Communication – Pipes
//Description: Writes output of ls to downstream end of pipe
/***************************   Lab3 - pipe()**************************/
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>
// main
int main(int argc,char *argv[]){
    int  fds[2];
    char buff[60];
    int count;
    int i;
//    create pipe
    pipe(fds);
    if (fork()==0){
        printf("\nWriter on the upstream end of the pipe -> %d arguments \n",argc);
//        Close read and set the output stream to go to write and execute ls
        close(fds[0]);
        dup2(fds[1], 1);
        execlp("ls", "ls", 0);
        exit(0);
        
    }else if(fork()==0){
        printf("\nReader on the downstream end of the pipe \n");
//        Close write and read input stream and print it
        close(fds[1]);
        while((count=read(fds[0],buff,60))>0){           for(i=0;i<count;i++){
                write(1,buff+i,1);
                write(1," ",1);
            }
            printf("\n");
        }
        exit(0);
    }else{
//        Parent Process closes both read and write and waits for child processes to finish
        close(fds[0]);
        close(fds[1]);
        wait(0);
        wait(0);
    }
    return 0;
}
