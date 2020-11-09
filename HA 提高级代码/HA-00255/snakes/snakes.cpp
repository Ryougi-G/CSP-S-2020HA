#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>


using namespace std;

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

const int N = 2e3 + 9;

int T, n, k, a[N], bv[N], cv[N];

int bl = 1;

int *b = bv, *c = cv; 

bool isJuedou() {
	int len = n - bl + 1;
	int boss = b[n] - b[bl];
	if ((len & 1) && boss < b[(n + bl) / 2])
		return false; 
	for (int i = 0; i + bl < n - i; i++) {
		c[n - i] = b[n - i] - b[bl + i];
		if (boss < c[n - i])
			return false;
	}
	if (len & 1)
		c[(n + bl) / 2] = b[(n + bl) / 2];
	bl += (n - bl + 1) / 2;
	sort(c + bl, c + n + 1);
	swap(b, c); 
	return true;
}

void solve() {
	for (int i = 1; i <= n; ++i) 
		bv[i] = a[i];
	
	// bl is the begin of array_b
	
	while (bl < n) {
		if (!isJuedou()) 
			break;
	}
	printf("%d\n", n - bl + 1);
}

int main() {
	freopen("snakes.in", "r", stdin);
	freopen("snakes.out", "w", stdout);
	T = read();
	n = read();
	for (int i = 1; i <= n; ++i) 
		a[i] = read();
	solve();
	for (T -= 1; T > 0; T--) {
		k = read();
		for (int i = 0, u, v; i < k; ++i) {
			u = read(), v = read();
			a[u] = v;
		}
		solve();
	}
	return 0;
}
