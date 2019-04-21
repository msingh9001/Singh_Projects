//
//  mystring.hpp
//  HW_4
//
//  Created by Mandeep Singh on 4/18/19.
//  Copyright © 2019 Mandeep Singh. All rights reserved.
//

#ifndef mystring_hpp
#define mystring_hpp

#include <stdio.h>
#include <iostream>
namespace std{
    class str{
    public:
        str(const char str[ ] = " ");
        
        //CONSTANT MEMBER FUNCTIONS
        size_t length() const;
        char operator [ ](size_t position) const;
        
        //MODIFICATION MEMBER FUNCTIONS
        void operator +=(const str& addend);
        void operator +=(const char addend[ ]);
        void operator +=(char addend);
        void reserve(size_t n);
        
        //NONMEMBER FUNCTIONS
        friend string operator +(const str& s1, const str& s2);
        friend istream& operator >>(istream& ins, str& target);
        friend ostream& operator <<(ostream& outs, const str& source);
        istream& getline(istream& ins, str& target, char delimiter = '\n');
        friend bool operator ==(const str& s1, const str& s2);
    private:
        int current_length;
        int allocated;
        char *characters;
    };
}
#endif /* mystring_hpp */
