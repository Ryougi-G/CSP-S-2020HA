#include <bits/stdc++.h>
const int maxn = 1000005;
using namespace std;
typedef unsigned long long ULL;
ULL a[maxn];
int n,m,c,k,w,p;
bool vis[70],in[70];
int main() {
	freopen("zoo.in","r",stdin);
	freopen("zoo.out","w",stdout);
	scanf("%d%d%d%d",&n,&m,&c,&k);
	for(int i = 1;i <= n;++ i) {
		scanf("%llu",&a[i]);
		for(int j = 0;j < 64;++ j) {
			if((ULL)(1 << j) & a[i]) {
				vis[j] = true;
			}
		}
//		for(int j = 0;j < 64;++ j) {
//			if((ULL)(1 << j) & a[i]) {
//				v[j].push_back(i);
//			}
//		}
	}
	for(int i = 1;i <= m;++ i) {
		scanf("%d%d",&p,&w);        
		in[p] = true;    
	}
	int cnt = 0;
	for(int i = 0;i < k;++ i) {
		if(!vis[i]&&!in[i]) {
			++ cnt;
		}
		if(vis[i]) {
			++ cnt;
		}
	}
	printf("%llu",(ULL)((1 << cnt) - n));
	return 0;
}           
