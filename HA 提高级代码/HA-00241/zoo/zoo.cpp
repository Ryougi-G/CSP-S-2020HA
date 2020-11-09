#include <bits/stdc++.h>

using namespace std;

template<typename T>
inline void read(T&x) {
	x = 0; bool w = 1; char c = getchar();
	while(!isdigit(c)) { if(c=='-')w=0; c = getchar(); }
	while(isdigit(c)) { x = x*10ull+c-'0'; c = getchar(); }
	x = w ? x : -x;
}

typedef unsigned long long ull; 
const int N = 1e6+10, K = 64;
int n, m, c, k, vis[K];
ull a = 0, b, ans = 1; 

signed main() {
	freopen("zoo.in","r",stdin);
	freopen("zoo.out","w",stdout);
	read(n), read(m), read(c), read(k);
	for(int i = 1; i <= n; i++) {
		read(b); a |= b;
	}
	for(ull j = 0; j < k; j++) {
		if((a>>j)&1ull) vis[j] = 2;
	}
	for(int i = 1, p, q; i <= m; i++) {
		read(p), read(q);
		if(vis[p]) continue;
		vis[p] = 1;
	}
	for(int i = 0; i < k; i++) {
		if(vis[i] == 1) continue;
		ans <<= 1;  
	}
	cout << (ull)(ans - n) << endl; 
	return 0;
}
//3 3 5 4
//1 4 6
//0 3
//2 4
//2 5

//2 2 4 3
//1 2
//1 3
//2 4
//1 1 1 64
//9223372036854775807
//63 1
