#include<bits/stdc++.h>
using namespace std;
int T,n,ans=0,k;
int xx,yy;
int a[10100];
bool guo[10100];
void work1()
{
	if((a[1]>a[2])&&((a[1]-a[2])>a[3]))
	{
		ans=1;
		return;
	}
	if((a[2]>a[3])&&((a[2]-a[3])>=a[1]))
	{
		ans=1;
		return;
	}
	if((a[3]>=a[2])&&((a[3]-a[2])>=a[1]))
	{
		ans=1;
		return;
	}
}
void work2()
{
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			for(int k=1;k<=n;k++)
			if(a[i]>a[j]&&i>j)
			{
				if(i>k)
				{
					if(a[i]-a[j]>=a[k])
					{
						a[i]-=a[j];
						guo[i]=1;
					}
				}
				else
				{
					if(a[i]-a[j]>a[k])
					{
						a[i]-=a[j];
						guo[i]=1;
					}
				}
			}
		}
		if(guo[i]=1)	ans--,guo[i]=0;
	}
}
int main()
{
	freopen("snakes.in","r",stdin);
	freopen("snakes.out","w",stdout);
	cin>>T;
	for(int i=1;i<=1;i++)
	{
		cin>>n;
		ans=n;
		for(int j=1;j<=n;j++)
			scanf("%d",&a[j]);
		if(n==3)	work1();
		else	work2();
		cout<<ans<<endl;
	}
	for(int i=2;i<=T;i++)
	{
		cin>>k;
		ans=n;
		for(int j=1;j<=k;j++)
		{
			cin>>xx>>yy;
			a[xx]=yy;
		}
		if(n==3)	work1();
		else	work2();
		cout<<ans<<endl;
	}
	return 0;
}
