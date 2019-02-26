//
//  main.c
//  Example 1
//
//  Created by Mandeep Singh on 01/09/19.
//  Copyright © 2019 Mandeep Singh. All rights  .
//

#include<stdio.h>
#define MAX_WORD_LEGNTH 30   //Setting the max words variable as 30

int main(int argc, char *argv[])  //Initializing main function with two parameters

{
    FILE *file1; //Setting pointer to file1
    int count = 0; //Initializing and setting the word count to 0

    char a1[MAX_WORD_LEGNTH+1]; //Creating character array to store strings in

    if(argc == 1){  //If no filepath given
        printf("No arguments were passed\n");  //Print statement
        
        }else{  //otherwise
            
    file1 = fopen(argv[1], "r"); //setting file1 as reading argv[1]
    if(file1 == NULL)  //If file not found
        printf("file not found\n"); //Return statement

    while(fscanf(file1, "%s", a1) == 1) {  //While fscanf returns 1 for reading file 1 and placing the string in a1
        count++; //Add 1 to count variable
        }
    printf("%d total words\n", count);   //Print statement with # of words in file
    }
  return 0;    //Return 0 to verify program ran all the way through properly
}
