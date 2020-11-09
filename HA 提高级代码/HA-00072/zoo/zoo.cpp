#include<bits/stdc++.h>
using namespace std;
int n,m,c,k;
long long tot,ans,e,amax;
long long a[1000001];
bool f[65];
int main()
{
	freopen("zoo.in","r",stdin);
	freopen("zoo.out","w",stdout);
	scanf("%d%d%d%d",&n,&m,&c,&k);
	for(int i=1;i<=n;i++)
	{
		scanf("%lld",a+i);
	}
	for(int i=1;i<=m;i++)
	{
		long long x,y;
		scanf("%d%d",&x,&y);
		f[x]=1;
		amax=max(amax,x);
	}
	for(int j=0;j<=amax;j++)
	{
		if(e&(1<<j)||!f[j]) continue;
		for(int i=1;i<=n;i++)
		{
			if(a[i]&(1<<j))
			{
				e+=(1<<j);
			}
		}
	}
	for(int i=1;i<=k;i++)
	{
		if(f[k]&&(!e&(1<<i)))
		{
			ans+=(1<<i);
		}
	}
	printf("%lld",(long long)((1<<(k-1))-ans));
	return 0;
}

