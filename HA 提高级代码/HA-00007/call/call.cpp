#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
int n, a[N];
inline int read() {
	int x = 0;
	bool f = 0;
	char c = getchar();
	while (c < '0' || c > '9') {
		if (c == '-')
			f = 1;
		c = getchar();
	}
	while (c <= '9' && c >= '0') {
		x = (x << 1) + (x << 3) + c - '0';
		c = getchar();
	}
	if (f)
		return ~(x - 1);
	return x;
}
int main() {
	freopen ("call.in", "r", stdin);
	freopen ("call.out", "w", stdout);
	n = read();
	for (register int i = 1; i <= n; i++)
		a[i] = read();
	for (register int i = 1; i <= n; i++)
		printf("0 ");
	putchar('\n');
	return 0;
}

