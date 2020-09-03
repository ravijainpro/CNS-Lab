#include <bits/stdc++.h>
using namespace std;

int main() {
	string input, output;
	cout << "Input Plain Text: ";
	getline(cin, input);
	cout << "Input Cipher Text: ";
 	getline(cin, output);
	int m=((int)output[0]-(int)output[1])/((int)input[0]-(int)input[1]);
	if(m<0) {
		m+=26;
	}
	if(m>26) {
		m%=26;
	}
	int c=(int)output[0]-65-m*((int)input[0]-65);
	if(c<0) {
		c+=26;
	}
	if(c>26) {
		c%=26;
	}
	cout << "\nKeys=(a,b) : " << m << " " << c << "\n";
 return 0;
}
