#define MOD 998244353

#include <cstdio>
#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

using namespace std;

inline int read(){
	int t = 0,flag = 1;
	register char c = getchar();
	while (c < 48 || c > 57) {if (c == '-') flag = -1;c = getchar();}
	while (c >= 48 && c <= 57) t = (t << 1) + (t << 3) + (c ^ 48),c = getchar();
	return flag * t;
}

struct edge{
	int u,v,next;
}e[1000001];

int n,m,t,c,q,f[100001],etot,head[100001],a[100001],pos[100001],v[100001],g,times = 1,lazy[100001];
bool flag1,flag2;

void addedge(int u,int v){
	e[++etot].u = u,e[etot].v = v,e[etot].next = head[u],head[u] = etot;
}

void cal(int now){
	if (pos[now] == -1) times = ((long long)times * v[now]) % MOD;
	else lazy[pos[now]] = (lazy[pos[now]] + (long long)times * v[now]) % MOD;
	for (int i = head[now];i;i = e[i].next) cal(e[i].v);
}

int main(){
	freopen("call.in","r",stdin);
	freopen("call.out","w",stdout);
	n = read();
	for (int i = 1;i <= n;i++) a[i] = read();
	m = read();
	for (int i = 1;i <= m;i++){
		t = read();
		if (t == 1) pos[i] = read(),v[i] = read(),flag1 = 1;
		if (t == 2) pos[i] = -1,v[i] = read(),flag2 = 1;
		if (t == 3){  
			c = read();
			for (int j = 1;j <= c;j++) g = read(),addedge(i,g);
		}
	}
	q = read();
	for (int i = 1;i <= q;i++) f[i] = read();
	for (int i = q;i >= 1;i--) cal(f[i]);
	for (int i = 1;i <= n;i++) printf("%d ",((long long)a[i] * times % MOD + lazy[i]) % MOD);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
