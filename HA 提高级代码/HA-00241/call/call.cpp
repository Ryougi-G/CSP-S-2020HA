#include <bits/stdc++.h>

using namespace std;

template<typename T>
inline void read(T&x) {
	x = 0; bool w = 1; char c = getchar();
	while(!isdigit(c)) { if(c=='-')w=0; c = getchar(); }
	while(isdigit(c)) { x = x*10+c-'0'; c = getchar(); }
	x = w ? x : -x;
}

const int N = 1e5 + 10, Mod = 998244353;
int n, m, q, val[N], opt[N], v[N], pos[N], Mul = 1;
vector<int> G[N];

inline int power(int a, int b) { int c = 1;
	for(; b; b>>=1, a = 1ll * a * a % Mod)
		if(b & 1) c = 1ll * a * c % Mod;
	return c; 
} 

inline int ni(int x) { return power(x, Mod - 2); }

inline void option(int x) {
	if(opt[x] == 1) val[pos[x]] = (val[pos[x]] + 1ll * v[x] * ni(Mul) % Mod) % Mod; 
	if(opt[x] == 2) Mul = 1ll * Mul * v[x] % Mod; 
	if(opt[x] != 3) return ;
	for(int i = 0; i < G[x].size(); i++)
		option(G[x][i]); 
}

signed main() {
	freopen("call.in","r",stdin);
	freopen("call.out","w",stdout);
	read(n);
	for(int i = 1; i <= n; i++) read(val[i]);
	read(m); int c;
	for(int i = 1; i <= m; i++) {
		read(opt[i]);
		if(opt[i] == 1) read(pos[i]), read(v[i]);
		if(opt[i] == 2) read(v[i]);
		if(opt[i] == 3) {
			read(c); int x; 
			while(c--) read(x), G[i].push_back(x); 
		}
	}
	read(q); int o; 
	while(q--) read(o), option(o); 
	for(int i = 1; i <= n; i++)
		printf("%d ", 1ll * Mul * val[i] % Mod); 
	return 0; 
}
