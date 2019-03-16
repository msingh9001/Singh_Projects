//
//  dataset.c
//
//  Created by Mandeep Singh on 03/10/19.
//  Copyright © 2019 Mandeep Singh. All rights  .
//
//

# ifndef DATASET_H
# define DATASET_H

typedef struct set SET;

SET *createDataSet(int maxElts);

void destroyDataSet(SET *sp);

void addElement(SET *sp, int age, int ID);

void removeElements(SET *sp, int age);

void searchAge(SET *sp, int age);

void maxAgeGap(SET *sp);

# endif /* DATASET_H */
