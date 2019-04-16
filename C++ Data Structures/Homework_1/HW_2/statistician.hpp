//
//  statistician.hpp
//  HW_2
//
//  Created by Mandeep Singh on 4/9/19.
//  Copyright © 2019 Mandeep Singh. All rights reserved.
//

#ifndef statistician_hpp
#define statistician_hpp

#include <stdio.h>

namespace std{
    class statistician{
    private:
        double x;
        double length;
        double lastNum;
        double sum;
        double avg;
        double largest;
        double smallest;
    public:
        void next_number(const double x);
        void update_length(){ length += 1; };
        void update_lastNum(const double x){ lastNum = x; };
        void update_sum(const double x){ sum += x; };
        void update_avg(const double x){ avg = (sum/length); };
        double get_length(){ return length; }
        double get_lastNum(){ return lastNum; }
        double get_sum(){ return sum; }
        double get_avg(){ return avg; }
        double get_smallest(){ return smallest; }
        double get_largest(){ return largest; }
    };
}
#endif /* statistician_hpp */
