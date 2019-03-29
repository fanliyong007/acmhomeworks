#define DEBUG
#include<bits/stdc++.h>
using namespace std;
int main()
{
    double e=0;
    printf("n e\n");
    printf("- -----------\n");
    for(int i=0;i<=9;i++)
    {
        e=0;
        double n=i;
        while(n>=0)
        {
            double tmp=1;
            int j=0;
            for(j=n;j>0;j--)
            {
                tmp*=j;
            }
            e+=1/(double)tmp;
            n--;
        }
        i<3?printf("%d %g\n",i,e):printf("%d %.9lf\n",i,e);
    }
    #ifdef DEBUG
    system("pause");
    #endif // DEBUG
    return 0;
}