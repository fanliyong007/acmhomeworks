#define debug
#include<bits/stdc++.h>
using namespace std;
int main()
{ 
    int a[101][101];
    int b[101][101];
    int Ra,Ca;
    int Rb,Cb;
    scanf("%d%d",&Ra,&Ca);
    for(int i=0; i<Ra; i++)
        for(int j=0; j<Ca; j++)
            scanf("%d",&a[i][j]);
 
    scanf("%d%d",&Rb,&Cb);
    for(int i=0; i<Rb; i++)
        for(int j=0; j<Cb; j++)
            scanf("%d",&b[i][j]);
    if(Ca!=Rb)
    {
        printf("Error: %d != %d\n",Ca,Rb);
    }
    else
    {
        printf("%d %d\n",Ra,Cb);
        for(int i=0; i<Ra; i++)
        {
            for(int j=0; j<Cb; j++)
            {
                int sum=0;
                for(int k=0; k<Ca; k++)
                    sum += a[i][k]*b[k][j];
                if(j < Cb-1)
                    printf("%d ",sum);
                else
                    printf("%d\n",sum);
            }
        }
    }

    #ifdef debug
        system("Raause");
    #endif
    return 0;
}