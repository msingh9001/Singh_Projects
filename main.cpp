//
//  main.cpp
//  vigenere
//
//  Created by Mandeep Singh on 4/12/20.
//  Copyright © 2020 Mandeep Singh. All rights reserved.
//

#include <iostream>
#include <iomanip>
#include <string>
#include "vigenere_encryption.hpp"
#include "vigenere_decryption.hpp"

using namespace std;

int main() {
    int x = 0;
    while(x != 1){
        int y;
        cout << "Choose 0 for encryption or 1 for decryption: " << endl;
        cin >> y;
        if(y == 0)
            encryption();
        if(y == 1)
            decryption();
        cout << "\nWould you like to encrypt/decrypt something else? Enter 0 for yes or 1 for no: " << endl;
        cin >> x;
    }
    return 0;
}

