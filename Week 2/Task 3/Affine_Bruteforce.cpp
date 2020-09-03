#include <bits/stdc++.h>
#include <string>
using namespace std;

bool coprime(int a, int b) { 
      
    if ( __gcd(a, b) == 1) 
        return true;
    else
        return false;      
} 

string decryptCipher(string cipher, int a, int b)
{
    string msg = "";
    int a_inv = 0;
    int flag = 0;

    for (int i = 0; i < 26; i++)
    {
        flag = (a * i) % 26;

        if (flag == 1)
        {
            a_inv = i;
        }
    }
    for (int i = 0; i < cipher.length(); i++)
    {
        if (cipher[i] != ' ')

            msg = msg +
                  (char)(((a_inv * ((cipher[i] + 'A' - b)) % 26)) + 'A');
        else

            msg += cipher[i];
    }

    return msg;
}

int main(void)
{
    string msg = "";
    int a, b;
    cout << "Enter the plain text: ";
    getline(cin, msg);
    string cipherText; 
    cout << "Encrypted Message is : ";
   getline(cin, cipherText);
    string ans = "";
    int in = 0;
    for(int i = 0; i < 26; i ++){
        if(coprime(i, 26)){
            for(int j = 0; j < 26; j ++){
                ans = decryptCipher(cipherText, i, j);
                //cout << ans << endl;
                if(ans == msg){
                    cout << "\nKeys(a = " << i << ", b = " << j << ")\n";
                    in = 1;
                    break;
                }
            }
        }
        if(in == 1){
            break;
        }
    }
    return 0;
}
