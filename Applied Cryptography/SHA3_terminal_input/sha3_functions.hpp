//
//  sha3_functions.hpp
//  SHA3
//
//  Created by Mandeep Singh on 5/9/20.
//  Copyright © 2020 Mandeep Singh. All rights reserved.
//

#ifndef sha3_functions_hpp
#define sha3_functions_hpp

#include <stdio.h>
int XOR(int a, int b);
void inputSHA3(int v[], int a[5][5][64]);
void theta(int a_in[5][5][64], int a_out[5][5][64]);
void rho(int a_in[5][5][64], int a_out[5][5][64]);
void pi(int a_in[5][5][64], int a_out[5][5][64]);
void outputSHA3(int a[5][5][64], int v_out[]);
#endif /* sha3_functions_hpp */
