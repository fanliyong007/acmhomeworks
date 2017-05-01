#include <stdio.h>
int main(int argc, char* argv[])
{
    int count, i;
    int x, y, num;
    scanf("%d", &count);
    for(i = 0; i < count; i++)
    {
        scanf("%d %d", &x, &y);
        if(x - y == 0 || x - y == 2)
        {
            num = ((x >> 1) << 2) + (x & 1) - (x - y);
            printf("%d\n", num);
        }
        else
            printf("No Number\n");
    }
    return 0;
}