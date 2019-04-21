//
//  sequence1.h
//  Lab_3
//
//  Created by Mandeep Singh on 4/18/19.
//  Copyright © 2019 Mandeep Singh. All rights reserved.
//
//  Sequence Class
//
#ifndef SEQUENCE1_H
#define SEQUENCE1_H

#include <iostream>

namespace std{
    class sequence{
    public:
        // TYPEDEF and MEMBER CONSTANTS
        typedef double value_type;
        typedef std::size_t size_type;
        static const size_type DEFAULT_CAPACITY = 50;
        sequence(size_type initial_capacity = DEFAULT_CAPACITY);
        ~sequence(){ delete [] data; };
        
        // MODIFICATION MEMBER FUNCTIONS
        void start(){ current_index = 0; };
        void end(){ current_index = used - 1; };
        void last(){ current_index = capacity - 1; };
        void advance();
        void retreat(){ if(current_index != 0)   current_index--; };
        void insert(const value_type& entry);
        void attach(const value_type& entry);
        void remove_current();
        void insert_front(const value_type& entry);
        void attach_back(const value_type& entry);
        void remove_front();
        void reserve(size_type new_capacity);
        void operator +=(const sequence& rhs);
        
        // CONSTANT MEMBER FUNCTIONS
        double getItem(int index) const;
        size_type size() const { return used; } ;
        bool is_item() const{ if((current_index + 1) <= used) return true; else return false; };
        value_type current() const { return data[current_index]; };
        sequence::value_type operator[](const int index);
        double mean() const;
        size_type cap() const{ return capacity; }
        double standardDeviation() const;
        value_type operator [](int index) const;
        
    private:
        value_type *data;
        size_type capacity;
        size_type used;
        size_type current_index;
    };
    // NON-MEMBER FUNCTIONS
    double summation(const sequence &s);
    sequence operator +(const sequence& lhs, const sequence& rhs);
    
}

#endif
