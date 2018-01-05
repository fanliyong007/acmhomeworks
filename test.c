#include"stdio.h"
#include"time.h"
int readCard()
{
    int a;
    scanf("%d",&a);
    return a;
}
int main()
{
   
    while(1)
    {
        int flag=0;
        time_t starttime;
        time_t endtime;
        flag=readCard();
        if(flag!=0)
        {
            time(&starttime);
            while(1)
            {
                if(flag!=readCard())
                {
                    time(&endtime); 
                    break;
                }
            }
             printf("time=%.0f s",-difftime(starttime, endtime));
        }   
    }
}