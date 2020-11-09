#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
const int MAXN = 1000100;
int n, m, c, k, a[MAXN];
long long cnt;
bool vis[70];
int main()
{
	freopen("zoo.in", "r", stdin);
	freopen("zoo.out", "w", stdout);
	memset(vis, true, sizeof(vis));
	scanf("%d%d%d%d", &n, &m, &c, &k);
	for(int i = 1; i <= n; ++i)
		scanf("%d", &a[i]);
	for(int i = 1; i <= m; ++i)
	{
		int p, q;
		bool f = false;
		scanf("%d%d", &p, &q);
		for(int j = 1; j <= n; ++j)
			if(a[j] & (long long)(1 << p)) f = true;
		vis[p] = f;
	}
	if(vis[k - 1] == true) cnt = 1;
	for(int i = k - 2; i >= 0; --i)
	{
		cnt <<= 1;
		if(vis[i] == true) cnt += 1;
	}
	printf("%d\n", cnt + 1 - n);
	return 0;
}
