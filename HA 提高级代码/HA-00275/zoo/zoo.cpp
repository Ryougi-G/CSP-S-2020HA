#include<iostream>
#include<cstdio>
using namespace std;
long long int a[100001];
int p[100001],q[100001];
int n,m,c,k;
long long int ans=0;
bool pd[65],hh[100001];
int main()
{
	freopen("zoo.in","r",stdin);
	freopen("zoo.out","w",stdout);
	scanf("%d%d%d%d",&n,&m,&c,&k);
	for(int i=1;i<=n;i++)
	{
		scanf("%lld",&a[i]);
		hh[a[i]]=1;
	}
	for(int i=1;i<=m;i++)
	{
		scanf("%d%d",&p[i],&q[i]);
		for(int j=1;j<=n;j++)
		{
			if(a[j]&(1<<p[i]))
			{
				pd[p[i]]=1;
			} 
		}
	}
	for(int i=0;i<=(1<<k)-1;i++)
	{
		if(!hh[i])
		{
			for(int j=0;j<k;j++)
			{
				if(i&(1<<j)&&pd[j])
				{
					ans++;
					break;
				}
			}
		}
	}
	cout<<ans;
	return 0;
}
