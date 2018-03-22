#include"stdio.h"
#include"math.h"
int main()
{
    for (int i = 1; i <= 5;i++)
    {
        if(i%2)
            printf("*");
        else
            continue;
        printf("#");
    }
    printf("#");
    scanf("%d");
    return 0;   
}