//zoj3958
// 题目的意思是两个人比拼厨艺，胜负情况分四种在表格内已经列出。
// 输入第一行为测试的次数，第二行为比拼的次数n，第三行为n次比拼的情况。
// 输出结果为Kobayashi赢，Tohru赢，或平局Draw。
// 主要思路是读取的时候就判断比赛结果，给两位选手算出成绩最后比较成绩
#include<iostream>
#include<cstdio>
using namespace std;
int main()
{
    int t=0,num=0,tmp=0;
    scanf("%d",&t);
    while (t--)
    {
    int kobayashi=0,tohru=0;
        scanf("%d",&num);
        for(int i=0;i<num;i++)
        {
            scanf("%d",&tmp);
            switch (tmp)
            {
                case 1:kobayashi+=1; break;
                case 2:tohru+=1; break;
                case 3:kobayashi+=1;tohru+=1; break;
                case 4:kobayashi-=1;tohru-=1;break;
            }
        }
        if(kobayashi!=tohru)
        {
            kobayashi>tohru?printf("Kobayashi\n"):printf("Tohru\n");
        }
        else
        {
            printf("Draw\n");
        }   
    }
    return 0;
}