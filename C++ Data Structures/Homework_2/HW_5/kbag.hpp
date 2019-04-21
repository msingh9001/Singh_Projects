//
//  kbag.hpp
//  HW_4
//
//  Created by Mandeep Singh on 4/10/19.
//  Copyright © 2019 Mandeep Singh. All rights reserved.
//

#ifndef kbag_hpp
#define kbag_hpp

#include <stdio.h>
#include<cstdlib>
#include <iostream>

namespace std {
    class kbag {
    public:
        // TYPEDEFS and MEMBER CONSTANTS
        typedef int value_type;
        typedef std::size_t size_type;
        static const size_type DEFAULT_CAPACITY = 20;
        kbag(size_type initial_capacity = DEFAULT_CAPACITY);
        ~kbag(){ delete [] data; };
        
        // MODIFICATION MEMBER FUNCTIONS
        void remove(int key);
        void insert(const value_type& entry, int key);
        void reserve(size_type new_capacity);
        
        // CONSTANT MEMBER FUNCTIONS
        void print() const { for(int i = 0; i < capacity; i++){ cout << data[i] << endl; } }
        size_type size() const { return used; }
        size_type cap() const{ return capacity; }
        size_type count(const value_type& target) const;
        
    private:
        value_type *data;
        size_type used;
        size_type capacity;
    };
    // NONMEMBER FUNCTIONS for the kkbag class
}
#endif /* kbag_hpp */
