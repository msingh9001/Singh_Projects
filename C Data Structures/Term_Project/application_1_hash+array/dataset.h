//
//  dataset.h
//
//  Created by Mandeep Singh on 03/14/19.
//  Copyright © 2019 Mandeep Singh. All rights  .
//
//

# ifndef DATASET_H
# define DATASET_H

typedef struct set{ //Define our struct set
    int **data;//Pointer to an array of integers
    int *arrayLength; //Array of integers where each index holds the length for the array at that index in the hash table
    int *arrayCount; //Array of integers where each index holds the length for the array at that index in the hash table
    int count; //Number of elements in array
    int length; //Length of hash table
    
}SET;

SET *createDataSet();

void destroyDataSet(SET *sp);

void addElement(SET *sp, int ID, int age);

void removeElement(SET *sp, int age);

void maxAgeGap(SET *sp);

int** searchAge(SET *sp, int age);

# endif /* DATASET_H */
