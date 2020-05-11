//
//  keystream_generation.hpp
//  RC4
//
//  Created by Mandeep Singh on 4/23/20.
//  Copyright © 2020 Mandeep Singh. All rights reserved.
//

#ifndef keystream_generation_hpp
#define keystream_generation_hpp
void keystream_generation(int n, int l, int* key, int* ks, int key_bits_length);
void swap(int* S, int i, int j);
void decimalToBinary(int n, int* ks, int* keystream);
int convertBitArrayToInt(int n, int* key_bits, int loc);
//void convertBitArrayToInt(int n, int* key_bits, int* key, int key_bits_length);
#endif /* keystream_generation_hpp */
