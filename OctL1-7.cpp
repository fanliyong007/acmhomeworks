#include<bits/stdc++.h>
using namespace std;
int test(int a,int b)
{
  double tweight=(a-100)*0.9;
  double weight=b/2;
  if(tweight-weight<tweight*0.1&&weight-tweight>tweight*0.1)
  {
    return 1;
  }
  else if(weight-tweight<tweight*10)
  {
    return 2;
  }
  else
  {
    return 3;
  }
}
int main()
{
  int time=0;
  cin>>time;
  for(int i=0;i<time;i++)
  {
    int height,weight;
    cin>>height>>weight;
    int flag=test(height,weight);
    if(flag==1)
    {
      cout<<"You are wan mei!"<<endl;
    }
    else if(flag==2)
    {
      cout<<"You are tai shou le!"<<endl;
    }
    else
    {
      cout<<"You are tai pang le!"<<endl;
    }
  }
  return 0;
}