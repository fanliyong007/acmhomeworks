#include"stdio.h"
int main()
{
    for(int i=1;i<=5;i++)
    {
        for(int j=5-i;j>0;j--)
            printf(" ");
        for(int k=2*i-1;k>0;k--)
            printf("*");
        printf("\n");
    }
    int c;
    scanf("%d",&c);scanf("%d",&c);
    return 0;
}