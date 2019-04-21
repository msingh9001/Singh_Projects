//
//  main.cpp
//  HW_2
//
//  Created by Mandeep Singh on 4/17/19.
//  Copyright © 2019 Mandeep Singh. All rights reserved.
//

#include <iostream>
#include "bag.hpp"

using namespace std;
int main(int argc, const char * argv[]) {
    set b1;
    set b2;
    b1.insert(3);
    b1.insert(8);
    b1.insert(7);
    b1.insert(10);
    std::cout << b1.size() << endl;
    b1.insert(10);
    std::cout << b1.size() << endl;
    b2.insert(10);
    b2.insert(12);
    b2.insert(3);
    std::cout << b2.size() << endl;
    
    EXIT_SUCCESS;
}
