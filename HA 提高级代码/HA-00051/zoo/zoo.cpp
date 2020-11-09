#include<bits/stdc++.h>
using namespace std;
int o[100010],b[100010],lm[100010];
int main()
{
	freopen("zoo.in","r",stdin);
	freopen("zoo.out","w",stdout);
	int n,m,c,k;
	cin>>n>>m>>c>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>b[i];
		lm[b[i]]=1;
		int p=b[i];
		int cnt=0;
		while(p)
		{
			if(p&1)
			{
				o[cnt]=1;
			}
			cnt++;
			p>>=1;
		}
	}
	for(int i=1;i<=m;i++)
	{
		int x,y;
		cin>>x>>y;
		o[y]=1;
	}
	int kl=1;
	for(int i=1;i<=k-1;i++)
	{
		if(o[i]==0)
		{
			kl=0;
			break;
		}
	}
	if(kl)
	{
		cout<<pow(2,k)-n;
	}
	else
	{
		int ans=0;
	for(int i=0;i<pow(2,k);i++)
	{
		int p=i;
		int cnt=0,ll=1;
		if(lm[p]==1)
		ll=0;
		else
		while(p)
		{
			if(p&1)
			{
				if(o[cnt]==0)
				{
					ll=0;
					break;
				}
				
			}
			p>>=1;
			cnt++;
		}
		if(ll)
		{
			ans++;
		}
	}
	cout<<ans;
	}
	
	return 0;
}