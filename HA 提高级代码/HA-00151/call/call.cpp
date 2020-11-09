#include<bits/stdc++.h>
using namespace std;
const int N=100001;
int a[N],pl[N][2],sum[N],g[5001][5001],e[N][2];
int n,m,q,i,j,t,p,v,c,pi=0,si=0,gi=0;
int hs(int w)
{
		int j,p,v;
		int x=e[w][1],y=e[w][2];
		if(x==1)
		{
			p=pl[y][1];
			v=pl[y][2];
			a[p]=a[p]+v;
			if(a[p]>=998244353)
				a[p]=a[p]%998244353;
		}
		if(x==2)
		{
			v=sum[y];
			for(j=1;j<=n;j++)
				a[j]=a[j]*(v%998244353)%998244353;
		}
		if(x==3)
			for(j=1;j<=g[y][0];j++)
				hs(g[y][j]);
}
int main()
{
	freopen("call.in","r",stdin);
	freopen("call.out","w",stdout);
	cin>>n;
	for(i=1;i<=n;i++)
		cin>>a[i];
	cin>>m;
	for(i=1;i<=m;i++)
	{
		cin>>t;
		if(t==1)
		{
			cin>>p>>v;
			pl[++pi][1]=p;
			pl[pi][2]=v;
			e[i][1]=1;
			e[i][2]=pi;
		}
		if(t==2)
		{
			cin>>v;
			sum[++si]=v;
			e[i][1]=2;
			e[i][2]=si;
		}
		if(t==3)
		{
			cin>>c;
			gi++;
			g[gi][0]=c;
			for(j=1;j<=c;j++)
			{
				cin>>v;
				g[gi][j]=v;
			}
			e[i][1]=3;
			e[i][2]=gi;
		}
	}
	cin>>q;
	for(i=1;i<=q;i++)
	{
		cin>>v;
		hs(v);
	}
	for(i=1;i<=n;i++)
		cout<<a[i]<<' ';
}
