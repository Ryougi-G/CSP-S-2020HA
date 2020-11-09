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

int n, m, c, k;

long long a[maxn], bl[1001];

bool vis[INF];

vector<int> v[maxn];

void Dfs(int x, int num)
{
	if(x == 0) return; 
	if(x & 1) {
		for(int i = 0; i < v[num].size(); i ++)
		{
			if(vis[v[num][i]] == 1) continue;
			vis[v[num][i]] = 1;
		}
	}
	Dfs(x >>= 1, num + 1);
}

int main()
{
	freopen("zoo.in", "r", stdin);
	freopen("zoo.out", "w", stdout);
	n = read(); m = read(); c = read(); k = read();
	for(int i = 1; i <= n; i ++)
	{
		a[i] = read();
	}
	for(int i = 1; i <= m; i ++)
	{
		int x = read(); int y = read();
		v[x].push_back(y);
	}
	for(int i = 1; i <= n; i ++)
	{
		Dfs(a[i], 0);
	}
	long long ans = 0;
	for(int i = 0; i < k; i ++)
	{
		int flag = 1;
		for(int j = 0; j < v[i].size(); j ++)
		{
			if(!vis[v[i][j]]) {
				flag = 0; break;
			}
		}
		ans += flag;
	}
	bl[1] = 2;
	for(int i = 2; i < 63; i ++)
	{
		bl[i] = bl[i - 1] * 2;
	}
	printf("%lld", bl[ans] - n);
	return 0;
}
