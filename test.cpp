#include<stdio.h>
#include<iostream>
using namespace std;
int main()
{ int i,x,y,a;
float sum=0;
x=2;
y=1;
for(i=1;i<=8;i++)
{
sum+=(float)(x)/y;
// printf("%d/%d\n",x,y);
a=x;
x=x+y;
y=a;
}
printf("%7.5f\n",sum);
cin>>x;
return 0;
}
