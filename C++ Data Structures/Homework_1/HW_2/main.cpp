//
//  main.cpp
//  HW_2
//
//  Created by Mandeep Singh on 4/7/19.
//  Copyright © 2019 Mandeep Singh. All rights reserved.
//

#include <iostream>
#include "statistician.hpp"

using namespace std;

int main(int argc, const char * argv[]) {
    statistician s;
    s.next_number(-10);
    s.next_number(5);
    s.next_number(-5);
    s.next_number(10);
    s.next_number(5);
    s.next_number(-5);
    cout << "Length is: " << s.get_length() << "\nSum is: " << s.get_sum() << "\nAverage is: " << s.get_avg() << "\nSmallest is: " << s.get_smallest() << "\nLargest is: " << s.get_largest() << "\nLast Number is: " << s.get_lastNum() << endl;
    EXIT_SUCCESS;
}
