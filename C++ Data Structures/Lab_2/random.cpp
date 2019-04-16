//
//  random.cpp
//  Lab_2
//
//  Created by Mandeep Singh on 4/11/19.
//  Copyright © 2019 Mandeep Singh. All rights reserved.
//

#include <stdio.h>
#include "random.h"

using namespace std;
using namespace coen79_lab2;

namespace coen79_lab2{
    rand_gen::rand_gen(int seed, int multiplier, int increment, int modulus){
        this->seed = seed;
        this->multiplier = multiplier;
        this->increment = increment;
        this->modulus = modulus;
    }
    
    void rand_gen::set_seed(int new_seed){
        seed = new_seed;
    }
    
    int rand_gen::next(){
        if(modulus!=0)
        {
            int next_seed = ((multiplier * seed) + increment) % modulus;
            set_seed(next_seed);
            return seed;
        }
        else
            return 0;
    }
    
    void rand_gen::print_info(){
        cout << "Seed: " << seed << "\nMultiplier: " << multiplier << "\nIncrement: " << increment << "\nModulus: " << modulus << endl;
    }
}
