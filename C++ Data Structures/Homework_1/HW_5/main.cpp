//
//  main.cpp
//  HW_5
//
//  Created by Mandeep Singh on 4/10/19.
//  Copyright © 2019 Mandeep Singh. All rights reserved.
//

#include <iostream>
#include <cctype>
#include <iostream>
#include <cstdlib>
#include "sequence.hpp"

using namespace std;

int main(int argc, const char * argv[]) {
    sequence test; // A sequence that we’ll perform tests on
    
    test.insert(30);
    test.insert(90);
    test.insert(20);
    test.insert(10);
    test.insert(40);
    cout << test.size() << "\n" << test.current() <<  endl;
    
}
