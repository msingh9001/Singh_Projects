//
//  bag.hpp
//  HW_4
//
//  Created by Mandeep Singh on 4/10/19.
//  Copyright © 2019 Mandeep Singh. All rights reserved.
//

#ifndef bag_hpp
#define bag_hpp

#include <stdio.h>
#include<cstdlib>
#include <iostream>

namespace std {
    class bag {
    public:
        // TYPEDEFS and MEMBER CONSTANTS
        typedef int value_type;
        typedef std::size_t size_type;
        static const size_type CAPACITY = 10; // CONSTRUCTOR
        bag() { used = 0; for(int i = 0; i < CAPACITY; i++){ data[i] = -1; } }
        
        // MODIFICATION MEMBER FUNCTIONS
        void remove(int key);
        void insert(const value_type& entry, int key);
        
        // CONSTANT MEMBER FUNCTIONS
        void print() const { for(int i = 0; i < CAPACITY; i++){ cout << data[i] << endl; } }
        size_type size() const { return used; }
        size_type count(const value_type& target) const;
    private:
        value_type data[CAPACITY]; // The array to store items
        size_type used; // How much of array is used
    };
    // NONMEMBER FUNCTIONS for the bag class
}
#endif /* bag_hpp */
