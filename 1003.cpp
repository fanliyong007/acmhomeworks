#include<iostream>
#include<cstring>
#include<cstdio>
#define Max 100008
using namespace std;
int main()
{
    int count = 0;
    scanf("%d", &count);
    for (int i = 1; i <= count;i++)
    {
        int digital[Max];
        int num = 0,sum=0,max=-99999;
        int pos=1,pos1 = 0, pos2 = 0;
        memset(digital, 0, sizeof(digital));
        scanf("%d", &num);
        for (int j = 1; j <= num;j++)
        {
            scanf("%d", &digital[j]);
            sum += digital[j];
            if(sum>max)
            {
                max = sum;
                pos1 = pos;
                pos2 = j;
            }
            if(sum<0)
            {
                sum = 0;
                pos = i + 1;
            }
        }
        printf("Case %d:\n",i);
        printf("%d %d %d\n", max, pos1, pos2);
        if(i!=count)
            printf("\n");
    }
    return 0;
}