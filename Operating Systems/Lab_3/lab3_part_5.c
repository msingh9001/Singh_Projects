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
    int n;
    printf("\n1.Producer\n2.Exit");
    while(1){
        int rNum = rand() / RAND_DIVISOR;

//        Generate a random number
        item = rand();
        printf("\nEnter your choice:");
        scanf("%d", &n);
//        Different options: Have producer put something in buffer or exit
        switch(n){
            case 1:
//                Mutex should be 1 and should not be full
                if((mutex == 1) && (empty != 0))
                    producer2();
                else
                    printf("Buffer is full");
                break;
            case 2:
                exit(0);
                break;
        }
//        Consumer will automatically take what is in buffer
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
