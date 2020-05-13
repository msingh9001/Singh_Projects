//
//  part4a.cpp
//  Lab_1
//
//  Created by Mandeep Singh on 4/4/19.
//  Copyright © 2019 Mandeep Singh. All rights reserved.
//
#include<iostream>
#include "part4a.hpp"

void part4a(){
    char* str;
    str = "SC"; //Trying to convert from string to char*
    *(str+3) ='U'; //We are trying to insert 'U' to index 3 of str which cannot be done
    //If we were to use a char array with allocated space then we could insert into an index
    std::cout<< str;
}
