#include <cstdio>
#include <cstring>
int read()
{
	int ch, f = 1;
	while ((ch = getchar()) < '0' || ch > '9')
		f = (ch == '-' ? -1 : 1);
	int ret = ch - '0';
	while ((ch = getchar()) >= '0' && ch <= '9')
		ret = ret * 10 + ch - '0';
	return ret;
}

const int N = 1e6 + 10;
int a[N], del[N];
int main()
{
	freopen("snakes.in", "r", stdin);
	freopen("snakes.out", "w", stdout);
	
	int t = read(), flag = 1, n;
	while (t--)
	{
		if (flag)
		{
			n = read();
			int cnt = n;
			for (int i = 1; i <= n; i++)
				a[i] = read();
			while (cnt > 1)
			{
				int maxx = -1, minx = 1e9, lm, u, v;
				for (int i = 1; i <= n; i++)
					if (maxx <= a[i] && del[i] == 0)
					{
						lm = maxx;
						maxx = a[i];
						u = i;
					}
				for (int i = n; i >= 1; i--)
					if (minx >= a[i] && del[i] == 0)
						minx = a[i], v = i;
				if (maxx - minx <= lm)
					break;
				else
				{
					a[u] -= minx;
					del[v] = 1;
					cnt--;	
				}
			}	
			printf("%d\n", cnt);
			flag = 0;
		}
		else
		{
			int k = read(), x, y, cnt = n;
			for (int i = 1; i <= k; i++)
				x = read(), y = read(), a[x] = y;
			while (cnt > 1)
			{
				int maxx = -1, minx = 1e9, lm, u, v;
				for (int i = 1; i <= n; i++)
					if (maxx <= a[i] && del[i] == 0)
					{
						lm = maxx;
						maxx = a[i];
						u = i;
					}
				for (int i = n; i >= 1; i--)
					if (minx >= a[i] && del[i] == 0)
						minx = a[i], v = i;
				if (maxx - minx <= lm)
					break;
				else
				{
					a[u] -= minx;
					del[v] = 1;
					cnt--;	
				}
			}	
			printf("%d\n", cnt);
			flag = 0;
		}
		memset(del, 0, sizeof(del));
	}
	return 0;
}
