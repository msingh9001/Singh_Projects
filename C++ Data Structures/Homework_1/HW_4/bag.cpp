//
//  bag.cpp
//  HW_4
//
//  Created by Mandeep Singh on 4/10/19.
//  Copyright © 2019 Mandeep Singh. All rights reserved.
//

#include "bag.hpp"
#include <algorithm> // Provides copy function #include <cassert> // Provides assert function #include "bag1.h"
namespace std {
    const bag::size_type bag::CAPACITY;
    bag::size_type bag::erase(const value_type& target)
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
    bool bag::erase_one(const value_type& target) {
        size_type index;
        index = 0;
        while ((index < used) && (data[index] != target))
            ++index;
        if (index == used)
            return false;
        --used;
        data[index] = data[used]; return true;
    }
    void bag::insert(const value_type& entry){
        assert(size( ) < CAPACITY);
        data[used] = entry;
        ++used;
    }
    bag::size_type bag::count(const value_type& target) const{
        size_type answer;
        size_type i;
        answer = 0;
        for (i = 0; i < used; ++i)
            if (target == data[i]) ++answer;
        return answer;
    }
    
    bag operator -(const bag& b1, const bag& b2){
        bag b3;
        assert(b1.size() + b2.size() <= bag::CAPACITY);
        for(int i = 0; i < b1.size(); i++){ b3.insert(b1.data[i]); }
        for(int j = 0; j < b2.size(); j++){
            int k = b2.data[j];
            b3.erase_one(k);
        }
        return b3;
    }
    
    bag operator -=(bag& b1, const bag& b2)
    {
        int j;
        
        for(int i = 0; i < b2.size(); i++)
        {
            j = b2.data[i];
            b1.erase_one(j);
        }
        return b1;
    }
}
