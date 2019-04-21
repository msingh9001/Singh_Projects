//
//  main.cpp
//  Lab_3
//
//  Created by Mandeep Singh on 4/18/19.
//  Copyright © 2019 Mandeep Singh. All rights reserved.
//

#include "sequence1.h"

// Main Function Stuff

using namespace std;
using coen79_lab3::sequence;


void printSequence1(sequence &seq) {
    seq.start();
    
    // Loop to print the sequence.
    while(seq.is_item()) {
        cout << seq.current() << " ";
        seq.advance();
    }
    cout << endl;
    
    seq.end();
}

void printstats1(sequence &seq)
{
    cout << "-----------------------------" << endl ;
    cout << "Mean: " << seq.mean() << endl;
    cout << "StdDev: " << seq.standardDeviation() << endl;
    cout << "Sum: " << coen79_lab3::summation(seq) << endl;
    cout << "Contents: " ;
    printSequence1(seq);
    cout << "Length: " << seq.size() << endl;
    cout << "-----------------------------" << endl ;
}

int main(int argc, const char * argv[])
{
    sequence tester1;
    tester1.insert(1);
    tester1.insert(2);
    tester1.insert(3);
    printstats1(tester1);
    sequence tester2;
    tester2.insert(2);
    tester2.insert(3);
    tester2.insert(4);
    printstats1(tester2);
    sequence tester3;
    tester3 = tester1 + tester2;
    cout << "tester 3 : "<< endl;
    printstats1(tester3);
    cout << "tester 3 functions : "<< endl;
    tester3.advance();
    printstats1(tester3);
     cout << "tester 3 advance : "<< endl;
    tester3.advance();
    printstats1(tester3);
    cout << "tester 3 remove_front : "<< endl;
    tester3.remove_front();
    printstats1(tester3);
    tester3.advance();
    printstats1(tester3);
    tester3.remove_front();
    printstats1(tester3);
    tester3.advance();
    printstats1(tester3);
    tester3.remove_current();
    printstats1(tester3);
    tester3.attach_back(14);
    printstats1(tester3);
}

