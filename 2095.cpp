#include<iostream>
using namespace std;
int main()
{
    int n=0;
    int a=0;
    int anwser=0;
    while(true)
    {   
        scanf("%d",&n);
        if(n==0)
            break;
       while(n--)
        {
            scanf("%d",&a);
            anwser=anwser^a;
        }
        cout<<anwser<<endl;
        anwser=0;
    }
    return 0;
}