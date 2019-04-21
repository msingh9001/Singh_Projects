//
//  main.cpp
//  HW_3
//
//  Created by Mandeep Singh on 4/18/19.
//  Copyright © 2019 Mandeep Singh. All rights reserved.
//

#include <iostream>
#include "bag.hpp"

int main(int argc, const char * argv[]) {
    std::bag b1;
    b1.insert(1, 5);
    b1.insert(2, 10);
    b1.print();
    b1.insert(3, 7);
    b1.insert(8, 2);
    b1.insert(3, 10);
    b1.print();
    b1.remove(1);
    b1.remove(9);
    b1.print();
}
