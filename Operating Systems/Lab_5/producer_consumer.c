//Name: Mandeep Singh
//Date: 01/27/20
//Title: Lab3 - Pthreads and inter-process Communication – Pipes
//Description: Producer and Consumer problem using a single buffer for two processes

#include <stdio.h>
#include <stdlib.h>
#define RAND_DIVISOR 100000000

int mutex = 1, full = 0, empty = 3, x = 0, item;
void producer2();
void consumer2();
int wait2(int);
int signal2();

int main(){
    printf("\n1.Producer\n2.Exit");
    while(1){
        int rNum = rand() / RAND_DIVISOR;

//        Generate a random number
        item = rand();
//        Produces the item
        if((mutex == 1) && (empty != 0))
            producer2();
        else
            printf("Buffer is full");
//        Consumes the item
        if((mutex == 1) && (full != 0))
            consumer2();
        else
            printf("The buffer is empty");
    }
    return 0;
}

int wait2(int s){
    return(--s);
}

int signal2(int s){
    return(++s);
}
//Producer waits for signal and if buffer is not full produces item
void producer2(){
    mutex=wait2(mutex);
    full=signal2(full);
    empty=wait2(empty);
    x++;
    printf("\nProducer produces the item %d",item);
    mutex=signal2(mutex);
}

//Consumer waits for signal and if buffer is not empty comsumes item
void consumer2(){
    mutex = wait2(mutex);
    full=wait2(full);
    empty=signal2(empty);
    printf("\nConsumer consumes item %d",item);
    x--;
    mutex=signal2(mutex);
}
