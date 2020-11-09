// T2
// DeP
#include <cctype>
#include <cstdio>
#include <algorithm>
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

typedef unsigned long long uLL;
const int MAXN = 1e6 + 5, MAXK = 1e2 + 5;

int n, m, c, K;
bool Mrk[MAXK];

int main() {
	freopen("zoo.in", "r", stdin);
	freopen("zoo.out", "w", stdout);

	read(n), read(m), read(c), read(K);
	uLL ai, Or = 0;
	for (int i = 1; i <= n; ++i)
		read(ai), Or |= ai;
	for (int p, q, i = 1; i <= m; ++i)
		read(p), read(q), Mrk[p] = true;

	int x = 0;
	for (int k = 0; k < K; ++k)
		if (((Or >> k) & 1) || !Mrk[k]) ++x;

	uLL zero = 0, one = 1;
	printf("%llu\n", max(zero, (one << x) - n));
	return 0;
}
