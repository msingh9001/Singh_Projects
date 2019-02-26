//
//  set.c
//
//  Created by Mandeep Singh on 02/21/19.
//  Copyright © 2019 Mandeep Singh. All rights  .
//
#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h> //Import libraries for usage
#include "set.h"    //Import header file
#include "list.c"
#include "list.h"

typedef struct set{ //Define our struct set
    void **data;//Pointer to an array of character strings
    int length; //Length of array
    int count; //Number of elements in array
    int (*compare)(); //Pointer to compare function passed through
    unsigned (*hash)(); //Pointer to hash function passed through
}SET;

//O(n)
SET *createSet(int maxElts, int(*compare)(), unsigned(*hash)()){ //Creates out set using variables initialized in struct set
    SET *sp;
    sp = malloc(sizeof(SET));
    assert(sp != NULL);
    sp -> count = 0;
    sp -> length = maxElts/20;
    sp -> data = malloc(sizeof(LIST*)* (sp -> length)); //Allocate memory size of list for length elts
    assert(sp -> data != NULL); //Make sure data is not NULL
    for(int i = 0; i < sp -> length; i++) //Make list for each hash location
        sp -> data[i] = createList(compare);
    sp -> compare = compare;
    sp -> hash = hash;
    return sp;
}

//O(n)
void destroySet(SET *sp){
    for(int i; i < sp -> length; i++)//Destroy every list in table
        destroyList(sp -> data[i]);
    free(sp -> data);//Free up hash table
    free(sp); //Free set
}

//O(1)
int numElements(SET *sp){
    return sp -> count;//Return the number of elements in array
}

//O(1)
void addElement(SET *sp, void *elt){
    assert(sp != NULL && elt != NULL); //make sure set and elt are not NULL
    unsigned index;
    index = sp -> hash(elt) % sp -> length; //hash key to find address
    addFirst(sp -> data[index], elt); //Call addFirst list function
    sp -> count++; //Increase count by 1 to account for adding an elt
}

//O(1)
void removeElement(SET *sp, void *elt){
    assert(sp != NULL && elt != NULL);
    unsigned index;
    index = sp -> hash(elt) % sp -> length;
    removeItem(sp -> data[index], elt); //Call removeItem list function
    sp -> count--;//Decrease count by 1 to account for deleting an elt
}

//O(n)
void *findElement(SET *sp, void *elt){
    assert(sp != NULL && elt != NULL);
    unsigned index;
    index = sp -> hash(elt) % sp -> length;
    void* x = findItem(sp -> data[index], elt);//call findItem list function
    return x;//return found elt
}

//O(n)
void *getElements(SET *sp){ //we want to only have array of elts from hash table
    assert(sp != NULL); //Make sure set sp is not NULL
    void** ret = malloc(sizeof(LIST*)* sp -> count);//Allocate memory the size of count for array ret
    assert(ret != NULL);
    
    int j = 0; //need two counters, one for new array and one for table
    for(int i = 0; i < sp -> length; i++){
        if(sp -> data[i] != NULL){
            ret[j] = getItems(sp -> data[i]);
        }
    }
    return ret;//Return elts
}
