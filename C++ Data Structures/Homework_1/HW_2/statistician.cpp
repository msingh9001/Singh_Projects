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
}
