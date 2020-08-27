#include <bits/stdc++.h>
using namespace std;
int shift=3;
char caesar_encoder(char x) {
    if ((x>='a' && x<='z') || (x>='A' && x<='Z')) {
        x = toupper(x);
        if(x>='a' && x<='z') {
            x-=32;
        }
        x = ((((int)x-65)+shift)%26)+65;
    }
    return (char)x;
}

char caesar_decoder(char x) {
    if (x>='A' && x<='Z') {
        x=(int)x-65-shift;
        if(x<0) {
            x*=(-1);
        }
        x = (x%26)+65;
    }
    return x;
}

int main() {
    string plain_txt;
    cout << "Enter Shift Key Followed By Plain Text: " << "\n";
    cin >> shift;
    getline(cin, plain_txt);
    string encoder_str = "";
    for (int i=0; i<plain_txt.length(); i++) {
        encoder_str += caesar_encoder(plain_txt[i]);
    }
    string decoder_str = "";
    for (int i=0; i<encoder_str.length(); i++) {
        decoder_str += caesar_decoder(encoder_str[i]);
    }
    cout << "Encoded Cipher Text: " << encoder_str << "\n";
    cout << "Decoded Text (By Knowing the right key): " << decoder_str << "\n";
    return 0;
}

 