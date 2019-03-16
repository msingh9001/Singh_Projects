//
//  college.c
//
//  Created by Mandeep Singh on 03/14/19.
//  Copyright © 2019 Mandeep Singh. All rights  .
//
//
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <stdbool.h>
#include <time.h>
# include "dataset.h"
# define MAX_SIZE 3000

int main()
{
    SET *records;
    records = createDataSet();
    
    /* Insert all records into the set. */
    
    int ID = 0;
    int age;
    srand(time(NULL));
    for(int i = 0; i < 1000; i++){
        int r = (rand() % 1) + 2; //A number between 0 and 1 randomly chosen and increased by 1 so range is [1,2]
        age = (rand() % 12) + 18; //A number between 0 and 12 randomly chosen and increased by 18 so range is [18,30]
        ID += r;
        addElement(records, ID, age);
    }
    printf("All IDs successfully added\n");
    age = (rand() % 12) + 18; //A number between 0 and 12 randomly chosen and increased by 18 so range is [18,30]
    searchAge(records, age);
    age = (rand() % 12) + 18; //A number between 0 and 12 randomly chosen and increased by 18 so range is [18,30]
    removeElement(records, age);
    maxAgeGap(records);
    destroyDataSet(records);
    exit(EXIT_SUCCESS);
}
