#include<bits/stdc++.h>
using namespace std;
int n,m,p,v,c,g,q,x;
int a[100010];
struct node
{
	int cao;
	int p;
	int v1;
	int v2;
	int g[1010];
}z[10010];
int w(int ii);
int main()
{
	freopen("call.in","r",stdin);
	freopen("call.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;++i)
	{
		cin>>a[i];
	}
	cin>>m;
	for(int i=1;i<=m;++i)
	{
		cin>>z[i].cao;
		if(z[i].cao==1)
		{
			cin>>z[i].p>>z[i].v1;
		}
		if(z[i].cao==2)
		{
			cin>>z[i].v2;
		}
		if(z[i].cao==3)
		{
			cin>>x;
			for(int j=1;j<=x;++j)
			{
				cin>>z[i].g[j];
			}
		}
	}
	cin>>q;
	for(int i=1;i<=q;++i)
	{
		cin>>x;
		if(x==1)
		{
			a[z[i].p]+z[i].v1;
		}
		if(x==2)
		{
			for(int j=1;j<=n;++j)
			{
				a[j]=a[j]*z[i].v2;
			}
		}
		if(x==3)
		{
			
		}
	}
	for(int i=1;i<=n;++i)
	{
		cout<<a[i];
	}
	return 0;
}
