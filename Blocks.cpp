//
// Created by Kartik on 28/08/17.
//

#include "blocks.h"

void encryption::dec_to_bin_private(int num,int temp[],int code){
    int i=0;
    while (true) {
        if (num == 1) {
            temp[i] = 1,i++;
            break;
        }
        if (num % 2 != 0) {
            num = (num - 1) / 2;
            temp[i] = 1, i++;
        }
        else if (num % 2 == 0) {
            num = (num) / 2;
            temp[i] = 0, i++;
        }
    }
    while(i%8!=7)
        temp[i]=0,i++;
    code == 0 ? fill_bin_array(i) : fill_key_array(i);
}

void encryption::fill_bin_array(int i) {
    for (int j = 0; j != i + 1; j++)
        bin[j] = temp[i - j];
}

void encryption::fill_key_array(int i) {
    for (int j = 0; j != i+1 ; j++)
        key[j]=temp[i-j];
}

void encryption::text_input(char pt){
    dec_to_bin_private(look_up_symbol(pt),temp,0);
}

void encryption::key_input(char Key) {
    dec_to_bin_private(look_up_symbol(Key),temp,1);
}

void encryption::exclusive_or(int code) {
    int i=0,j=0;
    while(i!=8){
        if((bin[i]==0&&key[j]==0) || (bin[i]==1&&key[j]==1))
            bin[i]=0;
        else
            bin[i]=1;
        i++,j++;

    }
    if(code==0)
        left_key_shift();
    else
        right_key_shift();
}

void encryption::print(int code) {
    if(code==0)
        cipher_text.push_back(look_up_char(bin_to_dec()));
    else
        plain_text.push_back(look_up_char(bin_to_dec()));
}

void encryption::encrypt(char plaintext, char privatekey) {
    text_input(plaintext);
    key_input(privatekey);
    exclusive_or(0);
    print(0);
}


void encryption::left_key_shift() {
    int temp=key[0];
    for(int i=0;i!=7;i++)
        key[i]=key[i+1];
    key[7]=temp;
}

void encryption::right_key_shift() {
    int temp=key[7];
    for(int i=0;i!=7;i++)
        key[i+1]=key[i];
    key[0]=temp;
}

int encryption::bin_to_dec(){
    double num = 0;
    int return_num;
    for(int i=0;i!=8;i++)
        num=num+(bin[7-i]*pow(2,i));
    return_num=(int)num,return_num=return_num%SIZE;
    return return_num;
}

int encryption::look_up_symbol(char _char) {
    int i = 0;
    while (symbol_table[i]->_char != _char)
        i++;
    return symbol_table[i]->index;
}

char encryption::look_up_char(int index) {
    int i=0;
    while(symbol_table[i]->index != index)
        i++;
    return symbol_table[i]->_char;
}

encryption::encryption() {
    for(int i=0;i!=SIZE;i++)
        symbol_table[i]=new char_index;
    symbol_table[0]->_char='`',symbol_table[0]->index=0;
    symbol_table[1]->_char='a',symbol_table[1]->index=1;
    symbol_table[2]->_char='z',symbol_table[2]->index=2;
    symbol_table[3]->_char='b',symbol_table[3]->index=3;
    symbol_table[4]->_char='y',symbol_table[4]->index=4;
    symbol_table[5]->_char='c',symbol_table[5]->index=5;
    symbol_table[6]->_char='x',symbol_table[6]->index=6;
    symbol_table[7]->_char='d',symbol_table[7]->index=7;
    symbol_table[8]->_char='w',symbol_table[8]->index=8;
    symbol_table[9]->_char='e',symbol_table[9]->index=9;
    symbol_table[10]->_char='v',symbol_table[10]->index=10;
    symbol_table[11]->_char='f',symbol_table[12]->index=11;
    symbol_table[12]->_char='u',symbol_table[12]->index=12;
    symbol_table[13]->_char='g',symbol_table[13]->index=13;
    symbol_table[14]->_char='t',symbol_table[14]->index=14;
    symbol_table[15]->_char='h',symbol_table[15]->index=15;
    symbol_table[16]->_char='s',symbol_table[16]->index=16;
    symbol_table[17]->_char='i',symbol_table[17]->index=17;
    symbol_table[18]->_char='r',symbol_table[18]->index=18;
    symbol_table[19]->_char='j',symbol_table[19]->index=19;
    symbol_table[20]->_char='q',symbol_table[20]->index=20;
    symbol_table[21]->_char='k',symbol_table[21]->index=21;
    symbol_table[22]->_char='p',symbol_table[22]->index=22;
    symbol_table[23]->_char='l',symbol_table[23]->index=23;
    symbol_table[24]->_char='n',symbol_table[24]->index=24;
    symbol_table[25]->_char='o',symbol_table[25]->index=25;
    symbol_table[26]->_char='1',symbol_table[26]->index=26;
    symbol_table[27]->_char='6',symbol_table[27]->index=27;
    symbol_table[28]->_char='0',symbol_table[28]->index=28;
    symbol_table[29]->_char='2',symbol_table[29]->index=29;
    symbol_table[30]->_char='9',symbol_table[30]->index=30;
    symbol_table[31]->_char='3',symbol_table[31]->index=31;
    symbol_table[32]->_char='8',symbol_table[32]->index=32;
    symbol_table[33]->_char='4',symbol_table[33]->index=33;
    symbol_table[34]->_char='7',symbol_table[34]->index=34;
    symbol_table[35]->_char='5',symbol_table[35]->index=35;
    symbol_table[36]->_char='A',symbol_table[36]->index=36;
    symbol_table[37]->_char='N',symbol_table[37]->index=37;
    symbol_table[38]->_char='Z',symbol_table[38]->index=38;
    symbol_table[39]->_char='B',symbol_table[39]->index=39;
    symbol_table[40]->_char='Y',symbol_table[40]->index=40;
    symbol_table[41]->_char='C',symbol_table[41]->index=41;
    symbol_table[42]->_char='X',symbol_table[42]->index=42;
    symbol_table[43]->_char='D',symbol_table[43]->index=43;
    symbol_table[44]->_char='W',symbol_table[44]->index=44;
    symbol_table[45]->_char='E',symbol_table[45]->index=45;
    symbol_table[46]->_char='V',symbol_table[46]->index=46;
    symbol_table[47]->_char='F',symbol_table[47]->index=47;
    symbol_table[48]->_char='U',symbol_table[48]->index=48;
    symbol_table[49]->_char='G',symbol_table[49]->index=49;
    symbol_table[50]->_char='T',symbol_table[50]->index=50;
    symbol_table[51]->_char='H',symbol_table[51]->index=51;
    symbol_table[52]->_char='S',symbol_table[52]->index=52;
    symbol_table[53]->_char='I',symbol_table[53]->index=53;
    symbol_table[54]->_char='R',symbol_table[54]->index=54;
    symbol_table[55]->_char='J',symbol_table[55]->index=55;
    symbol_table[56]->_char='Q',symbol_table[56]->index=56;
    symbol_table[57]->_char='K',symbol_table[57]->index=57;
    symbol_table[58]->_char='P',symbol_table[58]->index=58;
    symbol_table[59]->_char='L',symbol_table[59]->index=59;
    symbol_table[60]->_char='O',symbol_table[60]->index=60;
    symbol_table[61]->_char='M',symbol_table[61]->index=61;
    symbol_table[62]->_char='m',symbol_table[62]->index=62;
    symbol_table[63]->_char='!',symbol_table[63]->index=63;
    symbol_table[64]->_char='-',symbol_table[64]->index=64;
    symbol_table[65]->_char='"',symbol_table[65]->index=65;
    symbol_table[66]->_char='_',symbol_table[66]->index=66;
    symbol_table[67]->_char='#',symbol_table[67]->index=67;
    symbol_table[68]->_char='^',symbol_table[68]->index=68;
    symbol_table[69]->_char='$',symbol_table[69]->index=69;
    symbol_table[70]->_char=']',symbol_table[70]->index=70;
    symbol_table[71]->_char='%',symbol_table[71]->index=71;
    symbol_table[72]->_char='&',symbol_table[72]->index=72;
    symbol_table[73]->_char='[',symbol_table[73]->index=73;
    symbol_table[74]->_char=')',symbol_table[74]->index=74;
    symbol_table[75]->_char='@',symbol_table[75]->index=75;
    symbol_table[76]->_char='(',symbol_table[76]->index=76;
    symbol_table[77]->_char='?',symbol_table[77]->index=77;
    symbol_table[78]->_char='*',symbol_table[78]->index=78;
    symbol_table[79]->_char='>',symbol_table[79]->index=79;
    symbol_table[80]->_char='+',symbol_table[80]->index=80;
    symbol_table[81]->_char='=',symbol_table[81]->index=81;
    symbol_table[82]->_char='/',symbol_table[82]->index=82;
    symbol_table[83]->_char='<',symbol_table[83]->index=83;
    symbol_table[84]->_char='.',symbol_table[84]->index=84;
    symbol_table[85]->_char=';',symbol_table[85]->index=85;
    symbol_table[86]->_char=':',symbol_table[86]->index=86;
    symbol_table[87]->_char='~',symbol_table[87]->index=87;
    symbol_table[88]->_char='{',symbol_table[88]->index=88;
    symbol_table[89]->_char='|',symbol_table[89]->index=89;
    symbol_table[90]->_char='}',symbol_table[90]->index=90;
}

string encryption::Encrypt(string PlainText, char Key) {
    for (int i = 0; i != PlainText.size(); i++)
        encrypt(PlainText[i], Key);
    return cipher_text;
}

void decryption::decrypt(char cipher_text_char, char PrivateKey) {
    text_input(cipher_text_char);
    key_input(PrivateKey);
    exclusive_or(1);
    print(1);
}

string decryption::Decrypt(string cipher_text, char Key) {
    left_key_shift();
    for (int i = 0; i != cipher_text.size(); i++)
        decrypt(cipher_text[i], Key);
    return plain_text;
}
