//
//  main.cpp
//  Lab_2
//
//  Created by Mandeep Singh on 4/11/19.
//  Copyright © 2019 Mandeep Singh. All rights reserved.
//
#include "statistician.h"
#include "random.h"
#include <iostream>

using namespace std;
using namespace coen79_lab2;

void printStatisticianInfo(statistician & s) {
    cout << "Sum: " << s.sum() << endl;
    cout << "Mean: " << s.mean() << endl;
    cout << "Smallest: " << s.minimum() << endl;
    cout << "Largest: " << s.maximum() << endl;
    cout << endl;
}

void printNumbers(rand_gen &r, int num) {
    
    for (int i = 0; i < num; i++) {
        r.print_info();
        cout << "Next: " << r.next() << endl;
        cout << "\n" << endl;
    }
    cout << endl;
}

// main function
int main(int argc, const char * argv[])
{
    //statistician start
    statistician s1, s2, s3;
 
    cout << "--- s1 prints ---" << endl;
    
    s1.next(1.1);
    printStatisticianInfo(s1);
    s1.next(-2.4);
    printStatisticianInfo(s1);
    s1.next(0.8);
    printStatisticianInfo(s1);
    
    cout << "--- s2 prints ---" << endl;
    
    s2.next(5.7);
    printStatisticianInfo(s2);
    s2.next(-3.8);
    printStatisticianInfo(s2);
    s2.next(4.9);
    printStatisticianInfo(s2);
    
    s3 = s1 + s2;
    
    cout << "--- s3 print ---" << endl;
    
    printStatisticianInfo(s3);
    
    cout << "--- erase prints ---" << endl;
    
    s1.reset();
    s1.next(5);
    printStatisticianInfo(s1);
    
    s2 = s1;
    printStatisticianInfo(s1);
    
    s1.reset();
    s2.reset();
    s1.next(4);
    s2.next(4);
    if (s1 == s2)
        cout << "s1 is equal to s2" << endl;
    
    cout << endl << "--- scaling test ---" << endl;
    
    s1.reset();
    s1.next(4);
    s1.next(-2);
    printStatisticianInfo(s1);
    s1 = -1 * s1;
    printStatisticianInfo(s1);
    
    //random start
    
    rand_gen rg(1, 40, 725, 729);
    rg.print_info();
    printNumbers(rg, 5);
    
    rg.set_seed(1);
    printNumbers(rg, 5);

    rg.set_seed(15);
    printNumbers(rg, 5);


    rand_gen rg2(14, 85, 637, 1947);

    printNumbers(rg2, 5);

    rg2.set_seed(14);
    printNumbers(rg2, 5);

    EXIT_SUCCESS;
}
