#include<bits/stdc++.h>
using namespace std;
int n,m,q;
long long x[100009];
struct f
{
	int t;
	int p,v;
	int c[100009];
};
f y[1000];
int z[100009];
int main()
{
	
	freopen("call.in","r",stdin);
	freopen("call.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	cin>>x[i];
	cin>>m;
	for(int i=1;i<=m;i++)
	{
		cin>>y[i].t;
		if(y[i].t==1)
		cin>>y[i].p>>y[i].v;
		else if(y[i].t==2)
		cin>>y[i].v;
		else if(y[i].t==3)
		{
			cin>>y[i].p;
			for(int j=1;j<=y[i].p;j++)
			cin>>y[i].c[j];
		}
	}
	cin>>q;
	for(int i=1;i<=q;i++)
	cin>>z[i];
	for(int i=1;i<=q;i++)
	{
		if(y[z[i]].t==1)
		x[y[i].p]=(x[y[i].p]+y[i].v)%998244353;
		else if(y[z[i]].t==2)
		{
			for(int j=1;j<=n;j++)
			x[j]=((x[j]%998244353)*(y[i].v%998244353))%998244353;
		}
		/*else if(y[z[i]].t==3)
		{
			for(int j=1;j<=y[z[i]].p;j++)
			if(y[y[z[i]].c[j]].t==1)
			x[y[y[z[i]].c[i]].p]=(x[y[y[z[i]].c[i]].p]+y[y[z[i]]])
		}*/
	}
	for(int i=1;i<n;i++)
	cout<<x[i]<<' ';
	cout<<x[n]<<'\n';
	
	return 0;
}
