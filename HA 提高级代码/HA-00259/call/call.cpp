#include<bits/stdc++.h>
using namespace std;
int n;
int a[200000];
int m;
int t[200000];
int p[200000],v[200000];
int g[200000];
int c;
int z[200000];
int q;
int f[200000];
void work1(int x,int y)
{
	 a[x]=a[x]+y;
}
void work2(int x)
{
	for(int i=1;i<=n;i++)
		a[i]=a[i]*x;
}
void work3(int x)
{
	for(int i=1;i<=x;i++)
	{
		if(g[i]==1)
			work1(p[i],v[i]);
		if(g[i]==2)
			work2(z[i]);
	}
}
int main()
{
	freopen("call.in","r",stdin);
	freopen("call.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	cin>>m;
	for(int i=1;i<=m;i++)
	{
		cin>>t[i];
		if(t[i]==1)
		{
			for(int j=1;j<=1;j++)
				cin>>p[j]>>v[j];

		}
		if(t[i]==2)
		{
			for(int j=1;j<=1;j++)
				cin>>z[j];
			work2(z[1]);
		}
		if(t[i]==3)
		{
			cin>>c;
			for(int j=1;j<=c;j++)
			{
				cin>>g[j];
				work3(g[j]);
			}
		}
	}
	cout<<a[1];
	for(int i=2;i<=n;i++)
		cout<<' '<<a[n];
}





