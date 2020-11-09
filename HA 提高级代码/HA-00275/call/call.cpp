#include<iostream>
#include<cstdio>
using namespace std;
int n,m,q,g[1001][1001],t[1001],c;
long long int a[1001];
int p[1001],v[1001];
const int Mod=998244353;
void t1(int x)
{
	a[p[x]]=(a[p[x]]+v[x])%Mod;
}
void t2(int x)
{
	for(int i=1;i<=n;i++)
	{
		a[i]=(a[i]*v[x])%Mod;
	}
}
void t3(int x)
{
	for(int i=1;i<=g[x][0];i++)
	{
		if(t[g[x][i]]==1)
		{
			t1(g[x][i]);
		}else if(t[g[x][i]]==2)
		{
			t2(g[x][i]);
		}else
		{
			t3(g[x][i]);
		}
	}
}
int main()
{
	freopen("call.in","r",stdin);
	freopen("call.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%lld",&a[i]);
	}
	scanf("%d",&m);
	for(int i=1;i<=m;i++)
	{
		scanf("%d",&t[i]);
		if(t[i]==1)
		{
			scanf("%d%d",&p[i],&v[i]);
		}else if(t[i]==2)
		{
			scanf("%d",&v[i]);
		}else
		{
			scanf("%d",&c);
			for(int j=1;j<=c;j++)
			{
				scanf("%d",&g[i][j]);
			}
			g[i][0]=c;
		}
	}
	scanf("%d",&q);
	for(int i=1;i<=q;i++)
	{
		scanf("%d",&c);
		if(t[c]==1)
		{
			t1(c);
		}else if(t[c]==2)
		{
			t2(c);
		}else
		{
			t3(c);
		}
	}
	for(int i=1;i<=n;i++)
	{
		printf("%lld ",a[i]);
	}
	return 0;
}
