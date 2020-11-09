#include<bits/stdc++.h>

using namespace std;

int a[10005], wei[10005], kinds[10005];

int main()
{
	freopen("zoo.in", "r", stdin);
	freopen("zoo.out", "w", stdout);
	int n, m, c, k;
	cin >> n >> m >> c >> k;
	for(int i = 1; i <= n; i++) {
		cin >> a[i];
	} 	
	for(int i = 1; i <= m; i++) {
		cin >> wei[i] >> kinds[i];
	}
	int ans = 0;
	for(int i = 0; i < (1 << k); i++) {
		int k = i;
		for(int j = 1; j <= m; j++) {
			k = k & ~(1 << wei[j]);
		}
		if(k == 0) ans++;
	}	
	cout << ans - n;
}

