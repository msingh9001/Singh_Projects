//
//  mystring.cpp
//  HW_4
//
//  Created by Mandeep Singh on 4/18/19.
//  Copyright © 2019 Mandeep Singh. All rights reserved.
//FILE: mystring.h
//CLASS PROVIDED: string (a simple version of the Standard Library string class)
//CONSTRUCTOR for the string class:
//string(const char str[ ] = "") -- default argument is the empty string.
//Precondition: str is an ordinary null-terminated string. Postcondition: The string contains the sequence of chars from str.
//CONSTANT MEMBER FUNCTIONS for the string class:
//size_t length( ) const
//Postcondition: The return value is the number of characters in the string.
//char operator [ ](size_t position) const
//Precondition: position < length( ).
//Postcondition: The value returned is the character at the specified position of the string. A string’s positions start from 0 at the start of the sequence and go up to length( ) – 1 at the right end.
//MODIFICATION MEMBER FUNCTIONS for the string class:
//void operator +=(const string& addend)
//Postcondition: addend has been catenated to the end of the string.
//void operator +=(const char addend[ ])
//Precondition: addend is an ordinary null-terminated string. Postcondition: addend has been catenated to the end of the string.
//void operator +=(char addend)
//Postcondition: The single character addend has been catenated to the end of the string.
//void reserve(size_t n)
//Postcondition: All functions will now work efficiently (without allocating new memory) until n characters are in the string.

//NONMEMBER FUNCTIONS for the string class:
//string operator +(const string& s1, const string& s2) Postcondition: The string returned is the catenation of s1 and s2.
//istream& operator >>(istream& ins, string& target)
//Postcondition: A string has been read from the istream ins, and the istream ins is then returned by the function. The reading operation skips white space (i.e., blanks, tabs, newlines) at the start of ins. Then the string is read up to the next white space or the end of the file. The white space character that terminates the string has not been read.
//ostream& operator <<(ostream& outs, const string& source) Postcondition: The sequence of characters in source has been written to outs. The return value is the ostream outs.
//istream& getline(istream& ins, string& target, char delimiter = '\n')
//Postcondition: A string has been read from the istream ins. The reading operation reads all characters (including white space) until the delimiter is read and discarded (but not added to the end of the string). The return value is the istream ins.
//VALUE SEMANTICS for the string class:
//Assignments and the copy constructor may be used with string objects.
//COMPARISONS for the string class:
//The six comparison operators (==, !=, >=, <=, >, and <) are implemented for the string class, using the usual lexicographic order on strings.
//DYNAMIC MEMORY usage by the string class:
//If there is insufficient dynamic memory, the following functions throw bad_alloc: the constructors, reserve, operator +=, operator +, and the assignment operator.
#include "mystring.hpp"
#include <cstring>
namespace std{

    str(const char str[]) // Library facilities used: cstring
    {
        current_length = strlen(str);
        allocated = current_length + 1;
        characters = new char[allocated];
        strcpy(characters, str);
    }
    
    bool str::operator ==(const str& s1, const str& s2) // Postcondition: The return value is true if s1 is identical to s2. // Library facilities used: cstring
    {
        return (strcmp(s1.characters, s2.characters) == 0); }
}
