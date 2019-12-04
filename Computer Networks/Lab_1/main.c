//
//  Created by Behnam Dezfouli
//  CSEN, Santa Clara University
//
//
// This program offers two options to the user:
// -- Option 1: enables the user to copy a file to another file.
// The user needs to enter the name of the source and destination files.
// -- Option 2: enables the user to measure the performance of file copy.
// In addition to the name of source and destination files, the user needs to enter the maximum source file size as well as the step size to increment the source file size.
//
//
// double copier(FILE *s_file, FILE *d_file)
// Precondition: s_file is a pointer to a file opened in read mode, d_file is a file pointer opened in write mode
// Postcondition: Copies the contents of the file pointed to by s_file to the file pointed to by d_file
//


#include <stdio.h>
#include <stdlib.h> // For exit()
#include <time.h>

#define SIZE 1
#define DUM_CHAR 'A'


void copier(FILE *s_file, FILE *d_file){
    char ch;
    while ((ch = fgetc(s_file)) != EOF)
        fputc(ch, d_file);
}


int main(){
    int option = 2;

    int maxFileSize = 1000000;
    int stepSize = 100000;
    clock_t start;
    clock_t end;
    double cpu_time_used;
    
    printf("Enter 1 to copy a file or enter 2 to measure the performance of file copy: ");
    scanf("%d", &option);
    
    if ( option == 1 ){ // File copy

        FILE *s_file = fopen("/Users/msingh9001/Desktop/COEN_146L/Lab_1/Untitled.rtf", "r");
        
        if(s_file == NULL){
            fclose(s_file);
            printf("Press any key to exit...");
            exit(EXIT_FAILURE);
        }
        
        FILE *d_file = fopen("/Users/msingh9001/Desktop/COEN_146L/Lab_1/dest.rtf", "w");
        
//        if(d_file == NULL){
//            fclose(d_file);
//            printf("Press any key to exit...");
//            exit(EXIT_FAILURE);
//        }
        
        copier(s_file, d_file);
        printf("File has been copied\n");
    }
    
    else if ( option == 2 ){ // File copy with performance measurement

        printf("Please enter the maximum file size (in bytes): ");
        scanf("%d", &maxFileSize);
        printf("Please enter the step size: ");
        scanf("%d", &stepSize);
        
        FILE *s_file = fopen("/Users/msingh9001/Desktop/COEN_146L/Lab_1/Untitled.rtf", "r");
        FILE *d_file = fopen("/Users/msingh9001/Desktop/COEN_146L/Lab_1/dest.rtf", "w");
        
        int current_size = stepSize;
        while(current_size < maxFileSize){
            start = clock();
            int count = 0;
            char ch = fgetc(s_file);
            while(count <= current_size){
                fputc(ch, d_file);
                count++;
            }
            end = clock();
            cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
            
            printf("The time to copy %d bytes was:  %f\n", current_size, cpu_time_used);
            current_size += stepSize;
            }
        
    }else{
        printf("Invalid option!\n");
        exit(EXIT_FAILURE);
    }
    return 0;
}
