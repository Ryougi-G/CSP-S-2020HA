#include <bits/stdc++.h>
using namespace std;
const int maxn = 100005;
int n,m,Q,a[maxn],k[maxn],v[maxn][3],w[maxn],c[maxn];
vector<int>g[maxn];
const int mod = 998244353;                                      
void take_math(int kind,int &pos) {
	if(kind == 1) {
		scanf("%d%d",&v[pos][1],&v[pos][2]);
	}
	if(kind == 2) {
		scanf("%d",&w[pos]);
	}
	if(kind == 3) {
		scanf("%d",&c[pos]);
		for(int i = 1;i <= c[pos];++ i){
			int x;
			scanf("%d",&x);
			g[pos].push_back(x);
		}
	}
}
void do_math(int kind,int &pos) {              
	if(kind == 1) {
		a[v[pos][1]] += v[pos][2] % mod;
		a[v[pos][1]] %= mod;
	}
	if(kind == 2) {
		for(int i = 1;i <= n;++ i) {
			a[i] *= w[pos] % mod;
			a[i] %= mod;
		}
	}
	if(kind == 3) {
		for(int i = 0;i < g[pos].size();++ i) {
			do_math(k[g[pos][i]] , g[pos][i]);
		}
	}
}
int main() {
	freopen("call.in","r",stdin);
	freopen("call.out","w",stdout);
	scanf("%d",&n);
	for(int i = 1;i <= n;++ i) {
		scanf("%d",&a[i]);
	}
	scanf("%d",&m);
	for(int i = 1;i <= m;++ i) {
		scanf("%d",&k[i]);
		take_math(k[i] , i);
	}
	scanf("%d",&Q);
	while(Q --) {
		int x;
		scanf("%d",&x);
		do_math(k[x] , x);
	}
	for(int i = 1;i <= n;++ i) {
		printf("%d ",a[i]);
	}
	return 0;
}
