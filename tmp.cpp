#include<bits/stdc++.h>
using namespace std;
int arr[100000];
int ans[100000];
int main()
{
    
	arr[0]=0;arr[1]=1;arr[2]=1;
    ans[0]=0;
    ans[1] = 1;
    ans[2] = 2;
    for(int i=3;i<100000;i++)
	{
		arr[i]=arr[i-1]+arr[i-2];
        ans[i] = arr[i] + ans[i - 1];
    }
	int a;
	while(~scanf("%d",&a))
	{
        printf("%d\n", ans[a]);
    }
	return 0;
}