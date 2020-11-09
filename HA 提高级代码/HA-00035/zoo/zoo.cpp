#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
using namespace std;
typedef long long ll;
const int N = 1e6 + 10;
int n, m, c, k;
ll a[N], t, ans;
ll ru, ne, req, fai;
int main() {
	freopen("zoo.in", "r", stdin);
	freopen("zoo.out", "w", stdout);
	scanf("%d%d%d%d", &n, &m, &c, &k);
	t = (1<<k) - 1;
	for (int i = 1; i <= n; ++i) 
		scanf("%lld", &a[i]);
	int p, q;
	for (int i = 1; i <= m; ++i) {
		scanf("%d%d", &p, &q);
		ru |= 1<<p;
	}
	ne = a[1];
	for (int i = 2; i <= n; ++i) 
		ne |= a[i];
	req = ne & ru;
	fai = req ^ ru;
	for (int i = 0; i <= t; ++i)
		if ((i&fai) == 0) ans++;
	for (int i = 1; i <= n; ++i)
		if ((a[i]&fai) == 0) ans--;
	printf("%lld", ans);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
