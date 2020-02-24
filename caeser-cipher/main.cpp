#include <iostream>
#include <string>
#include<stdlib.h>
using namespace std;

void encrypt(string msg, int key){
    string output_msg = msg;

    for (int i=0;i<msg.length();i++){
    if (isalpha(msg[i])){
        if (isupper(msg[i])){
           output_msg[i]= (((msg[i]-'A') + key) % 26) + 'A';
        }
        else{
            output_msg[i]= (((msg[i]-'a') + key) % 26) + 'a';
        }

    }
}
cout<<"original message: "<<msg<<endl;
cout<<"encrypted message: "<<output_msg<<endl;
}
void decrypt(string ciphertext, int key){
    string output_msg = ciphertext;

    for (int i=0;i<ciphertext.length();i++){
    if (isalpha(ciphertext[i])){
        if (isupper(ciphertext[i])){
           output_msg[i]= (((ciphertext[i]-'A') - key + 26) % 26) + 'A';
        }
        else{
            output_msg[i]= (((ciphertext[i]-'a') - key + 26) % 26) + 'a';
        }

    }
}
cout<<"cipher message: "<<ciphertext<<endl;
cout<<"decrypted message: "<<output_msg<<endl;
}
int main()
{
    string msg = "test" ;
    string ciphertext = msg ;
    int key = 0;
    int choice = 0;
//do{
    cout << "Please enter text (plain or cipher):"<< endl;
    getline(cin,msg);
    //cin>> msg;
    cout << "Please enter Key length:"<< endl;
    cin>> key;
    cout << "Please enter your choice (1 for encrypt 2 for decrypt):"<< endl;
    cin>>choice;

    if (choice == 1){
        choice =1;
        encrypt(msg,key);
    }
    else if (choice == 2){
        choice =2;
        decrypt(msg,key);
    }
    else{
        exit(1);
    }
//}while (choice!=1 or choice!=2);

/*for (int i=0;i<str1.length();i++){
    if (isalpha(str1[i])){
        if (isupper(str1[i])){
           decs[i]= (((str1[i]-'A') - key +26) %26) + 'A';
        }
        else{
            decs[i]= (((str1[i]-'a')- key+26)%26) + 'a';
        }

    }
}


cout<<str<<endl;
cout<<str1<<endl;
cout<<decs<<endl;*/
return 0;

}
