#include <bits/stdc++.h>
#define fi first
#define se second
#define pb(x) push_back(x)
using namespace std;
typedef long long i64;
const int N = 1e5+5, P = 998244353;
int n, m, q, sc, a[N], T[N], p[N], v[N], vis[N], ans[N], f[N]; vector<int> e[N], s[N];
void fix(int &x) { x<P?0:x-=P; }
int main()
{
	freopen("call.in", "r", stdin), freopen("call.out", "w", stdout);
	scanf("%d", &n); for(int i = 1; i <= n; ++i) scanf("%d", a+i);
	scanf("%d", &m); for(int i = 1; i <= m; ++i)
	{
		scanf("%d", T+i);
		if(T[i] == 1) scanf("%d%d", p+i, v+i);
		else if(T[i] == 2) scanf("%d", v+i);
		else if(T[i] == 3) 
		{
			int c; scanf("%d", &c), sc += c;
			for(int i = 1, x; i <= c; ++i) scanf("%d", &x), e[i].pb(x);
		}
	}
	scanf("%d", &q);
	for(int i = 1; i <= q; ++i) scanf("%d", f+i), s[f[i]].pb(i);
	if(sc == 0)
	{
		i64 w = 1;
		for(int i = q; i; --i)
			if(T[f[i]] == 1) fix(ans[p[f[i]]] += v[f[i]]*w%P);
			else if(T[f[i]] == 2) w = w*v[f[i]];
		for(int i = 1; i <= n; ++i) fix(ans[i] += a[i]*w%P);
		for(int i = 1; i <= n; ++i) printf("%d ", a[i]); puts("");
	}
	return 0;
}
