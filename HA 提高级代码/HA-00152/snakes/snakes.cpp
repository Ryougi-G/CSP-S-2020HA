// T4
// DeP
#include <cstdio>
using namespace std;

const int MAXN = 1e6 + 5;

int n, K;
int A[MAXN], B[MAXN];

int main() {
	freopen("snakes.in", "r", stdin);
	freopen("snakes.out", "w", stdout);

	int Ti;
	scanf("%d", &Ti);
	for (int kase = 1; kase <= Ti; ++kase) {
		if (kase == 1) {
			scanf("%d", &n);
			for (int i = 1; i <= n; ++i) scanf("%d", B + i);
		} else {
			scanf("%d", &K);
			for (int x, y; K--; )
				scanf("%d%d", &x, &y), B[x] = y;
		}
		for (int i = 1; i <= n; ++i) A[i] = B[i];
		int p = 1;
		while (p < n && A[n] - A[p] >= A[n - 1])
			A[n] -= A[p++];
		printf("%d\n", n - p + 1);
	}

	return 0;
}
