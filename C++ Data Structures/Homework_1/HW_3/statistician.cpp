//
//  statistician.cpp
//  HW_2
//
//  Created by Mandeep Singh on 4/9/19.
//  Copyright © 2019 Mandeep Singh. All rights reserved.
//

#include "statistician.hpp"

namespace std {
    
    void statistician::next_number(const double x){
        update_length();
        update_sum(x);
        update_avg(x);
        update_lastNum(x);
        if(x < smallest) { smallest = x; }
        if(x > largest) { largest = x; }
    }
    
    statistician operator +(statistician& s1, statistician& s2){
        statistician s3;
        
        if(s1.get_length() == 0 && s2.get_length() == 0)
            return s3;
        else if(s1.get_length() == 0)
            return s2;
        else if(s2.get_length() == 0)
            return s1;
        else{
            double smallest = (s1.get_smallest() < s2.get_smallest()) ? s1.get_smallest() : s2.get_smallest();
            double largest = (s1.get_largest() > s2.get_largest()) ? s1.get_largest() : s2.get_largest();
            s3.sum = s1.get_sum() + s2.get_sum();
            s3.length = s1.get_length() + s2.get_length();
            s3.avg = s3.get_sum()/s3.get_length();
            s3.largest = largest;
            s3.smallest = smallest;
            s3.lastNum = s2.lastNum;
        }
        return s3;
    }
}
