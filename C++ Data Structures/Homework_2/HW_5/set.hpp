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
        static const size_type DEFAULT_CAPACITY = 30; // CONSTRUCTOR
        set(size_type initial_capacity = DEFAULT_CAPACITY);
        
        // MODIFICATION MEMBER FUNCTIONS
        size_type erase(const value_type& target);
        bool erase_one(const value_type& target);
        void insert(const value_type& entry);
        
        // CONSTANT MEMBER FUNCTIONS
        size_type size() const { return used; }
        bool contains(const value_type& target) const;
        void reserve(size_type new_capacity);
        size_type cap() const{ return capacity; }
        
    private:
        value_type *data; // The array to store items
        size_type capacity;
        size_type used; // How much of array is used
    };
    // NONMEMBER FUNCTIONS for the set class
}
#endif /* set_hpp */
