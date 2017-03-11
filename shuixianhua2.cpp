#include <stdio.h>  
int main()  
{  
    int i,j,m,n;  
    int ge,shi,bai;  
    int a[10];  
    while( scanf("%d%d",&m,&n)!=EOF )  
    {  
    i=0;  
    for(;m<=n;m++)  
    {  
      bai = m/100;  
      shi = (m-100*bai)/10;  
      ge = m-100*bai-10*shi;  
      if( m == (bai*bai*bai + shi*shi*shi + ge*ge*ge) )  
      {  
          a[i]=m;  
          i++;  
      }  
    }  
    if(i == 0)  
        printf("no\n");  
    else  
    {  
        for(j=0;j<i;j++)  
        {  
        printf("%d",a[j]);  
        if(j<i-1)  
            printf(" ");  
        }  
        printf("\n");  
    }  
    }  
    return 0;  
}
