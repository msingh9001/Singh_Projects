//
//  sorted.c
//
//  Created by Mandeep Singh on 01/23/19.
//  Copyright © 2019 Mandeep Singh. All rights  .
//
#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "set.h"  //Import libraries for usage

static int mybsearch(SET *sp, char *elt, bool *found);//Initialize our private search function

typedef struct set{ //Define our struct set
    char **data;//Pointer to an array of character strings
    int length; //Length of array
    int count; //Number of elements in array
}SET;

//O(1)
SET *createSet(int maxElts){ //Creates out set using variables initialized in struct set
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
void destroySet(SET *sp){
    assert(sp != NULL);//Checking to see if array elts are NULL
    for(int i = 0; i < sp -> count; i++)
        free(sp -> data[i]);//Freeing up memory
}

//O(1)
int numElements(SET *sp){
    assert(sp != NULL);
    return sp -> count;//Return the number of elements in array
}

//O(nlogn) for worst case
void addElement(SET *sp, char *elt){
    assert(sp != NULL && elt != NULL);
    bool found = false;//Found is false
    int index = mybsearch(sp, elt, &found);//Run search function
    if(found == true){
        //        printf("This element already exists");
    }else{
        for(int i = sp -> count; i > index; i--)
            sp -> data[i] = sp -> data[i-1];//Shift up elts in array
        sp -> data[index] = strdup(elt);//Insert elt to respective index
        sp -> count++;//Increase count by 1 to account for new elt
    }
}

//O(nlogn) for worst case
void removeElement(SET *sp, char *elt){
    assert(sp != NULL && elt != NULL);
    bool found = false;
    int index = mybsearch(sp, elt, &found);//Run search function
    if(found == true){
        for(int i = index + 1; i < sp -> count; i++)
            sp -> data[i-1] = sp -> data[i];//Shift elements down
        sp -> count--;//Decrease count by 1 to account for deleting an elt
    }else{
        //        printf("That element doesn't exist");
    }
}

//O(logn)
char *findElement(SET *sp, char *elt){
    assert(sp != NULL && elt != NULL);
    bool found = false;
    int find = mybsearch(sp, elt, &found);//Run search function
    
    if(found)
        return sp -> data[find];//Return the elt found
    else
        return NULL;
}

//O(1)
char **getElements(SET *sp){
    assert(sp != NULL);
    char** ret = malloc(sizeof(char*)* sp -> count);//Allocate memory the size of count for array ret
    memcpy(ret, sp -> data, sizeof(char*)* (sp -> count));//Copy the chunk of memory from original array to array ret
    return ret;//Return ret
}

//O(logn)
static int mybsearch(SET *sp, char *elt, bool *found){
    assert(sp != NULL && elt != NULL);
    int lo, hi, mid;//initialize variables
    lo = 0, hi = sp -> count - 1;//Give two variables values
    while(lo <= hi){
        mid = (hi + lo)/2;
        if(strcmp(elt, sp -> data[mid]) == 0){ //Compare the strings elt and all the elts in data[] to see if there is any match
            *found = true;//If there is found is true and mid is returned since that is the index where it was found
            return mid;
        }
        if(strcmp(elt, sp -> data[mid]) > 0) //elt is larger than the elt at data[]
            lo = mid + 1;//The elt we are searching for is larger than mid so lo is increased
        else
            hi = mid - 1;// The elt we are searching for is smaller than mid so hi is decreased
    }
    *found = false;//If elt is never found in data[] found is false
    return lo;//lo is returned
}
