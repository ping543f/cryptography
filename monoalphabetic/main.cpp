#include <iostream>
#include <stdlib.h>
#include <ctime>
#include <string>

using namespace std;

string Keygen()
{
string key(26, '\0');
srand(time(0));

for (int i=0; i<26;)
    {
        char ch ='A' + rand()%26;
        bool exist = false;
        for (int j=0; j<i; j++){
            if (ch==key[j]) exist=true;
        }
        if(exist == false){
        key [i]=ch;
        i++;
        }
    }
  return key;
}


string encrypt(string pt, string key){
    string ct = pt;
    for (int i=0; i<pt.length(); i++){
        if (isalpha(pt[i])){
            int pos =-1;
            if (isupper(pt[i])){
                pos = pt[i] - 'A';
                cout<<"UPPER:"<<pos<<endl;
            }
            else{
                pos = pt[i]-'a';
                cout<<"lower:"<<pos<<endl;
            }
            ct[i]= key[pos];

        }
        else{
        ct[i]=pt[i];
        }
    }
return ct;

}


string decrypt(string ct, string key){

    string pt = ct;
    for (int i=0; i<ct.length(); i++){
        if (isalpha(ct[i])){
            int pos =-1;
            for (int j=0;j<key.length();j++){
                if (ct[i]==key[j]) pos=j;
            }
            if (pos> -1){
                    pt[i] =pos+ 'A';
            }
            }
            else {
                    pt[i]=ct[i];
            }
    }
return pt;

}


int main()
{

 string key = Keygen();
  cout<<key<<endl;
  string pt = "We love UMP";
  string ct = encrypt(pt,key);
  cout<<pt<<endl;
  cout<<ct<<endl;
  string ppt = decrypt(ct,key);
  cout<<ppt<<endl;

}
