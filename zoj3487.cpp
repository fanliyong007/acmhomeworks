#include<iostream>
using namespace std;
int main()
{
    int count;
    cin>>count;
    for(int i=0;i<count;i++)
    {
        int num;
        cin>>num;
        if(num%100/10==1)
            cout<<num<<"th"<<endl;
        else
            switch(num%10)
            {
                case 1:cout<<num<<"st"<<endl;break;
                case 2:cout<<num<<"nd"<<endl;break;
                case 3:cout<<num<<"rd"<<endl;break;
                default:cout<<num<<"th"<<endl;break;
            }
        num=0;
    }
    return 0;
}