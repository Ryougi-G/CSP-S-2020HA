#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
using namespace std;
const int MAXN = 1e6 + 10;
struct node {
	int p ,s;
}a[MAXN];
bool cmp (node r1 ,node r2) {
	return r1.p == r2.p ? r1.s > r2.s : r1.p > r2.p;
}
int T ,n;
int main () {
	freopen ("snakes.in","r",stdin);
	freopen ("snakes.out","w",stdout);
	scanf ("%d",&T);
	while (T --) {
		scanf ("%d",&n);
		for (int q = 1;q <= n;++ q) {
			scanf ("%d",&a[q].p);
			a[q].s = q;
		}
		sort (a + 1 ,a + n + 1 ,cmp);
		while (a[1].p > a[2].p + a[n].p || (a[1].p == a[2].p + a[n].p && a[1].s > a[2].s)) {
			a[1].p -= a[n].p;
			a[n].p = 0 ,a[n].s = 0;
			n --;
			sort (a + 1 ,a + n + 1,cmp);
		}
		if (n == 2) n --;
		printf ("%d\n",n);
	}
	return 0;
}

