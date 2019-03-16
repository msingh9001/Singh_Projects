//
//  generic-table.c
//
//  Created by Mandeep Singh on 02/08/19.
//  Copyright © 2019 Mandeep Singh. All rights  .
//
#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "set.h"  //Import libraries for usage
#define EMPTY 0
#define FILLED 1
#define DELETED 2

static int search(SET *sp, void *elt, bool *found);//Initialize our private search function

typedef struct set{ //Define our struct set
    void **data;//Pointer to an array of character strings
    int length; //Length of array
    int count; //Number of elements in array
    char *flag;//Pointer to array of characters for flag array
    int (*compare)(); //Pointer to compare function passed through
    unsigned (*hash)(); //Pointer to hash function passed through
}SET;

//O(n)
SET *createSet(int maxElts, int(*compare)(), unsigned(*hash)()){ //Creates out set using variables initialized in struct set
    SET *sp;
    sp = malloc(sizeof(SET));
    assert(sp != NULL);
    sp -> count = 0;
    sp -> length = maxElts;
    sp -> data = malloc(sizeof(void*)*maxElts);
    assert(sp -> data != NULL);
    sp -> flag = malloc(sizeof(void*)*maxElts);
    assert(sp -> flag != NULL);
    for(int z = 0; z < sp->length; z++)//Set all vals in flag array to EMPTY
        sp -> flag[z] = EMPTY;
    sp -> compare = compare;
    sp -> hash = hash;
    return sp;
}

//O(1)
void destroySet(SET *sp){
    assert(sp != NULL);//Checking to see if array elts are NULL
    free(sp -> data);//Freeing up memory in hash table
    free(sp->flag);
}

//O(1)
int numElements(SET *sp){
    assert(sp != NULL);
    return sp -> count;//Return the number of elements in array
}

//O(n) for worst case
void addElement(SET *sp, void *elt){
    assert(sp != NULL && elt != NULL);
    bool found = false;//Found is false
    int index = search(sp, elt, &found);//Run search function
    if(found){
        //        printf("This element already exists");
    }else{
        sp -> data[index] = elt; //Set location of first empty/delete to elt
        sp -> flag[index] = FILLED;//Flag location is now FILLED
        sp -> count++;//Increase count by 1 to account for new elt
    }
}

//O(n) for worst case
void removeElement(SET *sp, void *elt){
    assert(sp != NULL && elt != NULL);
    bool found = false;//Found is false
    int index = search(sp, elt, &found);//Run search function
    if(found){ //If found is true
        sp -> flag[index] = DELETED;//Set flag to deleted
        sp -> count--;//Decrease count by 1 to account for deleting an elt
    }else
        printf("That elt doesn't exist\n");
}

//O(n)
void *findElement(SET *sp, void *elt){
    assert(sp != NULL && elt != NULL);
    bool found = false; //If found is false
    int index = search(sp, elt, &found);//Run search function
    if(found)
        return sp -> data[index];//Return the elt found
    else
        return 0;
}

//O(n)
void *getElements(SET *sp){
    assert(sp != NULL);
    int i,j;//initializing counters
    void** ret = malloc(sizeof(void*)* sp -> count);//Allocate memory the size of count for array ret
    assert(ret != NULL);
    
    for(i = 0; i < sp -> length; i++){
        if(sp -> flag[i] == FILLED){
            ret[j] = sp -> data[i];//If the flag[i] is FILLED, go to data[i] and copy to ret[j]
            j++;//This way every index of ret is only the FILLED data vals and no empty slots
        }else
            continue;
    }
    return ret;//Return elt
    //we want to only have array of filled elts from hash table not empty or deleted vals
    //need two counters, one for table/flag and one for new array
}

//O(n)
static int search(SET *sp, void *elt, bool *found){
    assert(sp != NULL && elt != NULL);
    unsigned hasher = sp->hash(elt); //creating var for the client provided hash func
    int mod = hasher  % sp -> length; //modulos
    int b = -1;
    
    for(int j = 0; j < sp -> length; j++){ //loop through entire table (0->legnth) to search for elt
        int addy = (mod + j) % sp -> length; //Remod and have linear probing
        
        if(sp -> flag[addy] == FILLED){ //go through flags and know where the first delete or empty flag is in case elt doesnt exist
            if(sp->compare(elt, sp -> data[addy]) == 0){ //compare elt and data[addy]
                *found = true; //found is true
                return addy; //return loc of elt
            }else
                continue;
        }else if(sp -> flag[addy] == DELETED){ //if deleted
            if(b == -1){
                b = addy;//set b to the loc of first deleted
            }else
                continue;
        }else if(sp -> flag[addy] == EMPTY){ //if empty
            if(b == -1){
                b = addy;//sets loc of first empty
            }if(b != -1)
                continue;
        }
    }
    *found = false; //if elt DNE, found is false
    return b;//return loc of either first empty or deleted loc
}
