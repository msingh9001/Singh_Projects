//
//  main.cpp
//  HW_2
//
//  Created by Mandeep Singh on 4/10/19.
//  Copyright © 2019 Mandeep Singh. All rights reserved.
//

#include <iostream>
#include "statistician.hpp"

using namespace std;

int main(int argc, const char * argv[]) {
    statistician s1;
    statistician s2;
    s1.next_number(-10);
    s1.next_number(5);
    s1.next_number(-5);
    s1.next_number(10);
    s1.next_number(5);
    s1.next_number(-5);
    s2.next_number(10);
    s2.next_number(10);
    s2.next_number(-10);
    s2.next_number(-10);
    s2.next_number(10);
    s2.next_number(14);
    statistician s3 = s1 + s2;
    cout << "Length is: " << s1.get_length() << "\nSum is: " << s1.get_sum() << "\nAverage is: " << s1.get_avg() << "\nSmallest is: " << s1.get_smallest() << "\nLargest is: " << s1.get_largest() << "\nLast Number is: " << s1.get_lastNum() << endl;
    cout << "Length is: " << s2.get_length() << "\nSum is: " << s2.get_sum() << "\nAverage is: " << s2.get_avg() << "\nSmallest is: " << s2.get_smallest() << "\nLargest is: " << s2.get_largest() << "\nLast Number is: " << s2.get_lastNum() << endl;
    cout << "Length is: " << s3.get_length() << "\nSum is: " << s3.get_sum() << "\nAverage is: " << s3.get_avg() << "\nSmallest is: " << s3.get_smallest() << "\nLargest is: " << s3.get_largest() << "\nLast Number is: " << s3.get_lastNum() << endl;
    EXIT_SUCCESS;
}
