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

void addElement(SET *sp, int elt, int ID);

void removeElement(SET *sp, int ID);

int searchID(SET *sp, int ID);

# endif /* DATASET_H */
