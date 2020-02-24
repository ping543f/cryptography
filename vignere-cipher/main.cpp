#include <iostream>
#include <stdlib.h>
#include <ctime>
#include <string>

using namespace std;

string Keygen(string key, int length)
{
    string str_key (length,'\0');
    for (int i=0;i<length;){
        for (int j=0; j<key.length();j++){
            str_key[i]=key[j];
            i++;
        }
    }
    return str_key;
}


string encrypt(string pt, string key){
    cout<<"printing key:"<<key<<endl;
    string ct = pt;
    for (int i =0; i<pt.length();i++){
        ct[i]= (((pt[i] - 'a') + (key[i] - 'a'))%26)+'a';
    }
//(pti-keyi) +26)%26 +'A'  subtract capital A
return ct;

}


string decrypt(string ct, string key){

    string pt = ct;
    //string ct = pt;
    for (int i =0; i<ct.length();i++){
        pt[i]= (((ct[i]-'a')-(key[i]-'a')+26)%26)+'a';
    }
//(pti-keyi) +26)%26 +'A'  subtract capital A
//return ct;
return pt;

}


int main()
{
    string key = "test";
    string pt = "mynameis";
    string stress_key = Keygen(key,pt.length());
    cout<<stress_key<<endl;
    cout<<pt<<endl;
    string ct= encrypt(pt,stress_key);
    cout<<ct<<endl;
    string ppt=decrypt(ct,stress_key);
    cout<<ppt<<endl;

 /*string key = Keygen();
  cout<<key<<endl;
  string pt = "We love UMP";
  string ct = encrypt(pt,key);
  cout<<pt<<endl;
  cout<<ct<<endl;
  string ppt = decrypt(ct,key);
  cout<<ppt<<endl;
*/
}
