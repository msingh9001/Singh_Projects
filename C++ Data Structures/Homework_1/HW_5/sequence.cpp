//
//  sequence.cpp
//  HW_5
//
//  Created by Mandeep Singh on 4/10/19.
//  Copyright © 2019 Mandeep Singh. All rights reserved.
//

#include "sequence.hpp"
#include <assert.h>

namespace std {
    
    sequence::sequence(){
        used = 0;
        current_index = 0;
        for(int i = 0; i < CAPACITY; i++)
            data[i] = -1;
    }
    
    void sequence::insert(const value_type& entry){
        assert(size() < CAPACITY);
        if(used == 0){
            data[0] = entry;
            current_index = 0;
        }else{
            for(int i = current_index; i < used; i++)
                data[i] = data[i+1];
            data[current_index] = entry;
        }
        used++;
    }
    
    void sequence::attach(const value_type& entry){
        assert(size() < CAPACITY);
        if(used == 0){
            data[0] = entry;
            current_index = 0;
        }else{
            for(int i = current_index; i < used; i++)
                data[i+1] = data[i+2];
            data[current_index+1] = entry;
            current_index += 1;
        }
        used++;
    }
    
    void sequence::remove_current(){
        if(is_item()){
            for(int i = CAPACITY; i > current_index; i--)
                data[i] = data[i-1];
        }
    }
}
