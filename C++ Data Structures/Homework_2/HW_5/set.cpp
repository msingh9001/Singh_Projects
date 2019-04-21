//
//  set.cpp
//  HW_2
//
//  Created by Mandeep Singh on 4/17/19.
//  Copyright © 2019 Mandeep Singh. All rights reserved.
//

#include "set.hpp"
#include <algorithm> // Provides copy function
#include <cassert> // Provides assert function
namespace std {
    
    const set::size_type set::DEFAULT_CAPACITY;
    
    set::set(size_type initial_capacity){
        used = 0;
        data = new value_type[initial_capacity];
        capacity = initial_capacity;
    }
    
    void set::reserve(size_type new_capacity){
        value_type *larger_array;
        if (new_capacity == capacity)
            return; // The allocated memory is already the right size. if (new_capacity < used)
        new_capacity = used; // Can’t allocate less than we are using.
        larger_array = new value_type[new_capacity]; copy(data, data + used, larger_array); delete [ ] data;
        data = larger_array;
        capacity = new_capacity;
    }
    
    //O(n)
    set::size_type set::erase(const value_type& target)
    {
        size_type index = 0;
        size_type many_removed = 0;
        while (index < used) {
            if (data[index] == target) {
                --used;
                data[index] = data[used];
                ++many_removed;
            }
            else
                ++index;
        }
        return many_removed;
    }
    
    //O(n)
    bool set::erase_one(const value_type& target) {
        size_type index;
        index = 0;
        while ((index < used) && (data[index] != target))
            ++index;
        if (index == used)
            return false;
        --used;
        data[index] = data[used]; return true;
    }
    
    //O(n)
    void set::insert(const value_type& entry){
        if (used == capacity)
            reserve(used+1);
        if(!contains(entry)){
            data[used] = entry;
            used++;
        }
    }
    
    //O(n)
    bool set::contains(const value_type& target) const{
        for (size_type i = 0; i < used; ++i)
            if (target == data[i]) return true;
        return false;
    }
}
