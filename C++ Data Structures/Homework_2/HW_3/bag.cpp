//
//  bag.cpp
//  HW_4
//
//  Created by Mandeep Singh on 4/10/19.
//  Copyright © 2019 Mandeep Singh. All rights reserved.
//

#include "bag.hpp"
#include <iostream>
#include <algorithm> // Provides copy function
#include <cassert> // Provides assert function
namespace std {
    const bag::size_type bag::CAPACITY;
    
    void bag::remove(int key){
        if(data[key] != -1)
            data[key] = -1;
        else
            cout << "No key exists here" << endl;
    }
    
    void bag::insert(const value_type& entry, int key){
        assert(size() < CAPACITY);
        if(data[key] == -1){
            data[key] = entry;
            used++;
        }else
            cout << "This key already has an item" << endl;
    }
    
    bag::size_type bag::count(const value_type& target) const{
        size_type answer;
        size_type i;
        answer = 0;
        for (i = 0; i < used; ++i)
            if (target == data[i]) ++answer;
        return answer;
    }
}
