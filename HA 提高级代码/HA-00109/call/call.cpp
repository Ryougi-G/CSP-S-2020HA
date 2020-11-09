#include <bits/stdc++.h>

using namespace std;

const int MAXN = 10010;

int arr[MAXN], n, m, q, f;
struct Tf
{
	int type;
	int p;
	int v;
	int c;
	int g[10010];
};
Tf Tj[MAXN];

inline int read()
{
	int xig = 0; bool fl = 0; char ch = getchar();
	while (!isdigit(ch)) fl |= (ch == '-'), ch = getchar();
	while (isdigit(ch)) xig = (xig << 3) + (xig << 1) + (ch ^ 48), ch = getchar();
	return fl ? -xig : xig;
}

void Tcheck(int x)
{
	if (Tj[x].type == 1)
	{
		Tj[x].v = read();
		Tj[x].v = read();
	}
	else if (Tj[x].type == 2)
	{
		Tj[x].v = read();
	}
	else if (Tj[x].type == 3)
	{
		Tj[x].c = read();
		
		for (register int i = 1; i <= Tj[x].c; ++ i)
		{
			Tj[x].g[i] = read();
		}
	}
	
	return ;
}

void Tdo(int x)
{
	if (Tj[x].type == 1)
	{
		arr[ Tj[x].p + 1 ] += Tj[x].v;
	}
	else if (Tj[x].type == 2)
	{
		for (register int i = 1; i <= n; ++ i)
		{
			arr[i] *= Tj[x].v;
		}
	}
	else if (Tj[x].type == 3)
	{
		for (register int i = 1; i <= Tj[x].c; ++ i)
		{
			Tdo(Tj[x].g[i]);
		}
	}
	
	return ;
}

int main()
{
	freopen("call.in", "r", stdin);
	freopen("call.out", "w", stdout);
	
	n = read();
	for (register int i = 1; i <= n; ++ i) arr[i] = read();
	
	m = read();
	for (register int i = 1; i <= m; ++ i)
	{
		Tj[i].type = read();
		Tcheck(i);
	}
	
	q = read();
	for (register int i = 1; i <= q; ++ i)
	{
		f = read();
		Tdo(f);
	}
	
	for (register int i = 1; i <= n; ++ i) printf ("%d ", arr[i]);
	
	return 0;
}
