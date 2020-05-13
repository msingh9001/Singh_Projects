//
//  part3.cpp
//  Lab_1
//
//  Created by Mandeep Singh on 4/4/19.
//  Copyright © 2019 Mandeep Singh. All rights reserved.
//
#include <iostream>
#include <string>
#include <fstream>
#include <ctype.h>
#include <stdio.h>
#include "part3.hpp"

using namespace std;

void part3(){
    string str;
    ifstream ifile;// declaring an object of class ifstream
    ifile.open("/Users/msingh9001/Desktop/COEN_179/Lab_1/Lab_1/GettysburgAddress.txt");// open file for reading
    cout <<"Reading data from a file :-" << endl;
    
    while(!ifile.eof() && ifile >> str){// while the end of file [ eof() ] is not reached
        for(int i = 0; i < str.length(); i++){
            if(!isalnum(str[i]))
                str.erase(str.begin() + i);
        }
        if(str.length() > 9){
            for(int k = 0; k < str.length(); k++){
                printf("%c", toupper(str[k]));
            }
            cout << "\n" << endl;
        }
    }
    ifile.close();// close the file
}
