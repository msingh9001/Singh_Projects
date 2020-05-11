//
//  keystream_generation.cpp
//  RC4
//
//  Created by Mandeep Singh on 4/23/20.
//  Copyright © 2020 Mandeep Singh. All rights reserved.
//
#include <string>
#include <iostream>
#include <cmath>
#include "keystream_generation.hpp"

void keystream_generation(int n, int l, int* key, int* ks, int key_bits_length){
    int vectorLength = static_cast<int>(pow(2, n) - 1);
    //Initialize S and T vectors
    int S[vectorLength], T[vectorLength];
    //Fill S vector from 0 -> 2^n-1 and vector T with key bits repeatedly
    for(int i = 0; i < static_cast<int>(pow(2, n)); i++){
        S[i] = i;
        T[i] = key[i % (key_bits_length/n)];
    }
    //Do swapping
    int j = 0;
    for(int i = 0; i < static_cast<int>(pow(2, n)); i++){
        j = (j + S[i] + T[i]) % static_cast<int>(pow(2, n));
        swap(S, i, j);
    }
    //Stream Generation
    int a = 0, b = 0, t;
    for(int i = 0; i < l; i++){
        a = (a+1) % static_cast<int>(pow(2, n));
        b = (b + S[a]) % static_cast<int>(pow(2, n));
        swap(S, a, b);
        t = (S[a] + S[b]) % static_cast<int>(pow(2, n));
        ks[i] = S[t];
    }
}

void swap(int* S, int i, int j){
    int temp = S[j];
    S[j] = S[i];
    S[i] = temp;
}

void decimalToBinary(int n, int* ks, int* keystream){
    //Initialize temp array to hold binary values for each decimal at a time
    int temparr[n], temp, keystreamCounter = 0;
    int l = sizeof(&ks)/sizeof(ks[0]);
    //Loop through ks and convert all decimals to binary
    for(int i = 0; i < l; i++){
        //Set temp = next decimal number to be converted
        temp = ks[i];
        int j = 0;
        //Looping through to find binary values
        while(temp > 0){
            //Storing remainder in binary array
            temparr[j] = n % 2;
            temp = temp / 2;
            j++;
        }
        //Since the binary representation in temp is backwards we store it into keystream correctly
        for(int k = keystreamCounter; k < n; k++){
            keystream[k] = temparr[(n-1)-k];
            keystreamCounter++;
        }
    }
}

int convertBitArrayToInt(int n, int* key_bits, int loc){
    //Loop through key_bits and calculate decimal value
    int decimal = 0, power = 1;
    for(int i = 0; i < n; i++){
        decimal += key_bits[(loc+(n-1)) - i] * power;
        power *= 2;
    }
    return decimal;
}
