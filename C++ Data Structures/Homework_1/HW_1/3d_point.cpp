//
//  3d_point.cpp
//  HW_1
//
//  Created by Mandeep Singh on 4/7/19.
//  Copyright © 2019 Mandeep Singh. All rights reserved.
//

#include "3d_point.hpp"
#include <cmath>

namespace std{
    point::point(double init_x, double init_y, double init_z){
        x = init_x;
        y = init_y;
        z = init_z;
    }
    
    void point::shift(double x_amt, double y_amt, double z_amt){
        x += x_amt;
        y += y_amt;
        z += z_amt;
    }
    
    void point::rotate_x(double degrees){
        y = (y)*cos(degrees) - (z)*sin(degrees);
        z = (y)*sin(degrees) + (z)*cos(degrees);
    }
    
    void point::rotate_y(double degrees){
        x = (x)*cos(degrees) + (z)*sin(degrees);
        z = (-x)*sin(degrees) + (z)*cos(degrees);
    }
    
    void point::rotate_z(double degrees){
        x = (x)*cos(degrees) - (y)*sin(degrees);
        y = (x)*sin(degrees)+ (y)*cos(degrees);
    }
}
