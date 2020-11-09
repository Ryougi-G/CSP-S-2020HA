#include<bits/stdc++.h>
using namespace std;
int t,a[1000100],b[1000100];
bool f[1000100];
int n,ans;
void Pan(int x,int y,int z,int tot)
{
	for(int i=1;i<tot;i++)
		if(b[i]==y)
		{
			ans=n-tot+2;
			return;
		}
	b[tot]=x;
	a[x]-=a[y];
	f[y]=1;
	int maxn=-1,cmax=-1,minn=1e9,maxi,mini,cmaxi;
	for(int i=1;i<=n;i++)
	{
		if(f[i]) continue;
		if(a[i]>=maxn)
		{
			maxn=a[i]; 
			maxi=i;
		}
	}
	f[maxi]=1;
	for(int i=1;i<=n;i++)
	{
		if(f[i]) continue;
		if(a[i]>=cmax)
		{
			cmax=a[i]; 
			cmaxi=i;
		}
	}
	f[maxi]=0;
	for(int i=n;i>=1;i--)
	{
		if(f[i]) continue;
		if(a[i]<=minn)
		{
			minn=a[i]; 
			mini=i;
		}
	}
	Pan(maxi,mini,cmaxi,tot+1);
}
void Work2()
{
	ans=0;
	sort(a+1,a+1+n);
	memset(f,0,sizeof(f));
	Pan(n,1,n-1,1);
	cout<<ans<<endl;
}
void Work1()
{
	sort(a+1,a+1+n);
	if(a[3]-a[1]<a[2]) cout<<3<<endl;
	else cout<<1<<endl;
}
void work1()
{
	for(int i=1;i<=n;i++) cin>>a[i];
	if(n==3) Work1();
	else Work2();
	for(int i=1;i<t;i++)
	{
		int k;
		cin>>k;
		for(int j=1;j<=k;j++)
		{
			int x,y;
			cin>>x>>y;
			a[x]=y;
		}
		if(n==3) Work1();
		else Work2();
	}
}
int main()
{
	freopen("snakes.in","r",stdin);
	freopen("snakes.out","w",stdout);
	
	cin>>t;
	cin>>n;
	work1();		
	return 0;
}
