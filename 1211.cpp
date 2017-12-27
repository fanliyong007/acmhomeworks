#include<iostream>
using namespace std;
int p=0,q=0,e=0,l=0,n=0,fn=0,d=0;
int num[10000];
void rsa();
void decrypt();
int main()
{    
    while(cin>>p>>q>>e>>l)
    {
        for(int i=0;i<l;i++)
        {
            cin>>num[i];
        }
        rsa();
        decrypt();
    }
    return 0;
}
void rsa()
{
    n=p*q;
    fn=(p-1)*(q-1);
    for(d=0;d<)
}
void decrypt()
{

}