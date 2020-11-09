#include<bits/stdc++.h>
#define rint register int
using namespace std;
int n,m,k,f[70],c,b[105];
long long a[100005],q[100005],p[100005];
long long s;
map<int,bool> g;
int main()
{
	freopen("zoo.in","r",stdin);
	freopen("zoo.out","w",stdout);
	cin>>n>>m>>c>>k;s=1;
	for(rint i=1;i<=n;i++)
	{
	scanf("%lld",&a[i]);
//	b[a[i]]=1;
	for(rint j=1;j<=k;j++)
	{
		if((1<<j-1)&a[i])
		f[j]=i;
	}
	}
	for(rint i=1;i<=m;i++)
	{
		scanf("%lld%lld",&p[i],&q[i]);
		if(f[p[i]+1])
		{
		g[q[i]]=1;
		}
	}
	for(rint i=1;i<=m;i++)
	{
		if(g[q[i]]==0)
		{
			b[p[i]]=1;
		}
	}
	for(rint i=1;i<=k;i++)
	{
		if(b[i]==0) s*=2;
	}
	s=s-n;
	cout<<s;
	return 0;
}
