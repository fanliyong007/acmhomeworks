#include<stdio.h>
#include<cmath>
#include<iostream>
#include<iomanip>  
using namespace std;
struct humidex
{
    double t;
    double d;
    double h;
}data;
int main()
{
    char tmp,space;
    int i;
    while(true)
    {
        data.d = 200;
        data.h = 200;
        data.t = 200;
        for(i=0;i<2;i++)  
        {  
            cin>>tmp;  
            if(tmp=='E')  
                return 0;  
            else if(tmp=='T')  
                cin>>data.t;  
            else if(tmp=='D')  
                cin>>data.d;  
            else if(tmp=='H')  
                cin>>data.h;  
        }  
        if(data.h==200)  
            data.h=data.t+0.5555*(6.11*exp(5417.7530*(1/273.16-1/(data.d+273.16)))-10);  
        else if(data.t==200)  
            data.t=data.h-0.5555*(6.11*exp(5417.7530*(1/273.16-1/(data.d+273.16)))-10);  
        else if(data.d==200)  
            data.d=1/((1/273.16)-((log((((data.h-data.t)/0.5555)+10.0)/6.11))/5417.7530))-273.16;  
         cout<<setprecision(1)<<fixed<<"T "<<data.t<<" D "<<data.d<<" H "<<data.h<<endl;  
    }
    return 0;
}
//使用scanf会读取空格故使用cin，注意cin与printf不能同时用否则会出错