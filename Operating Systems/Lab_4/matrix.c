//Name: Mandeep Singh
//Date: 02/03/20
//Title: Lab 4 - Developing multi-thread applications
//Description: This program uses threads to multiply matrices
#include <stdio.h>
#include <sys/types.h>  /* pid_t */
#include <unistd.h>     /* fork */
#include <stdlib.h>     /* atoi */
#include <errno.h>      /* errno */
#include <pthread.h>    /* pthread_t */
#include <time.h>
#define N 1024
#define M 1024
#define L 1024
//Initialize matrices and multiplication function
void *multiplication(int x);
int temp[N];
int matrixA[N][M];
int matrixB[M][L];
int matrixC[N][L];

void *multiplication(int x){
//Each thread processes a row of the output matrix
    for(int v = 0; v < L; v++){
        int temp = 0;
        for (int b = 0; b < M; b++)
            temp += matrixA[x][b] * matrixB[b][v];
        matrixC[x][v] = temp;
    }
}

int main(int argc, char *argv[]){
    for(int p = 0; p < N; p++)
        temp[p] = p;
//Assigns random values to matrices
    int i, j, k;
    srand(time(NULL));
    for (i = 0; i < N; i++)
        for (j = 0; j < M; j++)
            matrixA[i][j] = rand()%10;
    for (i = 0; i < M; i++)
        for (j = 0; j < L; j++)
            matrixB[i][j] = rand()%10;
//    Creates Processes and assigns them to multiplication function and passes which row they will calculate to function
    pthread_t tid[N];
    
    for (i = 0; i < N; i++)
        pthread_create(&tid[i], NULL, multiplication, (void *)temp[i]);
//  Joins function to main thread
    for (i = 0; i < N; i++) {
        pthread_join(tid[i], NULL);
        printf("Thread %d returned \n", i);
    }
//  Outputs final matrix
    for(i = 0; i < M; i++){
        for(j = 0; j < L; j++)
            printf("%d ", matrixC[i][j]);
        printf("\n");
    }
    
    printf("Main thread done.\n");
    return 0;
}
