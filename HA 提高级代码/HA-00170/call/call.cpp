#include<bits/stdc++.h>
using namespace std;
int n,a[100010],m,j[100010],q,f[100010],c[100010],g[1020][1020];
int p[100010],v[100010],v1[100010];
void work(int r)
{
	
	if(j[r]==1)
	{
		a[p[r]]+=v[r];
		a[p[r]]%=998244353;
	}
	else  if(j[r]==2)
	{
		for(int i=1;i<=n;i++)
		{
			a[i]*=v1[r];
			a[i]%=998244353;
		}
	}
	else if(j[r]==3)
	{
		for(int i=1;i<=c[r];i++)
		work(g[r][i]);
	}
}
int main()
{
	freopen("call.in","r",stdin);
	freopen("call.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	scanf("%d",&m);
	for(int i=1;i<=m;i++) 
	{
		scanf("%d",&j[i]);
		if(j[i]==1)  scanf("%d %d",&p[i],&v[i]);
		else if(j[i]==2) scanf("%d",&v1[i]);
		else if(j[i]==3)
		{
			scanf("%d",&c[i]);
			for(int k=1;k<=c[i];k++) scanf("%d",&g[i][k]);
		}
	}
	scanf("%d",&q);
	for(int i=1;i<=q;i++) 
	{
		scanf("%d",&f[i]);
		work(f[i]);
	}
	for(int i=1;i<=n;i++)
	{
		printf("%d ",a[i]);
	}
	return 0;
}
