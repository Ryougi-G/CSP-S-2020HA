#include<bits/stdc++.h>
using namespace std;
int n,m,q;
const int N=20001;
int a[N],p[N],t[N],v[N],c[N],f[N],w[N];
int gc[N];
int hs1(int x[N],int t,int pyf)
{
	x[t]+=pyf;
}
int hs2(int x[N],int hxy)
{
	for(int i=1;i<=n;++i)
	{
		x[i]*=hxy;
	}
}
int main()
{
	freopen("call.in","r",stdin);
	freopen("call.out","w",stdout);
	cin>>n;
	for(register int i=1;i<=n;++i)
	{
		cin>>a[i];
	}
	cin>>m;
	for(register int i=1;i<=m;++i)
	{
		cin>>t[i];
		if(t[i]==1)
		{
			cin>>p[i]>>v[i];
		}
		if(t[i]==2)
		{
			cin>>w[i];
		}
		if(t[i]==3)
		{
			cin>>c[i];
			for(register int j=1;j<=c[i];j++)
			{
				cin>>gc[j];
			}
		}
	}
	cin>>q;
	for(register int i=1;i<=q;++i)
	{
		cin>>f[i];
	}
	for(register int i=1;i<=q;++i)
	{
		if(f[i]==1)	
		{
			hs1(a,p[i],v[i]);
		}
		if(f[i]==2)
		{
			hs2(a,w[i]);
		}
		if(f[i]==3)
		{
			for(register int k=1;k<=c[i];k++)
			{
				if(gc[k]==1)
				{
						
					hs1(a,p[i],v[i]);
				}
				if(gc[k]==2)	
				{
					
					hs2(a,w[i]);
				}
			}
		}
	}
	for(register int i=1;i<=n;++i)
	{
		cout<<a[i]<<" ";
	}
}
