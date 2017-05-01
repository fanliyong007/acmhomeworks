#include<stdio.h>
#include<string.h>
#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
#define inf 99999999
#define maxn 111
int main(){
	string a;
	cin>>a;
	int l=a.length();
    printf("l=%d",l);
	int dp[111][111];
	for(int i=0;i<l;i++) dp[i][i]=1;
	for(int len=2;len<=l;len++)
    {
        printf("len=%d",len);
		for(int s=0;s<=l-len;s++)
        {
            printf("s=%d",s);
			int e=s+len-1;
            printf("e=%d",e);
			dp[s][e]=inf;//!!!
			if((a[s]=='('&&a[e]==')')||(a[s]=='['&&a[e]==']')) 
				dp[s][e]=min(dp[s][e],dp[s+1][e-1]);
			if((a[s]=='('&&a[e]!=')')||(a[s]=='['&&a[e]!=']')) 
				dp[s][e]=min(dp[s][e],dp[s][e-1]+1);
			if((a[e]==')'&&a[s]!='(')||(a[e]==']'&&a[s]!='[')) 
				dp[s][e]=min(dp[s][e],dp[s+1][e]+1);
			for(int k=s;k<e;k++){
				dp[s][e]=min(dp[s][e],dp[s][k]+dp[k+1][e]);
            printf("dp[%d][%d]=%d\n",s,e,dp[s][e]);
			}
		}
	}
	printf("%d\n",dp[0][l-1]+l);//answer `  
    for(int k=0;k<l;k++)
        for(int j=0;j<l;j++)
            printf("dp[%d][%d]=%d \n",k,j,dp[k][j]);
    cin.get();cin.get();
}