#include<bits/stdc++.h>
using namespace std;
long long ms=998244353,n,t,a[1000005],k,y,x,i,b,s,ans;
int com()
{
	long long h=0,s=a[0],b=0;
	for(i=0; i<n; i++)
	{
		s=min(s,a[i]);
		b=max(b,a[i]);
	}
	for(i=0; i<n; i++)
	{
		if(a[i]>h&&a[i]!=b)
		{
			h=a[i];
		}
	}
	if(b-s>=h)
	{
		b-=s;
		return 1;
	}
	return 0;
}
int main()
{
	freopen("snakes.in","r",stdin);
	freopen("snakes.out","w",stdout);
	scanf("%lld%lld",&t,&n);
	i=1;
	ans=n;
	scanf("%lld",&a[0]);
	for(; i<n; i++)
	{
		scanf("%lld",&a[i]);
	}
	while(com())
	{
		ans--;
	}
	printf("%lld\n",ans);
	t--;
	while(t)
	{
		scanf("%lld",&k);
		i=1;
		scanf("%lld",&x);
		scanf("%lld",&a[x]);

		for(; i<k; i++)
		{
			scanf("%lld",&x);
			scanf("%lld",&a[x]);

		}
		ans=n;
		while(com())
		{
			ans--;
		}
		printf("%lld\n",ans);
		t--;
	}
}
