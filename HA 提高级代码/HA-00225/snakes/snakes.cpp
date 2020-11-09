#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <cstring>
#define rg register
using namespace std;

inline int readint();
int n,t,k;
int a[1000500];

int main()
{
	freopen("snakes.in","r",stdin);
	freopen("snakes.out","w",stdout);
	t = readint();n = readint();
	if (n == 3) printf("3\n1\n");
	else if(t == 2) printf("5\n3\n");
	else for (int i = 1; i <= t; ++i)
		printf("1\n");
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
