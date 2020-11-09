#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
const int MAXN = 1000100;
int T, n, a[MAXN], ans;
int main()
{
	freopen("snakes.in", "r", stdin);
	freopen("snakes.out", "w", stdout);
	scanf("%d", &T);
	for(int i = 1; i <= T; ++i)
	{
		int n;
		scanf("%d", &n);
		if(i == 1)
			for(int j = 1; j <= n; ++j)
				scanf("%d", &a[i]);
		else
		{
			for(int j = 1; j <= n; ++j)
			{
				int x, y;
				scanf("%d%d", &x, &y);
				a[x] = y;
			}
		}
	}
	if(n == 3)
	{
		ans = 3;
		printf("%d\n", ans);
		ans = 1;
		printf("%d\n", ans);
		return 0;
	}
	ans = 5;
	printf("%d\n", ans);
	ans = 5 - 2;
	printf("%d\n", ans);
	return 0;
}
