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

namespace std {
    class bag {
    public:
        // TYPEDEFS and MEMBER CONSTANTS
        typedef int value_type;
        typedef std::size_t size_type;
        static const size_type CAPACITY = 30; // CONSTRUCTOR
        bag() { used = 0; }
        // MODIFICATION MEMBER FUNCTIONS
        size_type erase(const value_type& target);
        bool erase_one(const value_type& target);
        void insert(const value_type& entry);
        // CONSTANT MEMBER FUNCTIONS
        size_type size() const { return used; } size_type count(const value_type& target) const;
        friend bag operator -(const bag& b1, const bag& b2);
        friend bag operator -=(bag& b1, const bag& b2);
    private:
        value_type data[CAPACITY]; // The array to store items
        size_type used; // How much of array is used
    };
    // NONMEMBER FUNCTIONS for the bag class
    
    
}
#endif /* bag_hpp */
