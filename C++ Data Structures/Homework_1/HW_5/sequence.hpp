//
//  sequence.hpp
//  HW_5
//
//  Created by Mandeep Singh on 4/10/19.
//  Copyright © 2019 Mandeep Singh. All rights reserved.
//

#ifndef sequence_hpp
#define sequence_hpp
#include <cstdlib>
#include <stdio.h>
namespace std{
    class sequence{
    public:
        // TYPEDEFS and MEMBER CONSTANTS
        typedef double value_type;
        typedef std::size_t size_type;
        static const size_type CAPACITY = 30; // CONSTRUCTOR
        sequence();
        // MODIFICATION MEMBER FUNCTIONS
        void start(){ current_index = 0; };
        void advance(){ if(is_item()) current_index++; };
        void insert(const value_type& entry);
        void attach(const value_type& entry);
        void remove_current();
        // CONSTANT MEMBER FUNCTIONS
        size_type size() const { return used; } ;
        bool is_item() const{ if((current_index + 1) <= used) return true; else return false; };
        value_type current() const { return data[current_index]; };
    private:
        value_type data[CAPACITY];
        size_type used;
        size_type current_index;
    };
}
#endif /* sequence_hpp */
