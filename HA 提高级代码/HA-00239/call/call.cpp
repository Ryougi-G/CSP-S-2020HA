#include <bits/stdc++.h>
#define maxn 10500
using namespace std;
long long n,a[maxn],m,t[maxn],f[maxn],kb[maxn];
long long p,v;
int c;
int g;
long long t1(long long x,long long y)
{
	a[x]+=y;
}
long long t2(long long z,long long y)
{
	for(int i=1;i<=y;i++)
		a[i]*=z;
}
int main()
{	freopen("call.in","r",stdin);
	freopen("call.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	cin>>m;
	for(int j=1;j<=m;j++)
		{
			cin>>t[j];
			if(t[j]==1)
			{
				
				cin>>p>>v;
			}
			else if(t[j]==2)
			{	
				cin>>c;
			}
			else if(t[j]==3)
			{
				
				cin>>g;
				for(int i=1;i<=g;i++)
					cin>>kb[i];
			}		
		}
	int q;
	cin>>q;
	for(int i=1;i<=q;i++)
		cin>>f[i];
	for(int i=1;i<=q;i++)
	{
		if(f[i]==1)
			t1(p,v);
		else if(f[i]==2)
			t2(c,n);
		else if(f[i]==3)
		{	for(int j=1;j<=g;j++)
			{
				if(kb[j]==1)
				t1(p,v);
			else if(kb[j]==2)
				t2(c,n);
			}
		}
	}
	for(int i=1;i<=n;i++)
		cout<<a[i]%998244353<<" ";
	return 0;
}
