#include<bits/stdc++.h>
using namespace std;
long long n,a[100001],m,t[100001],p[10001],v[100001],c,g[100001],q,f[100001];
int main()
{
	freopen("call.in","r",stdin);
	freopen("call.out","w",stdout);
	scanf("%d",&n);
	for(int i=0;i<=n;i++)
		scanf("%d",&a[i]);
	scanf("%d",&m);
	for(int i=0;i<=m;i++)
	{
		scanf("%d",t[i]);
		if(t[i]==1)scanf("%d %d",&p[i],&v[i]);
		else if(t[i]==2)scanf("%d",&v[i]);
		else{
			scanf("%d",&c);
			for(int j=0;j<=c;j++)
				scanf("%d",&g[i]);
		}
		
	}
	scanf("%d",&q);
	for(int i=0;i<=q;i++)
		scanf("%d",&t[i]);
	for(int i=0;i<=n;i++)
	{
		if(t[i]==1)
			a[p[i]]+=v[i];
		else if(t[i]==2)
			for(int j=0;j<=n;j++)
				a[j]=a[j]*v[i];
		else 
			for(int j=0;j<=c;j++)
			{
				if(g[j]==1)a[p[i]]+=v[i];
				else a[j]=a[j]*v[i];
			}
	}
	for(int i=0;i<=n;i++)
	{
		if(i==0)printf("%d",a[i]);
		else printf(" %d",a[i]);
	}
	return 0;	
}
