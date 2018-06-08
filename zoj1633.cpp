#include <cstdio>

using namespace std;
const int maxn = 1000000;
const char* str = "T.T^__^";
typedef long long LL;
LL fibo[maxn];

int main()
{
	LL n;
	fibo[0] = 4; fibo[1] = 3;
	for(int i=2; i<maxn; i++) {
		fibo[i] = fibo[i-1] + fibo[i-2];
	}
	while(~scanf("%llu",&n)) {
		while(n>7) {
			int i = 0;
			while(i<maxn && fibo[i]<n) i++;
			n -= fibo[i-1];
		}
		printf("%c\n", str[n-1]);
	}
    return 0;
}
