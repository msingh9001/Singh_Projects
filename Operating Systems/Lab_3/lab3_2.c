//Name: Mandeep Singh
//Date: 01/27/20
//Title: Lab3 - Pthreads and inter-process Communication – Pipes
//Description: Writes the name of the executable to downstream of pipe
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
    pipe(fds);
    if (fork()==0){
//        Close Read end and write name of executable
        printf("\nWriter on the upstream end of the pipe -> %d arguments \n",argc);
        close(fds[0]);
        for(i=0;i<argc;i++){           write(fds[1],argv[i],strlen(argv[i]));       }       exit(0);
        
    }else if(fork()==0){
//        Close write end and read in stream
        printf("\nReader on the downstream end of the pipe \n");
        close(fds[1]);
        while((count=read(fds[0],buff,60))>0){           for(i=0;i<count;i++){
                write(1,buff+i,1);
                write(1," ",1);
            }
            printf("\n");
            
        }       exit(0);
    }else{
//        Parent process closes both read and write and waits for child to execute
        close(fds[0]);
        close(fds[1]);
        wait(0);
        wait(0);
    }
    return 0;
}
