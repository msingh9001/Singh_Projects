//
//  strings-table.c
//
//  Created by Mandeep Singh on 02/01/19.
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
#define DELETED 2 //Define our flag values

static int search(SET *sp, char *elt, bool *found);//Initialize our private search function

typedef struct set{ //Define our struct set
    char **data;//Pointer to an array of character strings
    int length; //Length of array
    int count; //Number of elements in array
    char *flag;//Pointer to array of characters for flag array
}SET;

//O(n)
SET *createSet(int maxElts){ //Creates out set using variables initialized in struct set
    SET *sp;
    sp = malloc(sizeof(SET));
    assert(sp != NULL);
    sp -> count = 0;
    sp -> length = maxElts;
    sp -> data = malloc(sizeof(char*)*maxElts);
    assert(sp -> data != NULL);
    sp -> flag = malloc(sizeof(char)*maxElts);
    assert(sp -> flag != NULL);
    for(int z = 0; z < maxElts; z++)//Set all vals in flag array to EMPTY
        sp -> flag[z] = EMPTY;
    return sp;
}

//O(n)
void destroySet(SET *sp){
    assert(sp != NULL);//Checking to see if array elts are NULL
    for(int i = 0; i < sp -> count; i++)
        if(sp -> flag[i] == FILLED || sp -> flag[i] == DELETED)
            free(sp -> data[i]);//Freeing up memory in hash table
}

//O(1)
int numElements(SET *sp){
    assert(sp != NULL);
    return sp -> count;//Return the number of elements in array
}

//O(n) for worst case
void addElement(SET *sp, char *elt){
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
void removeElement(SET *sp, char *elt){
    assert(sp != NULL && elt != NULL);
    bool found = false;//Found is false
    int index = search(sp, elt, &found);//Run search function
    if(found){ //If found is false
        sp -> flag[index] = DELETED;//Set flag to deleted
        sp -> count--;//Decrease count by 1 to account for deleting an elt
    }else
        printf("That elt doesn't exist\n");
}

//O(n)
char *findElement(SET *sp, char *elt){
    assert(sp != NULL && elt != NULL);
    bool found = false;//If found is false
    int index = search(sp, elt, &found);//Run search function
    if(found)
        return sp -> data[index];//Return the elt found
    else
        return 0;
}

//O(n)
char **getElements(SET *sp){
    assert(sp != NULL);
    int i,j;//initializing counters
    assert(sp != NULL);
    char** ret = malloc(sizeof(char*)* sp -> count);//Allocate memory the size of count for array ret
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

unsigned strhash(char *s){ //Hash function
    unsigned hash = 0;
    
    while(*s != '\0')
        hash = 31 * hash + *s ++;
    
    return hash;
}

//O(n)
static int search(SET *sp, char *elt, bool *found){
    assert(sp != NULL && elt != NULL);
    int mod = strhash(elt) % sp -> length; //modulos
    int b = -1;
    
    for(int j = 0; j < sp -> length; j++){ //loop through entire table (0->legnth) to search for elt
        int addy = (mod + j) % sp -> length; //Remod and have linear probing
        
        switch (sp -> flag[addy]) { //go through flags and know where the first delete or empty flag is in case elt doesnt exist
            case FILLED: //If filled
                if(strcmp(elt, sp -> data[addy]) == 0){ //compare elt and data[addy]
                    *found = true;//found is true
                    return addy; //return loc of elt
                }else{
                    continue;
                    break;
                    
                case DELETED: //if deleted
                    if(b == -1)
                        b = addy; //set b to the loc of first deleted
                    if(b != -1)
                        continue;
                    break;
                    
                case EMPTY: //if empty
                    if(b == -1)
                        b = addy; //sets loc of first empty
                    if(b != -1)
                        continue;
                    break;
                    
                default:
                    break;
                }
        }
    }
    *found = false; //if elt DNE, found is false
    return b;//return loc of either first empty or deleted loc
}
