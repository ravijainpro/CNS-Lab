#include<bits/stdc++.h>
using namespace std;

char cipherText[100];
char table[50][50];

void fillTable() {
    for(int col=0; col<26; col++) {
        for(int row=0; row<26; row++) {
            table[col][row] = ((col + row)%26) + 'A';
        }
    }
}

void prePosses (char str[], char key[]) {
    int len     = strlen(str);
    int lenKey  = strlen(key);
    int index   = lenKey;
    for(int i=0; i<len; i++) {
        if(!(str[i] >= 65 && str[i] <= 90)) {
            str[i]-=32;
        }
    }
    for(int i=0; i<lenKey; i++) {
        if(!(key[i] >= 65 && key[i] <= 90)) {
            key[i]-=32;
        }
    }
    if (len > lenKey) {
        for(int i=lenKey; i<len; i++) {
            if (str[i]>='A' && str[i]<='Z') {
                key[index++] = key[i % lenKey];
            }
            else
            key[index++] = ' ';
        }
        key[index] = '\0';
    }
    else key[len] = '\0';
}

void Input(char str[], char key[]) {
    printf("\nEnter text: ");     
    cin >> str;
    printf("\nEnter key: ");              
    scanf("%s", key);
}

void encrypt(char str[], char key[]) {
    int in = 0;
    for(int i=0; str[i]; i++) {
        int col = key[i] - 'A';
        int row = str[i] - 'A';

        if (str[i]>='A' && str[i]<='Z') {
            cipherText[in++] = table[col][row];
        }
        else cipherText[in++] = str[i];
    }
    cipherText[in] = '\0';
}

void decrypt(char str[], char key[]) {
    int in = 0;
    for(int i=0; str[i]; i++) {
        if (str[i]>='A' && str[i]<='Z') {
            int col = key[i] - 'A';
            char ch = str[i];
            int row = 0;
            for(int i=0; i<26; i++) {
                if (table[col][i] == ch) {
                    row = i;
                    break;
                }
            }
            cipherText[in++] = table[0][row];
        }
        else cipherText[in++] = str[i];
    }
    cipherText[in] = '\0';
}

void vigenereCipher(char str[], char key[]) {
    fillTable();
    Input(str, key);
    prePosses(str, key);
    encrypt(str, key);      
    printf("\nEncrypt text: %s\n\n", cipherText);
    decrypt(cipherText, key);      
    printf("Decrypt text: %s\n", cipherText);
}

int main () {
    char str[100], key[100];
    vigenereCipher(str, key);
    return 0;
}