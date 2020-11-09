// T3
// DeP
#include <queue>
#include <cctype>
#include <cstdio>
#include <cstring>
using namespace std;

namespace IO {
	const int MAXSIZE = 1 << 18 | 1;
	char buf[MAXSIZE], *p1, *p2;

	inline int Gc() {
		return p1 == p2 &&
			(p2 = (p1 = buf) + fread(buf, 1, MAXSIZE, stdin), p1 == p2)? EOF: *p1++;
	}
	template<typename T> inline void read(T& x) {
		x = 0; int f = 0, ch = Gc();
		while (!isdigit(ch)) f |= ch == '-', ch = Gc();
		while (isdigit(ch)) x = x * 10 + ch - '0', ch = Gc();
		if (f) x = -x;
	}
}
using IO::read;

typedef long long LL;
const int MAXN = 2e5 + 5, MAXC = 1e6 + 5, P = 998244353;

int fpow(int base, int b) {
	int ret = 1;
	while (b > 0) {
		if (b & 1) ret = (LL) ret * base % P;
		base = (LL) base * base % P, b >>= 1;
	}
	return ret;
}

int n, m, q;
int A[MAXN], U[MAXN];
int opt[MAXN], pos[MAXN], val[MAXN], Idx[MAXN];

int deg[MAXN];
LL f[MAXN];

namespace Graph {
	struct Edge { int nxt, to; } edges[MAXC];
	int head[MAXN], eidx;

	inline void init() { memset(head, -1, sizeof head), eidx = 1; }
	inline void AddEdge(int from, int to) {
		edges[++eidx] = (Edge){ head[from], to }, head[from] = eidx;
	}
}

namespace Solve1 {
	// brute force
	int Add[MAXN], Mul = 1;

	void BFS(int s) {
		using namespace Graph;
		static int Q[MAXN], ht, tl;
		Q[ht = tl = 1] = s;
		while (ht <= tl) {
			int u = Q[ht++];
			if (opt[u] == 1)
				Add[u] = (Add[u] + fpow(Mul, P - 2)) % P;
			if (opt[u] == 2)
				Mul = (LL) Mul * val[u] % P;
			for (int i = head[u]; ~i; i = edges[i].nxt)
				Q[++tl] = edges[i].to;
		}
	}

	void solve() {
		for (int k = 1; k <= q; ++k) BFS(Idx[k]);
		for (int i = 1; i <= n; ++i)
			A[i] = (LL) A[i] * Mul % P;
		for (int i = 1; i <= m; ++i)
			if (Add[i] != 0) {
				int p = pos[i], v = val[i];
				A[p] = (A[p] + (LL) Add[i] * v % P * Mul % P) % P;
			}
	}
}

namespace Solve2 {
	void Topo() {
		using namespace Graph;
		static int Q[MAXN], ht, tl;
		Q[ht = 1] = tl = 0;
		for (int i = 1; i <= m; ++i)
			if (deg[i] == 0) Q[++tl] = i;
		while (ht <= tl) {
			int u = Q[ht++];
			for (int v, i = head[u]; ~i; i = edges[i].nxt) {
				f[v = edges[i].to] += f[u];
				if ((--deg[v]) == 0) Q[++tl] = v;
			}
		}
	}

	void solve() {
		for (int k = 1; k <= q; ++k) ++f[Idx[k]];
		Topo();
		int Mul = 1;
		for (int i = 1; i <= n; ++i) if (f[i] > 0) {
			const int& p = pos[i], v = val[i];
			if (opt[i] == 1)
				A[p] = (A[p] + f[i] * v % P) % P;
			if (opt[i] == 2)
				Mul = (LL) Mul * fpow(v, f[i]) % P;
		}
		for (int i = 1; i <= n; ++i)
			A[i] = (LL) A[i] * Mul % P;
	}
}

int main() {
	freopen("call.in", "r", stdin);
	freopen("call.out", "w", stdout);

	Graph::init();

	read(n);
	for (int i = 1; i <= n; ++i) read(A[i]);
	read(m);
	for (int k, i = 1; i <= m; ++i) {
		read(opt[i]);
		switch (opt[i]) {
			case 1: read(pos[i]), read(val[i]); break;
			case 2: read(val[i]); break;
			case 3:
				read(k);
				for (int j = 1; j <= k; ++j) read(U[j]);
				for (int j = k; j >= 1; --j)
					Graph::AddEdge(i, U[j]);
				break;
			default: fprintf(stderr, "ERR!");
		}
	}
	read(q);
	for (int i = 1; i <= q; ++i) read(Idx[i]);

	if (n <= 1000)
		Solve1::solve();
	else
		Solve2::solve();

	for (int i = 1; i <= n; ++i)
		printf("%d%c", A[i], " \n"[i == n]);
	return 0;
}
