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

static int mybsearch(SET *sp, int elt, bool *found);//Initialize our private search function

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
        sp -> data[i] = 0; //Set all values in data to 0
    }
    return sp;
}

//O(1)
void destroyDataSet(SET *sp){
    assert(sp != NULL);//Checking to see if array elts are NULL
    free(sp -> data); //Free array data
    free(sp); //Free set
    printf("All records successfully destroyed\n");
}

//O(n) for worst case
void addElement(SET *sp, int age, int ID){
    assert(sp != NULL);
    bool found = false;
    int index = mybsearch(sp, age, &found); //O(logn) search func
    
    for(int i = sp -> count; i > index; i--)
        sp -> data[i] = sp -> data[i-1];//Shift up elts in array
    sp -> data[index] = age;//Insert elt to respective index
    sp -> count++;//Increase count by 1 to account for new elt
}

//O(n) for worst case
void removeElements(SET *sp, int age){
    assert(sp != NULL);
    
    bool found = false;
    int exist = mybsearch(sp, age, &found);//Use to check if age even exists so if it doesn't worse case is O(logn)
    if(true){
        int firstIndex, lastIndex;
        int j = 0;//Used to count how many repetitions of age there are
        for(int i = 0; i < sp -> count; i++){
            if(sp -> data[i] == age){
                j++; //increment j
            }
            if(sp -> data[i] != age && j != 0){
                lastIndex = i - 1; //Last index with age
                firstIndex = i - j; //First index with age
                break;
            }
        }
        for(int k = lastIndex + 1; k < sp -> count; k++){
            sp -> data[k] = sp -> data[firstIndex]; //Shifting down
            printf("Record was found and deleted\n");
            firstIndex++; //Increment so every index with age is shifted over
            sp -> count--; //Decrement to account for deleted elt
        }
    }else
        printf("No records with that age found\n");
}

//O(logn)
void searchAge(SET *sp, int age){
    assert(sp != NULL);
    
    bool found = false; //Initialize boolean
    int index = mybsearch(sp, age, &found);//Utilizing binary search
    if(false){
        printf("No student associated with this age: %d\n", age); //No IDs associated with age
    }else{
        printf("Student ID: %d\nStudent Age: %d\n", index, age); //There is ID(s) associated with age
    }
}

//O(1)
//Since this is a sorted array, largest age is at the end and smallest is at the beginning
void maxAgeGap(SET *sp){
    if(sp -> count <= 0) //If count <= 0, there are no records
        printf("There are no student records\n");
    else{
        int j = sp -> data[sp -> count - 1];//j is largest age
        int i = sp -> data[0]; //i is smallest age
        int ageGap = j - i; //ageGap is largest - smallest
        printf("The max age gap is %d\n", ageGap);
    }
}

//O(logn)
static int mybsearch(SET *sp, int elt, bool *found){
    assert(sp != NULL);
    int lo, hi, mid;//initialize variables
    lo = 0, hi = sp -> count - 1;//Give two variables values
    while(lo <= hi){
        mid = (hi + lo)/2;
        if(elt == (sp -> data[mid])){ //Compare the strings elt and all the elts in data[] to see if there is any match
            *found = true;//If there is found is true and mid is returned since that is the index where it was found
            return mid;
        }
        if(elt > sp -> data[mid]) //elt is larger than the elt at data[]
            lo = mid + 1;//The elt we are searching for is larger than mid so lo is increased
        else
            hi = mid - 1;// The elt we are searching for is smaller than mid so hi is decreased
    }
    *found = false;//If elt is never found in data[] found is false
    return lo;//lo is returned
}
