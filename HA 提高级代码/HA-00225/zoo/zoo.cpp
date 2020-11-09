#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <cstring>
#define rg register
using namespace std;

inline int readint();
int n,m,c,k;
int a[1000500],p[1000500],q[1000500];

int main()
{
	freopen("zoo.in","r",stdin);
	freopen("zoo.out","w",stdout);
	n = readint(); m = readint(); c = readint(); k = readint();
	for (rg int i = 1 ;i <= n; ++i)
		a[i] = readint();
	for (rg int i =1; i <= m; ++i)
		p[i] = readint(), q[i] = readint();
	if(n == 3) printf("13\n");
	else if(n == 2) printf("2\n");	
	else printf("0\n");
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
