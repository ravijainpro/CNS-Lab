#include<iostream>
#include<math.h>
#include<time.h>
using namespace std;
int main(){
    int p,a;
    cout<<"Enter A Prime Number: ";
    cin>>p;
    cout<<"Enter A Primitive Root of Mod "<<p<<" :";
    cin>>a;
    srand( (unsigned)time(NULL) );
    long long  int x,y;
    x=(rand()%(10))+5;
    y=(rand()%(10))+10;
    //cout<<x<<" "<<y<<endl;
    cout<<endl;

    cout<<"Secret Number Chosen By Alice:"<<x<<endl;
    cout<<"Secret number Chosen By Bob:"<<y<<endl;  
    cout<<endl;

    long long int k1,k2;
    k1=(pow(a,x));
    k1=k1%p;
    k2=(pow(a,y));
    k2=k2%p;
    cout<<"Key Sent By Alice to Bob: "<<k1<<endl;
    cout<<"Key Sent By Bob to Alice : "<<k2<<endl;
    cout<<endl;
    cout<<endl;
    k1=(pow(k1,y));
    k1=k1%p;
    k2=(pow(k2,x));
    k2=k2%p;
    cout<<"Key Decrypted By Bob: "<<k1<<endl;
    cout<<"Key Decrypted By Alice: "<<k2<<endl;
	return 0;
}
