#include <cstdio>
#include <vector>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

const int MOD = 998244353;

int read() {
	int x = 0, s = 1;
	char ch = getchar();
	for (; !isdigit(ch); ch = getchar()) 
		if (ch =='-')
			s = -1;
	for (; isdigit(ch); ch = getchar())
		x = x * 10 + (ch ^ 48);
	return x * s;
}

const int N = 1e5 + 9;

int n, m, q, T[N], P[N], V[N];
vector<int> G[N];
long long a[N];

void dfs(int u) {
	if (T[u] == 1) {
		a[P[u]] = (a[P[u]] + V[u]) % MOD; 
	} else if (T[u] == 2) {
		for (int i = 1; i <= n; ++i)
			a[i] = a[i] * V[u] % MOD;
	} else {
		for (int i = 0; i < G[u].size(); ++i) 
			dfs(G[u][i]);
	}
}

int main() {
	freopen("call.in", "r", stdin);
	freopen("call.out", "w", stdout);
	n = read();
	for (int i = 1; i <= n; ++i)
		a[i] = read();
	m = read();
	for (int i = 1; i <= m; ++i) {
		T[i] = read();
		if (T[i] == 1) {
			P[i] = read();
			V[i] = read();
		} else if (T[i] == 2) {
			V[i] = read();
		} else {
			P[i] = read();
			for (int j = 0, v; j < P[i]; ++j) {
				v = read();
				G[i].push_back(v);
			}
		}
	}
	q = read();
	while (q--) {
		int f = read();
		dfs(f);
	}
	for (int i = 1; i <= n; ++i)
		printf("%lld ", a[i] % MOD);
	return 0;
}
