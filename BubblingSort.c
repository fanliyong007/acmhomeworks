#include<stdio.h>
void swap(int* x,int* y)
{
    int tmp = *x;
    *x = *y;
    *y = tmp;
}
int main()
{ 
    int a[10];
    for(int i=0;i<10;i++)
        scanf("%d",a+i);
    for(int j = 0; j <= 9;j++)
    {
        for (int i = j; i < 9;i++)
        {
            if(a[i]>a[i+1])
            {
                swap(a+i, a+(i+1));
            }
        }
    }
    for(int i=0;i<10;i++)
        printf("%d\n",*(a+i));
    scanf("%d",a);
    return 0;
}
