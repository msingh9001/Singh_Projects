//
//  kbag.cpp
//  HW_4
//
//  Created by Mandeep Singh on 4/10/19.
//  Copyright © 2019 Mandeep Singh. All rights reserved.
//

#include "kbag.hpp"
#include <iostream>
#include <algorithm> // Provides copy function
#include <cassert> // Provides assert function
namespace std {
    const kbag::size_type kbag::DEFAULT_CAPACITY;
    
    kbag::kbag(size_type initial_capacity){
        used = 0;
        data = new value_type[initial_capacity];
        capacity = initial_capacity;
        for(int i = 0; i < capacity; i++)
            data[i] = -1;
    }
    
    void kbag::reserve(size_type new_capacity){
        value_type *larger_array;
        if (new_capacity == capacity)
            return; // The allocated memory is already the right size. if (new_capacity < used)
        new_capacity = used; // Can’t allocate less than we are using.
        larger_array = new value_type[new_capacity]; copy(data, data + used, larger_array); delete [ ] data;
        data = larger_array;
        capacity = new_capacity;
    }
    
    void kbag::remove(int key){
        if(data[key] != -1)
            data[key] = -1;
        else
            cout << "No key exists here" << endl;
    }
    
    void kbag::insert(const value_type& entry, int key){
        if (used == capacity)
            reserve(used+1);
        if(data[key] == -1){
            data[key] = entry;
            used++;
        }else
            cout << "This key already has an item" << endl;
    }
    
    kbag::size_type kbag::count(const value_type& target) const{
        size_type answer;
        size_type i;
        answer = 0;
        for (i = 0; i < used; ++i)
            if (target == data[i]) ++answer;
        return answer;
    }
}
