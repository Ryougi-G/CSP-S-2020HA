#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <cstring>
#define rg register
#define ll long long
using namespace std;

const int P = 998244353;
int n,m,Q;
int a[100500],t[100500],p[100500],j[100500],c[100500],f[100500],g[20000][20050],v[100500];
inline int readint();
void f1(int j)
{
	a[p[j]] = (a[p[j]] + v[j]) % P;
}
void f2(int j)
{
	for (rg int i = 1; i <= n; ++i)
		a[i] = (a[i] * v[j]) % P;
}
void f3(int j)
{
	for (rg int i = 1; i <= c[j]; ++i)
	{
		if(t[g[j][i]] == 1) f1(g[j][i]);
		else if(t[g[j][i]] == 2) f2(g[j][i]);
		else if(t[g[j][i]] == 3) f3(g[j][i]);
	}
}

int main()
{
	freopen("call.in","r",stdin);
	freopen("call.out","w",stdout);
	n = readint();
	for (rg int i = 1; i <= n; ++i)
		a[i] = readint();
	m = readint();
	for (rg int i = 1; i <= m; ++i)
	{
		t[i] = readint();
		if (t[i] == 1) p[i] = readint(),v[i] = readint();
		else if (t[i] == 2) v[i] = readint();
		else if (t[i] == 3)
		{
			c[i] = readint();
			for (rg int j = 1; j <= c[i]; ++j)
				g[i][j] = readint();
		}
	}
	Q = readint();
	for (rg int i = 1; i <= Q; ++i)
	{
		f[i] = readint();
		if(t[f[i]] == 1) f1(f[i]);
		else if(t[f[i]] == 2) f2(f[i]);
		else if(t[f[i]] == 3) f3(f[i]);
	}
	for (rg int i = 1; i <= n ;++i)
		printf("%d ",a[i] % P);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
inline int readint()
{
	int x = 0, f = 1;char c = getchar();
	while (c < '0' || c > '9') {if (c == '-') f = -1; c = getchar();}
	while (c >= '0' && c <= '9') {x = x * 10 + c - '0'; c = getchar();}
	return f * x;
}
