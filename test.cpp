
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
struct node
{
    int num;
    char s[8];
}e[10];
int pic[9][7]={ 1,0,0,1,1,1,1,
                0,0,1,0,0,1,0,
                0,0,0,0,1,1,0,
                1,0,0,1,1,0,0,
                0,1,0,0,1,0,0,
                0,1,0,0,0,0,0,
                0,0,0,1,1,1,1,
                0,0,0,0,0,0,0,
                0,0,0,0,1,0,0};
int a[8],b[8];

int main()
{
    int t;
    int n;
    scanf("%d",&t);
    while(t--)
    {

        memset(a,0,sizeof(a));
        memset(b,0,sizeof(b));
        scanf("%d",&n);
        for(int i=0;i<n;i++)
            scanf("%d %s",&e[i].num,e[i].s);
        for(int i=0;i<7;i++)
        {

            for(int j=0;j<n;j++)
            {
                a[i]=a[i]*2+(e[j].s[i]-'0');
                b[i]=b[i]*2+pic[e[j].num-1][i];
            }

        }
       sort(a,a+7);
       sort(b,b+7);
       int ok=1;
       for(int i=0;i<7;i++)
       {
           if(a[i]!=b[i])
           {
               ok=0;
               break;
           }
       }
       if(ok) puts("YES");
       else puts("NO");

    }
}
        开始以为是判断矩阵是否可逆，，然而不会。。
        看了题解才知道想多了，把每一列看成一个整数，列变换不影响数值，只要两个状态数值相同即可。

--------------------------------------------------------------------------------
定义如下规则序列（字符串）：
1.空序列是规则序列；
2.如果S是规则序列，那(S)和[S]也是规则序列；
3.如果A和B都是规则序列，那么AB也是规则序列。
例如，下面的字符串都是规则序列：
(), [], (()), ([]), ()[], ()[()]
这几个不是规则序列：
(, [, ], )(, ([()
现在，给出一些有'(' , ')' , '[' , ']'组成的序列，请添加尽量少的括号，得到一个规则序列，并输出该序列的长度。
Input
输入一个有'(' , ')' , '[' , ']'组成的序列
Output
输出规则后的字串长度
Sample Input
([(]
Sample Output
6

//([()])
首先，我只想声明一点，这道题有毒。。。我用char读入就错了，然而换成string读入就对了或者可以把定义char的数组开的大一点，原先1A的一题硬是纠结了老半天。
传送门：zjnu
题意：
就是对于一个组成的序列，添加尽量少的括号得到一个规则序列，并且输出这个序列的长度。
不过我学到了两种定义dp状态的方法：
1）定义dp[i][j]为i~j中需要添加的最少的括号数。这里我们记录s为一段字符的开始位置，e为一段字符的结束位置。
     ①当(a[s]=='('&&a[e]==')')||(a[s]=='['&&a[e]==']')时，dp[s][e]=min(dp[s][e],dp[s+1][e-1]); 
     ②当(a[s]=='('&&a[e]!=')')||(a[s]=='['&&a[e]!=']')时，dp[s][e]=min(dp[s][e],dp[s][e-1]+1);
     ③当(a[e]==')'&&a[s]!='(')||(a[e]==']'&&a[s]!='[')时，dp[s][e]=min(dp[s][e],dp[s+1][e]+1);
     ④然后当两个数中间还有其他数存在的时候，那么我们就用for，像石子归并那样，然后去更新dp[s][e]
最后输出的时候只要输出dp[0][len-1]+len就好了。
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
	int dp[111][111];5
	for(int i=0;i<l;i++) dp[i][i]=1;
	for(int len=2;len<=l;len++){
		for(int s=0;s<=l-len;s++){
			int e=s+len-1;
			dp[s][e]=inf;//!!!
			if((a[s]=='('&&a[e]==')')||(a[s]=='['&&a[e]==']')) 
				dp[s][e]=min(dp[s][e],dp[s+1][e-1]);
			if((a[s]=='('&&a[e]!=')')||(a[s]=='['&&a[e]!=']')) 
				dp[s][e]=min(dp[s][e],dp[s][e-1]+1);
			if((a[e]==')'&&a[s]!='(')||(a[e]==']'&&a[s]!='[')) 
				dp[s][e]=min(dp[s][e],dp[s+1][e]+1);
			for(int k=s;k<e;k++){
				dp[s][e]=min(dp[s][e],dp[s][k]+dp[k+1][e]);
			}
		}
	}
	printf("%d\n",dp[0][l-1]+l);
}
2）第二种状态定义的和第一种有点不一样。 

定义dp[i][j]为i~j的区间内符合规范的字符串的最短的长度。
当然在这里我们需要进行初始化，对于不同位置的dp，我们需要进行不同的计算。（这里初始化是很重要的）
当a[s]=='('&&a[e]==')'时，那么dp[s][e]=dp[s+1][e-1]+2;
否则的话，则去寻找跳板，然后更新dp[s][e]。
其实主要的思路就是先算出小区间的每个最短的长度，然后再根据小区间然后去更新大区间的值。
最后输出的直接是dp[0][len-1]就可以了。
#include<stdio.h>
#include<string.h>
#include<iostream>z
#include<algorithm>
#include<cstring>
using namespace std;
#define maxn 111
#define inf 99999999
int main(){
	string a;
	cin>>a;
	int dp[111][111];
	int len=a.length();
	for(int i=0;i<len;i++){
		for(int j=0;j<len;j++){
			if(i==j) dp[i][j]=2;
			if(i>j) dp[i][j]=0;
			else if(i<j) dp[i][j]=inf;
		}
	}
	for(int l=2;l<=len;l++){
		for(int s=0;s<=len-l;s++){
			int e=s+l-1;
			if((a[s]=='('&&a[e]==')')||(a[s]=='['&&a[e]==']')){
				if(l>2) dp[s][e]=dp[s+1][e-1]+2;
				else dp[s][e]=2;
			}
			for(int k=s;k<e;k++){
				dp[s][e]=min(dp[s][e],dp[s][k]+dp[k+1][e]);
			}
		}
	}
	printf("%d\n",dp[0][len-1]);
}
-------------------------------------------------------------------------------------


 Edward has an array A with N integers. He defines the beauty of an array as the summation of all distinct integers in the array. Now Edward wants to know the summation of the beauty of all contiguous subarray of the array A.
Input
There are multiple test cases. The first line of input contains an integer T indicating the number of test cases. For each test case:
The first line contains an integer N (1 <= N <= 100000), which indicates the size of the array. The next line contains N positive integers separated by spaces. Every integer is no larger than 1000000.
Output
For each case, print the answer in one line.
Sample Input
3
5
1 2 3 4 5
3
2 3 3
4
2 3 3 2
Sample Output
105
21
38
题目相关:
　　3872相关链接: http://acm.zju.edu.cn/onlinejudge/showProblem.do?problemId=5520
　　Edward拥有一组数列. 其定义了Beauty数: 连续子串的和(重复的项只计算一次). 比如子串: 2, 3, 3. 则总和为beauty=2+3= 5 (数值3只计算一次).
　　目标: 求一组数列中, 所有Beauty数的总和.
思路分析:
　　• 评估数据:
　　数据规模: 数列的长度为N (1 <= N <= 100000)
　　数值范围: 成员都是正整数, 且大小不大于1000000.
　　由此可得, 子串个数为N*(N-1)/2, 而最终的总数最大范围为 N*Ｎ*M = 10^5 * 10^5 * 10^6 = 10^16, 超过4位int/long范围, 尚在8位long long的表示范围内.
　　• 思路权衡
　　采用暴力的方式去解决, 枚举每个子串, 显然不可行. 就算子串的和计算为O(1), 由于子串个数N*(N-1)/2的数据规模10^10, 显然不行.
　　关于计数/累计和的问题时, 往往可以采取动态规划的方式来简化这个问题.
    设定opt[k]表示序列以第k个元素结尾的所有子串和, val[k]为数组的第k个元素数值.
    如果不考虑重复数据不得累加的问题, 则递进公式为:
        opt[k] = opt[k - 1] + delta(k) * val[k] = opt[k - 1] + k * val[k]
    opt[k]在opt[k-1]对应的所有子串基础上, 尾部添加val[k]项组成新子串. 总共添加k次.
    
    然而由于重复数字只计算一次的限制, 该公式需要修正. 
    引入索引映射idx, 其key为数值, value表示该数值最后出现的索引位置.
    修正的核心为:  
        delta(k) = 新子串数 - 忽略次数 = k - idx[val[k]]
    注: idx[val[k]]为val[k]最后出现的索引位置,  在这之前的子串因该数值已出现过, 视为忽略.
    于是递进公式演变为:
        opt[k] = opt[k - 1]  + delta(k) * val[k] = opt[k - 1] + (k - idx[val[k]]) * val[k];

    最后结果为:
        result = opt[1] + opt[2] + ... + opt[n]
    这样总得时间复杂度为O(N).
AC代码:
#include <cstdio>
#include <map>

typedef long long LL;

int main()
{
    
    int kase;
    scanf("%d", &kase);
    while ( kase-- > 0 ) {
        int n;
        scanf("%d", &n);
    
        std::map<int, int> kbmap;
        LL opt_sum = 0, total_sum = 0;
        int val;
        for ( int i = 1; i <= n; i++ ) {
            scanf("%d", &val);
            opt_sum = opt_sum + (i - kbmap[val]) * val;
            total_sum += opt_sum;
            kbmap[val] = i;  
        } 
        
        printf("%ld\n", total_sum);
        
    }

    return 0;
}