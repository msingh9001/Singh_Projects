//
//  unsorted.c
//
//  Created by Mandeep Singh on 01/16/19.
//  Copyright © 2019 Mandeep Singh. All rights  .
//
#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "set.h"  //Call libraries

static int search(SET *sp, char *elt, bool *found);//initializing our private search function

typedef struct set{ //initialize struct
    char **data;//Pointer to an array of character strings
    int length; //Length of array
    int count; //Number of elements in array
}SET;

//O(1)
SET *createSet(int maxElts){ //Creates our set using variables defined in the struct
    SET *sp;
    sp = malloc(sizeof(SET));
    assert(sp != NULL);
    sp -> count = 0;
    sp -> length = maxElts;
    sp -> data = malloc(sizeof(char*)*maxElts);
    assert(sp -> data != NULL);
    return sp;
}

//O(n)
void destroySet(SET *sp){ //destory set returns nothing hence void
    assert(sp != NULL);//Checking array has no NULL elts
    for(int i = 0; i < sp -> count; i++)
        free(sp -> data[i]);//Freeing up memory
    free(sp -> data);
    free(sp);
}

//O(1)
int numElements(SET *sp){ //done
    assert(sp != NULL);
    return sp -> count;//Returns the number of elements in the array
}

//O(n)
void addElement(SET *sp, char *elt){
    assert(sp != NULL && elt != NULL);
    bool found = false;
    int find = search(sp, elt, &found);//Search function is O(n)//Run search function
    if(found){
        //printf("This element already exists");
    }
    else{
        sp -> data[sp -> count] = strdup(elt);
        sp -> count++;// Add 1 to count to account for the new element
    }
}

//O(n)
void removeElement(SET *sp, char *elt){
    assert(sp != NULL && elt != NULL);
    bool found = false;
    int check = search(sp, elt, &found);//run search function
    if(check){
        sp -> data[check] = sp -> data[sp -> count - 1];//Take last element and move it to the index of elt we want to remove
        sp -> count--;//Shrink the array size by 1 to eliminate last elt
    }else{
        // printf("That element doesn't exist");
    }
}

//O(n)
char *findElement(SET *sp, char *elt){
    assert(sp != NULL && elt != NULL);
    bool found = false;
    int find = search(sp, elt, &found);//run search function
    
    if(found)
        return sp -> data[find];//return elt at data[find]
    else
        return NULL;//return nothing
}

//O(1)
char **getElements(SET *sp){
    assert(sp != NULL);
    char** ret = malloc(sizeof(char*)* sp -> count);//allocating memory the size of original array for array ret
    memcpy(ret, sp -> data, sizeof(char*)* (sp -> count));//Copying the chunk of data from the original array to array ret
    return ret;
}

//o(n)
static int search(SET *sp, char*elt, bool*found){
    assert(sp != NULL && elt != NULL);
    for(int i = 0; i < sp -> count; i++){
        int result = strcmp(sp -> data[i], elt);//Comparing the string elt with each elt in array to see if it already exists
        if(result == 0){
            *found = true;
            return i;//the index at which found becomes true is returned
        }
    }
    *found = false;
    return -1;
}
