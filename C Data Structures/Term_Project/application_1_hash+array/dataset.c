//
//  dataset.c
//
//  Created by Mandeep Singh on 02/21/19.
//  Copyright © 2018 Mandeep Singh. All rights  .
//
//Utilizing a hash table where every index has a pointer to an array that holds IDs of all students that age
#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "dataset.h"  //Import libraries for usage

//O(n)
SET *createDataSet(){ //Creates out set using variables initialized in struct set
    SET *sp;
    sp = malloc(sizeof(SET));
    assert(sp != NULL);
    sp -> length = 13;//only have 13 possibilites from [18,30]
    sp -> arrayLength = malloc(sizeof(int*)* (sp -> length)); //Allocate memory for an array to store legnths of hash arrays
    assert(sp -> arrayLength != NULL);
    for(int i = 0; i < sp -> length; i++) //Set all counts to 0
        sp -> arrayLength[i] = 0;
    sp -> arrayCount = malloc(sizeof(int*)* (sp -> length)); //Allocate memory for an array to store counts of hash arrays
    assert(sp -> arrayCount != NULL);
    sp -> data = malloc(sizeof(int*)* (sp -> length)); //Allocate memory for hash table
    assert(sp -> data != NULL);
    for(int j = 0; j < sp -> length; j++)
        sp -> data[j] = NULL; //Set all hash table elts to NULL so we don't need to waste space preallocating each hash array
    return sp;
}

//O(n)
void destroyDataSet(SET *sp){
    assert(sp != NULL);
    for(int i = 0; i < sp -> length; i++)
        free(sp -> data[i]); //Free each array within hash table
    free(sp -> data); //Free hash table
    free(sp -> arrayCount); //Free array of count elts
    free(sp -> arrayLength); //Free array of length elts
    free(sp); //Free set
    printf("All records successfully destroyed\n");
}

//O(1) for worst case
void addElement(SET *sp, int ID, int age){
    assert(sp != NULL);
    int index = age - 18; //Hash func for proper index
    if(sp -> data[index] == NULL){
        sp -> data[index] = malloc(sizeof(int*) * 300); //If the hash table elt is NULL, then we can allocate memory for just
        sp -> count++; //Increment count
        sp -> arrayCount[index] = 0; //Set the hash array count to 0 since it has just been created
        sp -> arrayLength[index] = 300; //Set the original array length of hash array to 300 but can extend it in future w/realloc
    }else if(sp -> arrayCount[index] >= sp -> arrayLength[index]){
        sp -> arrayLength[index] += 100; //Increment length
        sp -> data[index] = realloc(sp -> data[index], sizeof(int*)* (sp -> arrayLength[index])); //Reallocate memory
    }
    sp -> data[index][sp -> arrayCount[index]] = ID; //Set ID as value of the next index in sp -> data[index]
    sp -> arrayCount[index]++; //Increment count
}

//O(1) for worst case
void removeElement(SET *sp, int age){
    assert(sp != NULL);
    int index = age - 18; //Hash func for proper index
    if(sp -> data[index] == NULL){
        printf("Deletion could not be done\n");
    }else{
        free(sp -> data[index]);
        sp -> data[index] = NULL;
        sp -> count--;
        printf("All IDs associared with age %d were deleted\n", age);
    }
}

//O(1)
int** searchAge(SET *sp, int age){
    assert(sp != NULL);
    int index = age - 18; //Hash func for proper index
    if((sp -> data[index]) == NULL)
        printf("No student IDs associated with this age: %d\n", age);
    else{
        printf("Student IDs exist here\n");
    }
    return 0;
}

//O(n)
void maxAgeGap(SET *sp){
    int i = 0, j = 12;
    while((sp -> data[i]) == NULL && i < j) //Lower wall for the smallest age
        i++;
    while((sp -> data[j]) == NULL && j > i) //Upper wall for the largest age
        j--;
    int ageGap = j - i; //ageGap is largest minus smallest
    printf("The max age gap is %d\n", ageGap);
}
