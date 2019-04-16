//
//  3d_point.hpp
//  HW_1
//
//  Created by Mandeep Singh on 4/7/19.
//  Copyright © 2019 Mandeep Singh. All rights reserved.
//

#ifndef _d_point_hpp
#define _d_point_hpp

#include <stdio.h>
namespace std{
    class point{
    public:
        point(double init_x = 0.0, double init_y = 0.0, double init_z = 0.0);
        void shift(double x_amt, double y_amt, double z_amt);
        void rotate_x(double degrees);
        void rotate_y(double degrees);
        void rotate_z(double degrees);
        double get_x() { return x; }
        double get_y() { return y; }
        double get_z() { return z; }
    private:
        double x;
        double y;
        double z;
    };
}
#endif /* _d_point_hpp */
