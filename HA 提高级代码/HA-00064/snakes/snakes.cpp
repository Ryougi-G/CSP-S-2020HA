#include<bits/stdc++.h>
using namespace std;
long long m, n, flag = 0, len, b, u, v;
vector<long long> a;
void pd() {
	while (true) {
		if (a[a.size() - 1] - a[0] <= a[a.size() - 2]) {
			cout << a.size() << endl;
			break;
		} else {
			a[a.size() - 1] -= a[0];
			a.erase(a.begin(), a.begin() + 1);
			
		}
	}
}
int main () {
	freopen("snakes.in","r",stdin);
	freopen("snakes.out","w",stdout);
	cin >> m;
	while (m --) {
		if (!flag) {
			cin >> n;
			len = n;
			for (long long i = 1; i <= n; i ++) {
				cin >> b;
				a.push_back(b);
			}
			pd();
		} else {
			cin >> n;
			for (long long i = 1; i <= n; i ++) {
				cin >> u >> v;
				a[u - 1] = v;
			}
			pd();
		}
		flag = 1;
	}
	return 0;
}
