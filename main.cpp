#include "blocks.h"

using namespace std;

string encrypt();
string decrypt();

int main(){
    cout<<encrypt()<<endl;
    cout<<decrypt()<<endl;
    return 0;
}

string encrypt(){
    encryption en;
    string plaintext;
    char key;
    cout<<"Enter the PlainText:";
    cin>>plaintext;
    cout<<"Enter the Key:";
    cin>>key;
    return en.Encrypt(plaintext,key);
}

string decrypt(){
    decryption de;
    string cipher_text;
    char key;
    cout<<"Enter the Cipher Text:";
    cin>>cipher_text;
    cout<<"Enter the Key:";
    cin>>key;
    return de.Decrypt(cipher_text,key);
}