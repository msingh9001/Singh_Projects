//
//  cryptanalyze.cpp
//  vigenere_cryptanalysis
//
//  Created by Mandeep Singh on 4/12/20.
//  Copyright © 2020 Mandeep Singh. All rights reserved.
//

#include "cryptanalyze.hpp"
#include <string>
#include <iostream>
using namespace std;
void vigenere_cryptanalyze(){
    string ciphertext;
    int key;
    char alphabet[26] = {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
    cout << "Please enter your ciphertext: " ;
    cin >> ciphertext;
    cout << "Please enter key size estimate: " ;
    cin >> key;
    cout << "Cryptanalyzing..." << endl;
    
    for(int i = 0; i < key; i++){
        int column[26] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
        int j = i;
        while(j <= ciphertext.length()){
            for(int k = 0; k < 26; k++)
                if(alphabet[k] == ciphertext[j]){
                    column[k] += 1;
                    break;
                }
            j += key;
        }
       // cout << "Column " << i << "[";
        for(int l = 0; l < 26; l++)
            cout  << column[l] << " ";
        cout << endl;
        ///< ",";
//        cout << column[25] << "]" << endl;
    }
    cout << "A B C D E F G H I J K L M N O P Q R S T U V W X Y Z" << endl;
}
