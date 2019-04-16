//
//  statistician.cpp
//  Lab_2
//
//  Created by Mandeep Singh on 4/11/19.
//  Copyright © 2019 Mandeep Singh. All rights reserved.
//

#include <stdio.h>
#include "statistician.h"

using namespace std;
using namespace coen79_lab2;

namespace  coen79_lab2{
    
    statistician::statistician(){
        count = 0;
        total = 0;
        tiniest = 0;
        largest = 0;
    }
    
    void statistician::next(double x){
        count += 1;
        total += x;
        if(x < tiniest) { tiniest = x; }
        if(x > largest) { largest = x; }
    }
    
    void statistician::reset(){
        count = 0;
        total = 0;
        largest = 0;
        tiniest = 0;
    }
    
    statistician operator +(const statistician& s1, const statistician& s2){
        statistician s3;
        
        if(s1.length() == 0 && s2.length() == 0)
            return s3;
        else if(s1.length() == 0)
            return s2;
        else if(s2.length() == 0)
            return s1;
        else{
            double smallest = (s1.minimum() < s2.minimum()) ? s1.minimum() : s2.minimum();
            double largest = (s1.maximum() > s2.maximum()) ? s1.maximum() : s2.maximum();
            s3.total = s1.sum() + s2.sum();
            s3.count = s1.length() + s2.length();
            s3.largest = largest;
            s3.tiniest = smallest;
        }
        return s3;
    }
    
    statistician operator *(double scale, const statistician& s){
        statistician s3;
        
        s3.count = s.count;
        s3.total = s.total * scale;
        if(scale >= 0){
            s3.tiniest = s.tiniest * scale;
            s3.largest = s.largest * scale;
        }else{
            s3.tiniest = s.largest * scale;
            s3.largest = s.tiniest * scale;
        }
        
        return s3;
    }
    
    bool operator ==(const statistician& s1, const statistician& s2){
        if(s1.length() == 0 && s2.length() == 0)
            return true;
        else if(s1.length() == s2.length() && s1.sum() == s2.sum() && s1.maximum() == s2.maximum() && s1.mean() == s2.mean() && s1.minimum() == s2.minimum())
            return true;
        else
            return false;
    }
}
