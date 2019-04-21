//
//  sequence1.cpp
//  Lab_3
//
//  Created by Mandeep Singh on 4/18/19.
//  Copyright © 2019 Mandeep Singh. All rights reserved.
//

#include <stdio.h>
#include <cmath>
#include "sequence1.hpp"

namespace std{
    
    sequence::sequence(size_type initial_capacity){
        used = 0; current_index = 0;
        data = new value_type[initial_capacity];
        capacity = initial_capacity;
    }
    
    void sequence::reserve(size_type new_capacity){
        value_type *larger_array;
        if (new_capacity == capacity)
            return; // The allocated memory is already the right size. if (new_capacity < used)
        new_capacity = used; // Can’t allocate less than we are using.
        larger_array = new value_type[new_capacity]; copy(data, data + used, larger_array); delete [ ] data;
        data = larger_array;
        capacity = new_capacity;
    }
    
    void sequence::advance(){
        if(is_item()){
            if(current_index < used)
                current_index++;
        }
    }
    
    void sequence::insert(const value_type& entry){
        if (used == capacity)
            reserve(used+1);
        if(used == 0){
            data[0] = entry;
            current_index = 0;
        }else{
            //            for(size_type i = current_index + 1; i < used; i++)
            //                data[i-1] = data[i];
            for(size_type i = used + 1; i > current_index; i--)
                data[i] = data[i-1];
            
            data[current_index] = entry;
        }
        used++;
    }
    
    void sequence::attach(const value_type& entry){
        if (used == capacity)
            reserve(used+1);
        if(used == 0){
            current_index = 0;
            data[current_index] = entry;
        }else{
            for(size_type i = current_index; i < used; i++)
                data[i+1] = data[i+2];
            data[current_index+1] = entry;
            current_index += 1;
        }
        used++;
    }
    
    void sequence::remove_current(){
        if(is_item()){
            for(int i = capacity; i > current_index; i--)
                data[i- 1] = data[i];
        }
        used--;
        std::cout << "**********Length: " << this->size() << std::endl;
        
    }
    
    void sequence::insert_front(const value_type& entry){
        if (used == capacity)
            reserve(used+1);
        if(used == 0){
            data[0] = entry;
            current_index = 0;
        }else{
            for(size_type i = 0; i < used; i++)
                data[i] = data[i+1];
            data[0] = entry;
            current_index = 0;
        }
        used++;
    }
    
    void sequence::attach_back(const value_type& entry){
        if (used == capacity)
            reserve(used+1);
        if(used == 0){
            current_index = 0;
            data[current_index] = entry;
        }else{
            current_index = used;
            data[current_index] = entry;
        }
        used++;
    }
    
    void sequence::remove_front(){
        if(is_item()){
            for(int i = 1; i < size(); i++)
                data[i-1] = data[i];        //shift down
        }
        used--;
    }
    
    double sequence::getItem(int index) const{
        assert(index < size());
        double item = data[index];
        return item;
    }
    
    void sequence::operator +=(const sequence& rhs){
        assert(rhs.size() <= (capacity - this->size()));
        for(double i = this->size(); i < (this->size() + rhs.size()); i++)
            this->attach_back(getItem(i));
    }
    
    sequence::value_type sequence::operator [](int index) const{
        assert(index < size());
        return data[index];
    }
    
    double sequence::mean() const{
        return summation(*this)/size();
    }
    
    double sequence::standardDeviation() const{
        double avg = mean(), stD = 0;
        
        for(int i = 0; i < size(); ++i)
            stD += pow(data[i] - avg, 2);
        
        return sqrt(stD/size());
    }
    
    double summation(const sequence &s){
        double sum = 0;
        for(double i = 0; i < s.size(); i++){
            sum += s[i];
        }
        return sum;
    }
    
    sequence operator +(const sequence& lhs, const sequence& rhs){
        assert(lhs.size() + rhs.size() < 50);
        sequence s1;
        for(int i = 0; i < lhs.size(); i++)
            s1.attach_back(lhs.getItem(i));
        for(int i = 0; i < rhs.size(); i++)
            s1.attach_back(rhs.getItem(i));
        //        for(double j = lhs.size(); j < rhs.size(); j++)
        //            s1.attach_back(rhs.getItem(j - lhs.size()));
        return s1;
    }
    
}
