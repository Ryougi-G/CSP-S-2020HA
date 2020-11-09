#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long u64;
const int N = 1e6+5, K = 64;
int n, m, c, k, w, v[N], g[N], p[N], q[N], vis[K], f[N]; u64 a[N];
int main()
{
	freopen("zoo.in", "r", stdin), freopen("zoo.out", "w", stdout);
	scanf("%d%d%d%d", &n, &m, &c, &k);
	for(int i = 1; i <= n; ++i) 
	{
		scanf("%llu", a+i);
		for(int j = 0; j < k; ++j) if(a[i]>>j&1) vis[j] = 1;
	}
	for(int i = 1; i <= m; ++i) scanf("%d %d", p+i, q+i), v[i] = q[i];
	sort(v+1, v+m+1), c = unique(v+1, v+m+1)-v-1;
	for(int i = 0; i < k; ++i) f[i] = 1;
	for(int i = 1; i <= m; ++i)
	{
		q[i] = lower_bound(v+1, v+c+1, q[i])-v-1;
		if(vis[p[i]]) g[q[i]] = 1;
	}
	for(int i = 1; i <= m; ++i) f[p[i]] &= g[q[i]];
	for(int i = 0; i < k; ++i) w += f[i];
	if(n == 0&&w == 64) puts("18446744073709551616");
	else printf("%llu\n", (1ull<<w)-n);
 	return 0;	
}
