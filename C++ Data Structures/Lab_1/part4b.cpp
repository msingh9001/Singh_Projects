//
//  part4b.cpp
//  Lab_1
//
//  Created by Mandeep Singh on 4/4/19.
//  Copyright © 2019 Mandeep Singh. All rights reserved.
//
//There was no + 1 to start in line 22 which would cause a bad access error since the recursive functionality would not work
#include<iostream>
#include "part4b.hpp"

void part4b(){
    char sentence[50];
    std::cout << "Enter a string: \n";//Enter: I attend Santa Clara University
    std::cin.getline(sentence, 50);
    std::cout <<"The string you entered contains " << str_len(sentence,0) << " characters." << std::endl;
}

int str_len(char s[],int start){
    if(s[start] =='\0')
        return 0;
    return 1 + str_len(s, start + 1);
}
