//
//  pqueue.c
//
//  Created by Mandeep Singh on 02/28/19.
//  Copyright © 2019 Mandeep Singh. All rights  .
//
//Priority queue by utilizing binary heap implemented through an array
#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h> //Import libraries for usage
#include "pqueue.h"
#define LEFT ((2 * i) + 1)
#define RIGHT ((2 * i) + 2)

typedef struct pqueue {
    int length;
    int count;
    void **data;
    int (*compare)();
} PQ;

//O(1)
PQ *createQueue(int (*compare)()){
    PQ *queue;
    queue = malloc(sizeof(PQ));
    assert(queue != NULL);
    queue -> count = 0;
    queue -> length = 10;
    queue -> data = malloc(sizeof(void*) * queue -> length);
    assert(queue -> data != NULL);
    queue -> compare = compare;
    return queue;
}

//O(1)
void destroyQueue(PQ *pq){ //Destroy entire queue
    free(pq -> data);
    free(pq);
}

//O(1)
int numEntries(PQ *pq){
    return pq -> count; //Return number of elts in queue
}

//O(logn)
void addEntry(PQ *pq, void *entry) {
    if(pq -> count >= pq -> length){
        pq -> length *= 2;
        pq -> data = realloc(pq -> data, sizeof(void*) * pq -> length); //Reallocate memory
    }

    int i1 = pq -> count;//Set i1 to index value of soon-to-be newly inserted data
    int i2 = (i1 - 1) / 2;
    pq -> data[pq -> count] = entry; //Insert new data at count and then increment count
    
    while(1){
        if((*pq -> compare)(entry, pq -> data[i2]) < 0){ //If data at entry is less than data parent
\
            void* temp = pq -> data[i2]; //swap entry & pq -> data[i2]
            pq -> data[i2] = entry;
            pq -> data[i1] = temp;
            i1 = i2; //update i1
            i2 = (i1 - 1) / 2; //update i2
        }else
            break; //Break to end while loop once reheaping is done
    }
    pq -> count++; //Increment to account for new elt
}

// O(logn)
void *removeEntry(PQ *pq){
    if(pq -> count <= 0)
        return NULL;
    else if(pq -> count == 1){
        void* x = pq -> data[0];
        pq -> data[0] = NULL;
        pq -> count--; //Decrement to account for deleted elt
        return x;
    }
    
    void *x = pq -> data[0];
    pq -> data[0] = pq -> data[pq -> count - 1];
    pq -> data[pq -> count - 1] = NULL;
    int i = pq -> count - 2;
    
    while(1){
        if(i <= 0)
            break;
        if((*pq -> compare)(pq -> data[i], pq -> data[(i-1)/2]) < 0){
            void *temp = pq->data[i]; //swap pq -> data[i] & pq -> data[(i-1)/2]
            pq -> data[i] = pq -> data[(i-1)/2];
            pq -> data[(i-1)/2] = temp;
        }
        i--; //Decrement i
    }
    pq -> count--; //Decrement count
    return x;
}

