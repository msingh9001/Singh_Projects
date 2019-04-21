//
//  set.hpp
//  HW_2
//
//  Created by Mandeep Singh on 4/17/19.
//  Copyright © 2019 Mandeep Singh. All rights reserved.
//

#ifndef set_hpp
#define set_hpp

#include <stdio.h>
#include<cstdlib>

namespace std {
    class set {
    public:
        // TYPEDEFS and MEMBER CONSTANTS
        typedef int value_type;
        typedef std::size_t size_type;
        static const size_type CAPACITY = 30; // CONSTRUCTOR
        set() { used = 0; }
        // MODIFICATION MEMBER FUNCTIONS
        size_type erase(const value_type& target);
        bool erase_one(const value_type& target);
        void insert(const value_type& entry);
        // CONSTANT MEMBER FUNCTIONS
        size_type size() const { return used; }
        bool contains(const value_type& target) const;
    private:
        value_type data[CAPACITY]; // The array to store items
        size_type used; // How much of array is used
    };
    // NONMEMBER FUNCTIONS for the set class
}
#endif /* set_hpp */
