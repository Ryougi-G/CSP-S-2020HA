#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;
const int MAXN = 100100;
int n, m, a[MAXN], q;
vector<int> f[MAXN];
void use(int id)
{
	if(f[id][0] == 1)
		a[f[id][1]] += f[id][2];
	else if(f[id][0] == 2)
		for(int i = 1; i <= n; ++i)
			a[i] *= f[id][1];
	else if(f[id][0] == 3)
		for(int i = 2; i <= f[id][1] + 1; ++i)
			use(f[id][i]);
	return ;
}
int main()
{
	freopen("call.in", "r", stdin);
	freopen("call.out", "w", stdout);
	scanf("%d", &n);
	for(int i = 1; i <= n; ++i)
		scanf("%d", &a[i]);
	scanf("%d", &m);
	for(int i = 1; i <= m; ++i)
	{
		int t, k;
		scanf("%d", &t);
		f[i].push_back(t);
		if(t == 1)
		{
			scanf("%d", &k);
			f[i].push_back(k);
			scanf("%d", &k);
			f[i].push_back(k);
		}
		else if(t == 2)
		{
			scanf("%d", &k);
			f[i].push_back(k);
		}
		else if(t == 3)
		{
			scanf("%d", &k);
			f[i].push_back(k);
			for(int j = 2; j <= f[i][1] + 1; ++j)
				{
					scanf("%d", &k);
					f[i].push_back(k);
				}
		}
	}
	scanf("%d", &q);
	for(int i = 1; i <= q; ++i)
	{
		int id;
		scanf("%d", &id);
		use(id);
	}
	for(int i = 1; i <= n; ++i)
		printf("%d ", a[i]);
	return 0;
}
