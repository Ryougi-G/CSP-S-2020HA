#include<bits/stdc++.h>

using namespace std;

#define re register

const int maxn = 1e6 + 1;
const int INF = 1e8 + 7;

inline int read()
{
	re int x = 0, f = 1, ch = getchar();
	while(!isdigit(ch)){ if(ch == '-') f = -1; ch = getchar();}
	while(isdigit(ch)) x = x * 10 + ch - '0', ch = getchar();
	return x * f;
}

int n;

int a[maxn], b[maxn], c[maxn];

int main()
{
	freopen("snakes.in", "r", stdin);
	freopen("snakes.out", "w", stdout);
	int T = read();
	for(int l = 1; l <= T; l ++)
	{
		if(l == 1) {
			n = read();
			for(int i = 1; i <= n; i ++) a[i] = read();
		}
		else {
			int k = read();
			for(int i = 1; i <= k; i ++)
			{
				int x = read(); int y = read();
				b[x] = y; 
			}		
			for(int i = 1; i <= n; i ++)
			{
				a[i] = b[i];
			}
		}
		if(a[1] - a[3] > a[2]) printf("1\n");
		if(a[1] - a[3] < a[2]) printf("3\n");
	}
	return 0;
}
