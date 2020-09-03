#include<iostream>
using namespace std;

string encryptMessage(string msg, int a, int b)
{
    string cipher = "";
    for (int i = 0; i < msg.length(); i++)
    {
        if (msg[i] != ' ')

            cipher = cipher +
                     (char)((((a * (msg[i] - 'A')) + b) % 26) + 'A');
        else
            cipher += msg[i];
    }
    return cipher;
}


int main(){
	string txt,encry;
	cout << "Enter the String To Be Encrypted\n";	
	cin >> txt;
	cout << "\nEnter the keys=(a, b)\n";
	int key1, key2;
	cin >> key1 >> key2;
	cout << "\nEncrypted Cipher: ";
	encry = encryptMessage(txt,key1,key2);
	cout << encry << endl;

}
