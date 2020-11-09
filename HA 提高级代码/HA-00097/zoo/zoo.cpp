#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define rint register int
ll n,m,c,k,a,sum,pp;
int p,q,ans;
map<int,int> mp;
int main()
{
	freopen("zoo.in","r",stdin);
	freopen("zoo.out","w",stdout);
	scanf("%lld%lld%lld%lld",&n,&m,&c,&k);
	for(rint i=1;i<=n;i++)
	{
		scanf("%lld",&a);
		mp[a]=1;
		sum=(sum|a);
	}
	for(rint i=1;i<=m;i++)
	{
		scanf("%lld%lld",&p,&q);
		cout<<(1<<p)<<endl;
		if((sum&(1<<p))==0)
		pp=pp|(1<<p);
	}
	for(rint i=0;i<=(1<<k)-1;i++)
	{
		if(mp[i]==0)
		{
			if((pp&i)==0) ans++;
		}
	}
	cout<<ans;
	return 0;
} 
