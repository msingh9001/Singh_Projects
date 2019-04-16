//
//  main.cpp
//  HW_4
//
//  Created by Mandeep Singh on 4/10/19.
//  Copyright © 2019 Mandeep Singh. All rights reserved.
//

#include <iostream>
#include "bag.hpp"
using namespace std;
int main(int argc, const char * argv[]) {
    bag b1;
    bag b2;
    bag b3;
    b1.insert(3);
    b1.insert(8);
    b1.insert(7);
    b1.insert(10);
    b1.insert(11);
    std::cout << b1.size() << endl;
    b2.insert(10);
    b2.insert(12);
    b2.insert(3);
    b1 -= b2;
    std::cout << b1.size() << endl;
    b1.insert(6);
    b3 = b1 - b2;
    std::cout << b3.size() << endl;
    
    return 0;
}
