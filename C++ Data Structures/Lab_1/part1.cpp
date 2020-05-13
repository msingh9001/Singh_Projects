//
//  part1.cpp
//  Lab_1
//
//  Created by Mandeep Singh on 4/4/19.
//  Copyright © 2019 Mandeep Singh. All rights reserved.
//

#include "part1.hpp"
#include <iostream>
#include <string>

using namespace std;

void part1(){
    string input;
    cout << "Please enter a string: " << endl;
    getline(cin, input);
    int x = 0, y = 0; //x is alphanumeric counter and y is nonalphanumeric and nonspace counter
    for(int i = 0; i < input.length(); i++){
        if(isalnum(input[i])) x++;
        else if (input[i] != ' ') y++;
    }
    
    cout << "\nThere are " << x << " alpanumeric chars and " << y << " nonalphanumeric chars" << "\n" << endl;
}
