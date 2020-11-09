#include <bits/stdc++.h>
using namespace std;
int n,m,q,x,y;
int a[100010];
int f[100010];
struct node{
	int t;
	int qd,zd;
	int cz;
	int gs,lx;
}b[100010][100];
int main()
{
	freopen("call.in","r",stdin);
	freopen("call.out","w",stdout);
	memset(f,0,sizeof(f));
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	cin>>m;
	for(int i=1;i<=m;i++)
	{
		cin>>b[i][0].t;
		if(b[i][0].t==1) cin>>b[i][0].qd>>b[i][0].zd;
		else if(b[i][0].t==2) cin>>b[i][0].cz;
		else if(b[i][0].t==3) 
		{
			cin>>b[i][0].gs;
			for(int j=1;j<=b[i][0].gs;j++)
			{
				cin>>b[i][j].lx;
			}
		}
	}
	cin>>q;
	for(int i=1;i<=q;i++)
	{
		cin>>x;
		if(b[x][0].t==1) 
		{
			for(int j=b[x][0].qd;j<=b[x][0].zd;j++)
			{
				a[j]++;
				a[j]%=998244353;
			}
		}
		if(b[x][0].t==2)
		{
			for(int j=1;j<=n;j++)
			{
				a[j]*=b[x][0].cz;
				a[j]%=998244353;
			}
		}
	}
	cout<<a[1];
	for(int i=2;i<=n;i++)
	{
		cout<<' '<<a[i];
	}
	return 0;
}
