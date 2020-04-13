//Name: Mandeep Singh
//Date: 01/27/20
//Title: Lab3 - Pthreads and inter-process Communication – Pipes
//Description: Pipes grep root to cat /etc/passwd
#include <stdio.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

int main(int argc,char *argv[]){
    int fds[2];
//    Create pipe
    pipe(fds);
    if (fork() == 0) {
//      Close read and set output stream to go to write and run grep root
        dup2(fds[0], 0);
        close(fds[1]);
        execlp("grep", "grep", "root", 0);
    }
    else if(fork() == 0){
//      Close write and read input stream and run cat /etc/passwd
        dup2(fds[1], 1);
        close(fds[0]);
        execlp("cat", "cat", "/etc/passwd", 0);
        
    }else{
//        Parent Process closes both read and write and waits for child processes to finish
        close(fds[0]);
        close(fds[1]);
        wait(0);
        wait(0);
    }
    return 0;
}
