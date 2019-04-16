//
//  main.cpp
//  HW_1
//
//  Created by Mandeep Singh on 4/7/19.
//  Copyright © 2019 Mandeep Singh. All rights reserved.
//

#include <iostream>
#include "3d_point.hpp"

using namespace std;

int main(int argc, const char * argv[]) {
    point mypoint;
    
    int in = 0;
    
    cout << "Please enter a number 1 - 5 to perform an operation:\n1 - Shift your point\n2 - Rotate about the x-axis\n3 - Rotate about the y-axis\n4 - Rotate aboute the z-axis\n5 - Get the coordinates of your point\nOr enter -1 to exit" << endl;
    
    while(in != -1){
        cout << "\nPlease enter a value: " << endl;
        cin >> in;
        
        if(in == -1){
            cout << "Exiting..." << endl;
        }else if(in == 1){
            int x, y, z;
            cout << "\nEnter a x value: " << endl;
            cin >> x;
            cout << "\nEnter a y value: " << endl;
            cin >> y;
            cout << "\nEnter a z value: " << endl;
            cin >> z;
            mypoint.shift(x, y, z);
            cout << "\nYour point has been shifted" << endl;
        }else if(in == 2){
            int degree;
            cout << "\nEnter the degree value: " << endl;
            cin >> degree;
            mypoint.rotate_x(degree);
            cout << "\nYour point has been rotated" << endl;
        }else if(in == 3){
            int degree;
            cout << "\nEnter the degree value: " << endl;
            cin >> degree;
            mypoint.rotate_y(degree);
            cout << "\nYour point has been rotated" << endl;
        }else if(in == 4){
            int degree;
            cout << "\nEnter the degree value: " << endl;
            cin >> degree;
            mypoint.rotate_z(degree);
            cout << "\nYour point has been rotated" << endl;
        }else if(in == 5){
            cout << "\nThe coordinates are x: " << mypoint.get_x() << " y: " << mypoint.get_y() << " z: " << mypoint.get_z() << endl;
        }else{
            cout << "\nPlease enter a valid input\n";
        }
    }
    EXIT_SUCCESS;
}
