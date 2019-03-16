//
//  dataset.c
//
//  Created by Mandeep Singh on 03/10/19.
//  Copyright © 2019 Mandeep Singh. All rights  .
//
//
#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "dataset.h"  //Import libraries for usage

typedef struct set{ //Define our struct set
    int *data;//Pointer to an array of integers
    int length; //Length of array
    int count; //Number of elements in array
}SET;

//O(n)
SET *createDataSet(int maxElts){ //Creates out set using variables initialized in struct set
    SET *sp;
    sp = malloc(sizeof(SET)); //Allocate memory for set
    assert(sp != NULL);
    sp -> count = 0; //Set count to 0
    sp -> length = maxElts; //Set length to maxElts
    sp -> data = malloc(sizeof(int*)* maxElts); //Allocate memory for array data
    assert(sp -> data != NULL);
    for(int i = 0; i < sp -> length; i++){
        sp -> data[i] = 0; //Set all vals in array data to 0
    }
    return sp;
}

//O(1)
void destroyDataSet(SET *sp){
    assert(sp != NULL);//Checking to see if array elts are NULL
    free(sp -> data); //Free array data
    free(sp); //Free set sp
    printf("All records successfully destroyed\n");
}

//O(1) for worst case
void addElement(SET *sp, int elt, int ID){
    assert(sp != NULL);
    sp -> data[ID] = elt; //Insert elt at loc ID
    sp -> count++;//Increase count by 1 to account for new elt
}

//O(1) for worst case
void removeElement(SET *sp, int ID){
    assert(sp != NULL);
    int search = searchID(sp, ID); //Utilize search func
    if(search != 0){ //If search is true
        sp -> data[ID] = 0; //Set index at ID to 0
        printf("Record was found and deleted\n");
        sp -> count--; //Decrement to account for deleted elt
    }else
        printf("Deletion could not be done\n");
}

//O(1)
int searchID(SET *sp, int ID){
    assert(sp != NULL);
    int temp = sp -> data[ID]; //Since we are using ID to index mapping in an unsorted array, search is O(1)
    
    if(temp == 0) //0 means no ID exists there
        printf("Student ID: %d\nStudent Age: No student associated with this ID\n", ID);
    else //ID exists
        printf("Student ID: %d\nStudent Age: %d\n", ID, temp);
    
    return temp;
}
