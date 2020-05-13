//
//  part2.cpp
//  Lab_1
//
//  Created by Mandeep Singh on 4/4/19.
//  Copyright © 2019 Mandeep Singh. All rights reserved.
//

#include "part2.hpp"
#include <iostream>
#include <iomanip>
#include <string>
#include <stdio.h>
#include <ctype.h>

using namespace std;

void part2(){
    string a = "0123456789";
    string b = "9876543210";
    
    cout << a << "\n" << setw(11) << b << setw(20) << a << "\n" << setw(13) << b << setw(22) << a << "\n" << setw(15) << b << setw(24) << a << "\n" << setw(17) << b << setw(26) << a << "\n" << setw(19) << b << "\n" << std::endl;
    
}
