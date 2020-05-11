//
//  main.cpp
//  SHA3
//
//  Created by Mandeep Singh on 5/9/20.
//  Copyright © 2020 Mandeep Singh. All rights reserved.
//
#include <iostream>
#include<string>
#include "sha3_functions.hpp"

using namespace std;
int main(int argc, const char * argv[]) {
    int v[1600], a[5][5][64], a_out[5][5][64], v_out[1600];
//Because my terminal limited the input legnth of the bitsream, I have to input halves and then append them in order for my input to be read
    string str1, str2;
    cout << "Please enter the first half of your 1600 bit input:" << endl;
    cin >> str1;
    cout << "Please enter the second half of your 1600 bit input:" << endl;
    cin >> str2;
    str1.append(str2);
    
    for(int i = 0; i < 1600; i++)
        v[i] = str1[i] - 48;
//Since C++ does not allow me to return arrays, I pass them into functions
    inputSHA3(v, a);
//Run sha3 operations and output a_out[2][3][11->20] for each operation output
    for(int i = 0; i < 5; i++)
        for(int j = 0; j < 5; j++)
            for(int k = 0; k < 64; k++)
                cout << a[i][j][k];
    cout << endl;
    theta(a, a_out);
    for(int i = 11; i < 21; i++)
        cout << a_out[2][3][i];
    cout << endl;
    rho(a, a_out);
    for(int i = 11; i < 21; i++)
        cout << a_out[2][3][i];
    cout << endl;
    pi(a, a_out);
    for(int i = 11; i < 21; i++)
        cout << a_out[2][3][i];
    cout << endl;
    for(int i = 9; i < 19; i++)
        cout << a_out[4][3][i];
    cout << endl;
    outputSHA3(a_out, v_out);
    return 0;
}
