#include <bits/stdc++.h>

using namespace std;

template<typename T>
inline void read(T&x) {
	x = 0; bool w = 1; char c = getchar();
	while(!isdigit(c)) { if(c=='-')w=0; c = getchar(); }
	while(isdigit(c)) { x = x*10+c-'0'; c = getchar(); }
	x = w ? x : -x;
}

const int N = 1e6+10;
int n, m, T, a[N], b[N], No;

inline bool caneat(int x, int v) {
	if(x == No) return x > v;
	if(a[x] - v > a[x-1]) return 1; 
	else return !caneat(x-1, a[x]-v);
}

inline void work(int i) {
	read(n);
	if(i == 1) { m = n; 
		for(int i = 1; i <= n; i++)
			read(b[i]), a[i] = b[i];
	}
	else {
		for(int i = 1, x, y; i <= n; i++) 
			read(x), read(y), b[x] = y;
		for(int i = 1; i <= m; i++) a[i] = b[i];
	}
	No = 0;
	for(int i = m; i; i--) {
		No++;
		if(caneat(m, a[No])) {
			a[m] -= a[No]; 
			int j = m;//
			while(j > No && a[j] < a[j-1]) 
				swap(a[j], a[j-1]);
		}
		else No--;
	}
	cout << m - No << endl; 
}

signed main() {
	freopen("snakes.in","r",stdin); 
	freopen("snakes.out","w",stdout); 
	read(T);
	for(int i = 1; i <= T; i++) 
		work(i); 
	return 0; 
}
