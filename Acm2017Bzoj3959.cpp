//zoj3959
// 题目的意思就是出几个题目然后让你按着规则对题目的难度系数做判断，如果符合输出Yes，不符合输出No。
// 规则一：题目的数量必须在10到13之间（两者都包含）。
// 规则二：难度系数最低的题目其难度系数必须等于1。
// 规则三：至少有两道题目难度系数等于一。
// 规则四：在题目升序排列之后除了最高难度的题目，剩下的题目难度系数相邻的题目两道之间的难度系数必须不超过2.
// 第一行输入T代表有T个实例测试
// 第二行输入N表示题目的个数
// 第三行输入的是题目的难度系数依次类推
// 需要注意的是输入输出数据比较大，c++需要使用scanf和printf，Java需要使用BufferedReader类
// 思路是这样的：首先是读入测试个数然后读入题目数量，如果题目个数不够或者超出则读入一行之后直接输出No，
// 对于没有难度系数为1的题目或者难度系数为1的
// 题目少于两道则直接输出No，如果没有则继续。
// 对读入的数据由数组来存储然后对其排序，排序完成之后对每两个相邻的题目难度系数进行判断输出结果
#include<iostream>
#include<algorithm>
#include<stdio.h>
#include<cstring>
using namespace std; 
int main()
{
    int T = 0, N = 0;
    int flag=0;
    int flag2=0;
    int s[108];
    scanf("%d", &T);
    while(T--)
    {
        flag=0;
        flag2=0;
        memset(s,sizeof(s),0);
        scanf("%d",&N);
        for (int i = 0; i < N; i++)
        {
            scanf("%d",&s[i]);
            if(s[i]==1)
                flag++;
            if(s[i]<1)
                flag2=1;
        }
        if(N < 10 || N > 13)
        {
            printf("No\n");
            continue;
        }
        if(flag<2)
        {
            printf("No\n");
            continue;
        }
        sort(s,s+N);
        for (int i = 0; i < N-2; i++)
        {
            if(s[i+1]-s[i]>2)
            {
                flag2=1;
            }
        }
        if(flag2==0)
        {
            printf("Yes\n");
        }
        else
        {
            printf("No\n");
        }
        
    }    
    return 0;
}
