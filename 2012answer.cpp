#include<cstdio>  
#include<cstring>  
using namespace std;  
const int maxn=3000;        
//生成素数表  
bool flag[maxn+5];//flag[i]==true表i为素数  
int prime[maxn+5];  
int get_prime()  
    {  
        for(int i=2;i<=maxn;i++)  
        {  
            if(prime[i]==0)  
            {  	
                flag[i]=true;  
                prime[++prime[0]]=i;  
            }  
            for(int j=1;j<=prime[0] && prime[j]<=maxn/i;j++)  
            {  
                prime[prime[j]*i]=1;  
                if(i%prime[j]==0) break;  
            }  
        }  
        return prime[0];  
    }  
    int compute(int x)  
    {  
        return x*x+x+41;  
    }  
      
    //判断范围内是否都为素数  
    bool check(int a,int b)  
    {  
        for(int i=a;i<=b;i++)  
            if(!flag[compute(i)]) return false;  
        return true;  
    }  
      
    int main()  
    {  
        get_prime();  
        int a,b;  
        while(scanf("%d%d",&a,&b)==2)  
        {  
            if(a==0&&b==0) break;  
            printf("%s\n",check(a,b)?"OK":"Sorry");  
        }  
        return 0;  
    }  
