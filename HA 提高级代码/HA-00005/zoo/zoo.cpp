#include <cstdio>
#include <cstring>
#include <algorithm>
#include <bitset>
using namespace std;
const int MAXK = 66;
const int MAXN = 1e6 + 10;
int n ,m ,c ,k;
long long SIT ,a[MAXN] ,ans = 0;
unsigned long long cl = 0 ,Need = 0 ,SN;
int main () {
	freopen ("zoo.in","r",stdin);
	freopen ("zoo.out","w",stdout);
	scanf ("%d%d%d%d",&n ,&m ,&c ,&k);
	SIT = (1 << k) - 1;
	for (int q = 1;q <= n;++ q) {
		scanf ("%lld",&a[q]);
		cl |= a[q];
	}
	for (int q = 1 ,x ,y;q <= m;++ q) {
		scanf ("%d%d",&x ,&y);
		Need |= (1 << x);
	}
	for (int q = 0;q <= c;++ q) {
		long long x = (1 << q);
		if ((Need & x) == x && (cl & x) == 0) {
			SN += x;
		}
	}
	for (long long q = 0;q <= SIT;++ q) {
		if ((q & SN) == 0) {
			ans ++;
		}
	}
	printf ("%d\n",ans - n);
	return 0;
}

