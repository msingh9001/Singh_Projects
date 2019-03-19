//
//  selection-sort.c
//
//  Created by Mandeep Singh on 02/21/19.
//  Copyright © 2018 Mandeep Singh. All rights  .
//
//Utilizing the selection sort algorithm to sort an integer array
#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h> //Import libraries for usage
#define NUM_OF_ELEMENTS 7

void selectionSort(int arr[]);
void swap(int *x, int *y);

int main(){
    int myarray[NUM_OF_ELEMENTS] = {6, 4, 7, 9, 2, 0, 19};
    selectionSort(myarray);
    for(int i = 0; i < NUM_OF_ELEMENTS; i++)
        printf("%d\n", myarray[i]);
}

//O(n^2) & not stable
void selectionSort(int arr[]){
    for(int i = 0; i < NUM_OF_ELEMENTS - 1; i++){
        int smallest = i;
        
        for(int j = i + 1	; j < NUM_OF_ELEMENTS; j++){
            if(arr[j] < arr[smallest])
                smallest = j;
        }
        swap(&arr[smallest], &arr[i]);
    }
    
}

//O(1)
void swap(int *x, int *y){
    int temp = *x;
    *x = *y;
    *y = temp;
}
