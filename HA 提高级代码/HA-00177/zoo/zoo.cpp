#include <iostream>
#include <cstdio>
using namespace std;
int vis[10024];
int need[10024];
int own[1001];
int main()
{
	freopen("zoo.in", "r", stdin);
	freopen("zoo.out", "w", stdout);
	int n, m, c, k;
	cin >> n >> m >> c >> k;
	for(int i=1; i<=n; i++)
	{
		cin >> own[i];
		vis[own[i]]=1;
	}
	int a, b;
	for(int i=1; i<=m; i++)
	{
		cin >> a >> b;
		for(int j=0; j<=(1<<k)-1; j++)
		{
			if(j&(1<<a))
			{
				need[j] |= 1<<(b-1);
			}
		}
	}
	int ans=0;
	int xx=0;
	for(int i=1; i<=n; i++)
	{
	    xx |= need[own[i]];
	} 
	for(int i=0; i<=(1<<k)-1; i++)
	{
		if(!vis[i])
		{
			if((xx | need[i])==xx)
			{
				ans++;
			}
		}
	}
	cout << ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
