#include <bits/stdc++.h>
#define fi first
#define se second
#define pb(x) push_back(x)
using namespace std;
typedef long long i64;
typedef pair<int, int> pii;
const int N = 1e6+5;
int T, n, a[N], f[N], st[N], g[N], h[N]; 
int sol()
{
	set<pii> s; int top = 0, ret = 1;
	for(int i = 1; i <= n; ++i) g[i] = f[i] = -1, h[i] = 0;
	for(int i = 1; i <= n; ++i) s.insert(pii(a[i], i));
	while(s.size() > 1)
	{
		pii u = *--s.end(), v = *s.begin(); st[++top] = u.se;
		s.erase(--s.end()), s.erase(s.begin());
		u.fi -= v.fi; if(f[v.se] != -1) h[v.se] = u.se; 
		f[u.se] = 1, s.insert(u);
	}
	while(top)
	{
		int x = st[top--]; if(g[x] != -1) continue;
		if(!h[x]||g[h[x]] == 0) g[x] = 1;
		else g[x] = 0, ret = n-top;
	}
	return ret;
}
int main()
{
	freopen("snakes.in", "r", stdin), freopen("snakes.out", "w", stdout);
	scanf("%d%d", &T, &n); for(int i = 1; i <= n; ++i) scanf("%d", a+i);
	printf("%d\n", sol());
	for(int q = 2, k; q <= T; ++q)
	{
		scanf("%d", &k);
		for(int i = 1, x, y; i <= k; ++i) scanf("%d%d", &x, &y), a[x] = y;
		printf("%d\n", sol());	
	}
	return 0;
}
