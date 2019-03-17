//
//  table.c
//
//  Created by Mandeep Singh on 03/14/19.
//  Copyright © 2019 Mandeep Singh. All rights  .
//
//Implementing quicksort algorithm for use in array
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <assert.h>
# include <stdbool.h>
# include "set.h"
# define EMPTY   0
# define FILLED  1
# define DELETED 2

void swap(void *first, void *second);
void quicksort(SET *sp, void** ret[], int first, int last);
int partition(SET *sp, void** ret[], int first, int last);

struct set {
    int count;                  // number of elements in array
    int length;                 // length of allocated array
    void **data;                // array of allocated elements
    char *flags;                // state of each slot in array
    int (*compare)();		// comparison function
    unsigned (*hash)();		// hash function
};


static int search(SET *sp, void *elt, bool *found)
{
    int available, i, locn, start;


    available = -1;
    start = (*sp->hash)(elt) % sp->length;

    for (i = 0; i < sp->length; i ++) {
        locn = (start + i) % sp->length;

        if (sp->flags[locn] == EMPTY) {
            *found = false;
            return available != -1 ? available : locn;

        } else if (sp->flags[locn] == DELETED) {
            if (available == -1)
		available = locn;

        } else if ((*sp->compare)(sp->data[locn], elt) == 0) {
            *found = true;
            return locn;
        }
    }

    *found = false;
    return available;
}

//O(n)
SET *createSet(int maxElts, int (*compare)(), unsigned (*hash)())
{
    int i;
    SET *sp;


    assert(compare != NULL && hash != NULL);

    sp = malloc(sizeof(SET));
    assert(sp != NULL);

    sp->data = malloc(sizeof(char *) * maxElts);
    assert(sp->data != NULL);

    sp->flags = malloc(sizeof(char) * maxElts);
    assert(sp->flags != NULL);

    sp->compare = compare;
    sp->hash = hash;
    sp->length = maxElts;
    sp->count = 0;

    for (i = 0; i < maxElts; i ++)
        sp->flags[i] = EMPTY;

    return sp;
}

//O(1)
void destroySet(SET *sp)
{
    assert(sp != NULL);

    free(sp->flags);
    free(sp->data);
    free(sp);
}

//O(1)
int numElements(SET *sp)
{
    assert(sp != NULL);
    return sp->count;
}

//O(n)
void addElement(SET *sp, void *elt)
{
    int locn;
    bool found;


    assert(sp != NULL && elt != NULL);
    locn = search(sp, elt, &found);

    if (!found) {
	assert(sp->count < sp->length);

	sp->data[locn] = elt;
	sp->flags[locn] = FILLED;
	sp->count ++;
    }
}

//O(n)
void removeElement(SET *sp, void *elt)
{
    int locn;
    bool found;


    assert(sp != NULL && elt != NULL);
    locn = search(sp, elt, &found);

    if (found) {
	sp->flags[locn] = DELETED;
	sp->count --;
    }
}

//O(n)
void *findElement(SET *sp, void *elt)
{
    int locn;
    bool found;
    assert(sp != NULL && elt != NULL);
    locn = search(sp, elt, &found);
    return found ? sp->data[locn] : NULL;
}

//O(nlogn)
void quicksort(SET *sp, void** ret[], int first, int last){
    int pivot = partition(sp, ret, first, last); //Set pivot
    if(first < last){
        pivot = partition(sp, ret, first, last); //Set new pivot
        quicksort(sp, ret, first, pivot - 1); //quicksort for subarray
        quicksort(sp, ret, pivot + 1, last); //quicksort for subarray
    }
}

//O(logn)
int partition(SET *sp, void** ret[], int first, int last){
    void* pivot = ret[last]; //Set pivot
    int low = first; //Set pointer to next lowest elt
    for(int i = first; i < last; i++){
        if((*sp->compare)(ret[i], pivot) < 0){ //If pivot is > ret[i]
            swap(&ret[i], &ret[low]); //Then swap
            low++; //Increment low
        }
    }
    swap(&ret[last], &ret[low]); //Swap last and low
    return low;
}

//O(1)
void swap(void *first, void *second){
    void* temp = second; //Swap first and second
    second = first;
    first = temp;
}

//O(n)
void *getElements(SET *sp){
    void*** ret = malloc(sizeof(void*)* sp -> count);//Allocate memory the size of count for array ret
    assert(ret != NULL);
    int i = 0, j = 0;
    for(i = 0; i < sp -> length; i++){
        if(sp -> flags[i] == FILLED){
            ret[j] = sp -> data[i];//If the flag[i] is FILLED, go to data[i] and copy to ret[j]
            j++;//This way every index of ret is only the FILLED data vals and no empty slots
        }
    }
    quicksort(sp, ret, 0, sp -> count - 1); //Call quicksort
    return ret; //Return ordered array
}
