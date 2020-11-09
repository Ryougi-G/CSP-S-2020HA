#include<bits/stdc++.h>
using namespace std;
const long long maxn = 10010;
const long long p = 998244353;
long long n, a[maxn], m, len = 0, aa, b, c;
struct node {
	long long u[maxn];
} f[maxn];
void debug() {
	for (long long i = 1; i <= len; i ++) {
		cout << a[i] % p << ' ';
	}
}
void ty1(long long n) {
	a[f[n].u[2]] += f[n].u[3];
}
void ty2(long long n) {
	for (long long i = 1; i <= len; i ++) {
		a[i] = (a[i] * f[n].u[2]) % p;
	}
}
void ty3(long long n) {
	for (long long i = 3; i <= f[n].u[2]; i ++) {
		if (f[f[n].u[i]].u[1] == 1) {
			ty1(f[n].u[i]);
		}
		if (f[f[n].u[i]].u[1] == 2) {
			ty2(f[n].u[i]);
		}
		if (f[f[n].u[i]].u[1] == 3) {
			ty3(f[n].u[i]);
		}
	}
	 
}
int main () {
	freopen("call.in","r",stdin);
	freopen("call.out","w",stdout);
	cin >> n;
	for (long long i = 1; i <= n; i ++) cin >> a[i], len ++;
	cin >> n;
	for (long long i = 1; i <= n; i ++) {
		cin >> f[i].u[1];
		if (f[i].u[1] == 1) {
			cin >> f[i].u[2] >> f[i].u[3];
		}
		if (f[i].u[1] == 2) {
			cin >> f[i].u[2];
		}
		if (f[i].u[1] == 3) {
			cin >> m;
			f[i].u[2] = m + 2;
			for (long long j = 3; j <= f[i].u[2]; j ++) {
				cin >> f[i].u[j];
			}
		}
	}
	cin >> m;
	while (m --) {
		cin >> n;
		if (f[n].u[1] == 1) {
			ty1(n);
		}
		if (f[n].u[1] == 2) {
			ty2(n);
		}
		if (f[n].u[1] == 3) {
			ty3(n);
		}
	}
	debug();
	return 0;
}
