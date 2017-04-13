#include<queue>
#include<cstdio>
#include<algorithm>
using namespace std;
typedef long long LL;
const int maxn = 1e2 + 10;
int T, n, m;
char s[maxn][maxn];
bool check(int x, int y)
{
	if (1 <= x&&x <= n && 1 <= y + 1 && y + 1 <= m&&s[x][y + 1] == 'O') return true;
	if (1 <= x + 1 && x + 1 <= n && 1 <= y && y <= m&&s[x + 1][y] == '/') return true;
	if (1 <= x + 1 && x + 1 <= n && 1 <= y + 1 && y + 1 <= m&&s[x + 1][y + 1] == '|') return true;
	if (1 <= x + 1 && x + 1 <= n && 1 <= y + 2 && y + 2 <= m&&s[x + 1][y + 2] == '\\') return true;
	if (1 <= x + 2 && x + 2 <= n && 1 <= y  && y <= m&&s[x + 2][y] == '(') return true;
	if (1 <= x + 2 && x + 2 <= n && 1 <= y + 2 && y + 2 <= m&&s[x + 2][y + 2] == ')') return true;
	return false;
}
int main()
{
	scanf("%d", &T);
	while (T--)
	{
		scanf("%d%d", &n, &m);
		for (int i = 1; i <= n; i++) scanf("%s", s[i] + 1);
		int ans=0;
		for (int i = -1; i <= n; i++)
		{
			for (int j = -1; j <= m; j++)
			{
				if (check(i, j)) ans++;
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}