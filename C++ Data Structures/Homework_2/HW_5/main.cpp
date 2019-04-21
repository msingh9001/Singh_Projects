//
//  main.cpp
//  HW_5
//
//  Created by Mandeep Singh on 4/18/19.
//  Copyright © 2019 Mandeep Singh. All rights reserved.
//

#include <iostream>
#include "kbag.hpp"
#include "sequence1.hpp"
#include "set.hpp"
using namespace std;
int main(int argc, const char * argv[]) {
    kbag k1;
    kbag k2(32);
    cout<< k1.cap() << " " << k2.cap() << endl;
    sequence s1;
    sequence s2(17);
    cout<< s1.cap() << " " << s2.cap() << endl;
    set set1;
    set set2(15);
    cout<< set1.cap() << " " << set2.cap() << endl;
    EXIT_SUCCESS;
}
