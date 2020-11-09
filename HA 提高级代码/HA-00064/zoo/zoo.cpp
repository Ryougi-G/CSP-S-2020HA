#include<bits/stdc++.h>
using namespace std;
long long a1, a2, n, m;
long long spow(long long a, long long b) {
	if (!b) return 1;
	if (b % 2) return a*pow(a, b - 1);
	else {
		long long c = pow(a, b / 2);
		return c * c;
	}
}
int main() {
	freopen("zoo.in","r",stdin);
	freopen("zoo.out","w",stdout);
	cin >> a1 >> a2 >> n >> m;
	cout << spow(2, m) - 1;
	return 0;
}
