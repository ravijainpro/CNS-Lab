#include<iostream>
using namespace std;

//function to encrypt the plain text
string encrypt(string x,int n)
    {
    string cipher="";

    for(int i=0;i<x.length();i++)
        {
        if(isupper(x[i]))
            cipher += (x[i] + n - 65)%26 + 65;
        else if(islower(x[i]))
            cipher += (x[i] + n - 97)%26 + 97;
        else
            cipher += x[i];
        }
    return cipher;
    }

//function to decrypt the cipher text using brute force attack
void decrypt(string x)
    {
    string text;
    for(int n=0;n<26;n++)
        {
        text = "";
        for(int i=0;i<x.length();i++)
            {
            if(isupper(x[i]))
                {
                if((x[i] - n - 65)<0)
                    text += 91 + (x[i] - n - 65);
                else
                    text += (x[i] - n - 65)%26 + 65;
                }
            else if(islower(x[i]))
                {
                if((x[i] - n - 97) < 0)
                    text += 123 + (x[i] - n - 97);
                else
                    text += (x[i] - n - 97)%26 + 97;
                }
            else
                text += x[i];
            }
        cout << "Plain text for key " << n << " :- " << text << endl;
        }
    }

int main()
{
int key;
string text;
cout << "Enter text:- ";
getline(cin,text);
cout << "Enter key:- ";
cin >> key;

string cipher = encrypt(text,key);
cout << "Cipher text :- " << cipher << endl << endl;

decrypt(cipher);
}

