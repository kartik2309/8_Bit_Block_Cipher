//
// Created by Kartik on 06/09/17.
//

#ifndef INC_8_BIT_BLOCK_CIPHER_BLOCKS_H
#define INC_8_BIT_BLOCK_CIPHER_BLOCKS_H
#define SIZE 91

#include <iostream>
#include <string>
#include <cmath>

using namespace std;

class encryption {
protected:
    string cipher_text,plain_text;
    int temp[8],bin[8],key[8];
    typedef struct char_index{
        char _char;
        int index;
    }*pointer;
    pointer symbol_table[SIZE];
    void dec_to_bin_private(int,int[],int);
    void fill_bin_array(int);
    void fill_key_array(int);
    void text_input(char);
    void key_input(char);
    void exclusive_or(int);
    void print(int);
    void encrypt(char,char);
    void left_key_shift();
    void right_key_shift();
    int bin_to_dec();
    int look_up_symbol(char);
    char look_up_char(int);
public:
    encryption();
    string Encrypt(string,char);

};

class decryption : encryption {
    void decrypt(char,char);
public:
    string Decrypt(string,char);
};



#endif //INC_8_BIT_BLOCK_CIPHER_BLOCKS_H
