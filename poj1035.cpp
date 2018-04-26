#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<queue>
using namespace std;

const int INF=0x3f3f3f3f;
const int maxn=10010;
char dic[maxn][100];
int cnt;

void read_Dic(){
	cnt=0;
	while(scanf("%s",dic[cnt])){
		if(dic[cnt][0]=='#')
			break;
		cnt++;
	}
}

bool isCorrect(char *str){
	for(int i=0;i<cnt;i++){
		if(strcmp(str,dic[i])==0)
			return true;
	}
	return false;
}

void Replace(char *str,char *dic){
	int diff=0;
	int dicLen=strlen(dic);
	for(int j=0;j<dicLen;j++){
		if(str[j]!=dic[j])
			diff++;
	}
	if(diff==1)
		printf(" %s",dic);
}

void Insert(char *str,char *dic){
	int arr[100];
	int len=strlen(str);
	int dicLen=strlen(dic);
	memset(arr,-1,sizeof(arr));
	for(int j=0;j<len;j++){
		for(int k=j==0?0:arr[j-1]+1;k<dicLen;k++){
			if(str[j]==dic[k]){
				arr[j]=k;
				break;
			}
		}
	}
	bool isMatch=true;
	for(int j=0;j<len;j++){
		if(arr[j]==-1){
			isMatch=false;
			break;
		}
	}
	if(isMatch) printf(" %s",dic);
}

void Delete(char *str,char *dic){
	int arr[100];
	int len=strlen(str);
	int dicLen=strlen(dic);
	memset(arr,-1,sizeof(arr));
	for(int j=0;j<dicLen;j++){
		for(int k=j==0?0:arr[j-1]+1;k<len;k++){
			if(str[k]==dic[j]){
				arr[j]=k;
				break;
			}
		}
	}
	bool isMatch=true;
	for(int j=0;j<dicLen;j++){
		if(arr[j]==-1){
			isMatch=false;
			break;
		}
	}
	if(isMatch) printf(" %s",dic);
}

void Operate_Str(char *str){
	printf("%s:",str);
	int len=strlen(str);
	for(int i=0;i<cnt;i++){
		int dicLen=strlen(dic[i]);
		if(len==dicLen){//替换
			Replace(str,dic[i]);
		}
		else if(len+1==dicLen){//插入
			Insert(str,dic[i]);
		}
		else if(len==dicLen+1){//删除
			Delete(str,dic[i]);
		}
	}
	putchar(10);
}

int main(){
#ifndef ONLINE_JUDGE
	freopen("test.in","r",stdin);
	freopen("test.out","w",stdout);
#endif//犯规输入输出
	read_Dic();
	char str[100];
	while(scanf("%s",str)){
		if(str[0]=='#') break;
		if(isCorrect(str))
			printf("%s is correct\n",str);
		else
			Operate_Str(str);
	}
	return 0;
}

// #include<bits/stdc++.h>
// // #include<iostream>
// // #include<set>
// // #include<algorithm>
// // #include<vector>
// // #include<string>
// // #include<iterator>
// using namespace std;
// vector<string>dic;
// set<string>ans;
// vector<string>::iterator search(string tmp)
// {
//     bool flag = false;
//     vector<string>::iterator it = dic.begin();
//     for (it; it != dic.end(); it++)
//     {
//         if(*it==tmp)
//         {
//             flag = true;
//             return it;
//             break;
//         }
//     }
//     if(!flag)
//         return dic.end();
// }
// void funone(string tmp)//改变一个字符
// {
// 	int len=tmp.length();
// 	for(int i=0;i<len;i++)
// 	{
//         string x = tmp;
//         for (int j = (int)'a'; j <= (int)'z'; j++)
//         {
//             x[i] = (char)j;
//             if(search(x)!=dic.end())
//             {
//                 set<string>::iterator it = ans.find(x);
//                 if (it == ans.end())
//                     ans.insert(x);
//             }
//         }
//     }
// }
// void funtwo(string tmp)//增加一个字符
// {
//     int len = tmp.length();
//     for(int i=0;i<=len;i++)
// 	{
//         string x=tmp;
//         for (int j = (int)'a'; j <= (int)'z'; j++)
//         {
//             x=x.insert(i,1,(char)j);
//             if(search(x)!=dic.end())
//             {
//                 set<string>::iterator it = ans.find(x);
//                 if (it == ans.end())
//                     ans.insert(x);
//             }
//             x = tmp;
//         }
//     }
// }
// void funthree(string tmp)//减少一个字符
// {
//     int len = tmp.length();
//     for(int i=0;i<len;i++)
// 	{
//         string x=tmp;
//         for (string::iterator it = x.begin(); it != x.end();it++)
//         {
//             x.erase(it);
//             if(search(x)!=dic.end())
//             {
//                 set<string>::iterator it = ans.find(x);
//                 if (it == ans.end())
//                     ans.insert(x);
//             }
//             x = tmp;
//         }
//     }

// }
// int main()
// {
// 	string tmp;
// 	while(cin>>tmp)
// 	{
		
// 		while(tmp!="#")
// 		{
// 			dic.push_back(tmp);
// 			cin>>tmp;
// 		}
// 		cin>>tmp;
// 		while(tmp!="#")
// 		{
// 			if(search(tmp)!=dic.end())
// 			{
// 				cout<<tmp<<" is correct"<<endl;
//                 cin>>tmp;
// 				continue;
// 			}
// 			funone(tmp);
//             funthree(tmp);
//             funtwo(tmp);
//             if(!ans.empty())
//             {
//                 cout << tmp << ":";
//                 for (set<string>::iterator it=ans.begin(); it != ans.end();it++)
//                     cout << " " << *it;
//                 cout << endl;
//             }
//             else
//             {
//                 cout << tmp << ":" << endl;
//             }
//             cin>>tmp;
//             ans.clear();
//         }
				
// 	}
// 	return 0;
// }