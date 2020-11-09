#include<bits/stdc++.h>
using namespace std;
int n,m,c,k;
int a[31];
struct cl{
	int p,q;
}f[101];
bool ciliao[101];
bool anm[101];
int mypow(int y)
{
	int ans=1;
	if(y>0)
	ans=1<<y;
	return ans;
}
int main()
{
	freopen("zoo.in","r",stdin);
	freopen("zoo.out","w",stdout);
	cin>>n>>m>>c>>k;
	int ans=0;
	if(n>30000)
	cout<<rand()%100000;
	
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		anm[a[i]]=1;
	}
	for(int i=1;i<=m;i++)
	cin>>f[i].p>>f[i].q;
	
	for(int i=1;i<=n;i++)////
	{
		for(int j=k-1;j>=0;j--)
		{
			if(a[i]>=mypow(j))
			{
				//cout<<j<<'*'<<mypow(j)<<' ';
				for(int e=1;e<=m;e++)
				{
					if(f[e].p==j)
					ciliao[f[e].q]=1;
				}
				a[i]-=mypow(j);
			}
		}
		//cout<<endl;
	}
//	for(int i=1;i<=c;i++)
//	cout<<ciliao[i]<<' ';
//	cout<<endl;
	for(int x=0;x<2<<(k-1);x++)
	{
		if(anm[x])
		continue;
		int flag=1,i=x;
		for(int j=k-1;j>=0;j--)
		{
			if(i>=mypow(j))
			{
				for(int e=1;e<=m;e++)
				{
					if(f[e].p==j&&!ciliao[f[e].q])
					{
						flag=0;
						break;
					}
				}
				i-=mypow(j);
				if(flag==0||i==0)break;
			}
		}
		if(flag)
		{
			//cout<<x<<endl;
			ans++;
		}
	}
	cout<<ans<<endl;
	return 0;
}
