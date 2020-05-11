//
//  sha3_functions.cpp
//  SHA3
//
//  Created by Mandeep Singh on 5/9/20.
//  Copyright © 2020 Mandeep Singh. All rights reserved.
//

#include "sha3_functions.hpp"
#include <iostream>
//XOR function
int XOR(int a, int b){
    if((a == 0 && b == 1) || (a == 1 && b == 0))
        return 1;
    else
        return 0;
}
//Converts 1D array to 3D array
void inputSHA3(int v[], int a[5][5][64]){
    for(int i = 0; i < 5; i++)
        for(int j = 0; j < 5; j++)
            for(int k = 0; k < 64; k++)
                a[i][j][k] = v[64 * ((5 * j) + i) + k];
}

void theta(int a_in[5][5][64], int a_out[5][5][64]){
    for(int i = 0; i < 5; i++)
        for(int j = 0; j < 5; j++)
            for(int k = 0; k < 64; k++){
                int column_left_sum = 0, column_right_sum = 0, final_sum = a_in[i][j][k];
                //Loop through and sum(XOR) left column
                for(int l = 0; l < 5; l++)
                    column_left_sum = XOR(column_left_sum, a_in[(i-1)%5][l][k]);
                final_sum = XOR(final_sum, column_left_sum);
                //Loop through and sum(XOR) right column
                for(int l = 0; l < 5; l++)
                    column_right_sum = XOR(column_right_sum, a_in[(i+1)%5][l][(k-1)%64]);
                //XOR sums with a_in[i][j][k]
                final_sum = XOR(final_sum, column_right_sum);
                a_out[i][j][k] = final_sum;
            }
}
//Use rho matrix to find the output of t value and subtract from k
void rho(int a_in[5][5][64], int a_out[5][5][64]){
    int rhomatrix[5][5] = {{0,36,3,41,18}, {1,44,10,45,2}, {62,6,43,15,61}, {28,55,25,21,56}, {27,20,39,8,14}};
    for(int i = 0; i < 5; i++)
        for(int j = 0; j < 5; j++)
            for(int k = 0; k < 64; k++)
                a_out[i][j][k] = a_in[i][j][((k-rhomatrix[i][j]) + 64)%64];
}
//use j for i index and use (2*i + 3*j)%5 to find j index 
void pi(int a_in[5][5][64], int a_out[5][5][64]){
    for(int i = 0; i < 5; i++)
        for(int j = 0; j < 5; j++)
            for(int k = 0; k < 64; k++)
                a_out[j][(2*i + 3*j)%5][k] = a_in[i][j][k];
}
//Use function to find index for v_out that corresponds to a[i][j][k]
void outputSHA3(int a[5][5][64], int v_out[]){
    for(int i = 0; i < 5; i++)
        for(int j = 0; j < 5; j++)
            for(int k = 0; k < 64; k++)
                v_out[(64 * ((5 * j) + i)) + k] = a[i][j][k];
}
