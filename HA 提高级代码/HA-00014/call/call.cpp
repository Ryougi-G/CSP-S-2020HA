#include <bits/stdc++.h>
using namespace std;
const int MAXN = 2e4+10;
int n,a[MAXN],m,t[MAXN],p[MAXN],v[MAXN],c,g[MAXN],q,f[MAXN],cnt=0,tnt=0,A,B;
int call2(int v[])
{
	for(int times=1;times<=n;times++)
		a[times]*=v[tnt];
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
			cnt++;
			cin>>A>>B;
		}
		else if(t[i]==2)
		{
			tnt++;
			cin>>v[tnt];
		}
		else if(t[i]==3)
		{
			cin>>c;
			for(int j=1;j<=c;j++)
			{
				cin>>g[j];
			}	
		}
	}	
	cin>>q;
	for(int k=1;k<=q;k++)
	{
		cin>>f[k];
		if(f[k]==1)	a[p[1]]+=v[1];
		else if(f[k]==2) call2(v);
		else if(f[k]==3)
		{
			for(int l=1;l<=c;l++)
			{
				if(g[l]==1) 
				{
					a[1]+=1;
					continue;
				}
				else if(g[l]==2) call2(v);
			}
		}
	}
	for(int i=1;i<n;i++)
		cout<<a[i]<<' ';
	cout<<a[n];
	return 0;
}
