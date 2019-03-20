//
//  bubble-sort.c
//
//  Created by Mandeep Singh on 03/19/19.
//  Copyright © 2018 Mandeep Singh. All rights  .
//
//Utilizing the bubble sort algorithm to sort an integer array
#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h> //Import libraries for usage
#define NUM_OF_ELEMENTS 7

void bubbleSort(int arr[]);

int main(){
    int myarray[NUM_OF_ELEMENTS] = {6, 4, 7, 9, 2, 0, 19};
    bubbleSort(myarray);
    for(int i = 0; i < NUM_OF_ELEMENTS; i++)
        printf("%d\n", myarray[i]);
}

//O(n^2) & stable
void bubbleSort(int arr[]){
    int i, j;
    for(i = 0; i < NUM_OF_ELEMENTS; i++){
        for(j = NUM_OF_ELEMENTS - 1; j > i; j--){
            if(arr[j] < arr[j - 1]){
                int temp = arr[j - 1];
                arr[j - 1] = arr[j];
                arr[j] = temp;
            }
        }
    }
}
