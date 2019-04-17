#define local
#include<bits/stdc++.h>
using namespace std;
const int Max=10008;//打表范围
int prime[80000];//里面依次递增的存放找到的素数，100万以内其实只有78498个素数
//下标为i的数是否是某个素数的倍数0和1默认不是素数的倍数，素数也不是素数的倍数
bool isp[Max];//false是素数，true是素数
void doprime()
{
    isp[0]=true;
    isp[1]=true;//头两个都 不是素数
    int count=0;//用来计数当前找到第几个素数了
    for(int i=2;i<Max;i++)//从2到Max一个个筛选
    {
        if(isp[i]==false)//如果i不是素数的倍数（false表示这个数是素数）
        {
            prime[count]=i;//prime存储找到第count个素数
            count++;//这是下一个素数的位置
        }
        //针对当前的i，目前已经找到了count个素数，用已经找到的count个素数去做筛选
        for(int j=0;j<count&&i*prime[j]<Max;j++)//i的prime表中第j个素数不要超过Max数组的上限
        {
            //prime[j]  j从0-->>count 所以素数的i倍都筛选
            //标记i*prime是素数的倍数。prime[j]是素数*i就是合数了
            isp[i*prime[j]]=true;
            if(i*prime[j]==0)//如果i能整除这个素数就退出
            {
                break;
            }
        }
    }
}
int primecount(int x)
{
    int sum=0;
    for(int j=2;j<x;j++)
    {
        int tmp=0;
        int i=0;
        if(isp[j]==false)
        {
            for(int i=j;i<x;i++)
            {
                if(isp[i]==false)
                {
                    tmp+=i;
                    if(tmp==x)
                    {
                        sum++;
                        break;
                    }
                }
            }
        }
    }
    return sum;
}
int main()
{
    doprime();
    int num;
    while(true)
    {
        cin>>num;
        if(num==0)
            break;
        int sum=0;
        if(isp[num]==false)
            sum++;
        int tmp=num;
        sum+=primecount(num);
        cout<<sum<<endl;
    }
    #ifdef local
    system("pause");
    #endif
    return 0;
}