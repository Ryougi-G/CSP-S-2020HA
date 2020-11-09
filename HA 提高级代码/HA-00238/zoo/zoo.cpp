#include <iostream>
#include <cstdio>
#define LL long long
using namespace std;
const int maxN = 1e6 + 10;

int n, m, c, k, ans = 0;
LL a[maxN];
LL animal;
int food[64];
int main(void){
	freopen("zoo.in", "r", stdin);
	freopen("zoo.out", "w", stdout);
	scanf("%d%d%d%d", &n, &m, &c, &k);
	for (int i = 1; i <= n; i ++){
		scanf("%lld", &a[i]);
		animal |= a[i];
	}
	for (int i = 1; i <= m; i ++){
		int p, q;
		scanf("%d%d", &p, &q);
		if (animal & (1 << p))
			food[p] = 1;
		else
			food[p] = 2;
	}
	for (int i = 0; i < (1 << k); i ++){
		bool flag = true;
		for (int j = 0; j < k; j ++){
			if (food[j] == 2 && (i & (1 << j)))
				flag = false;
		}
		if (flag)
			ans ++;
	}
	printf("%d\n", ans - n);
	return 0;
}

