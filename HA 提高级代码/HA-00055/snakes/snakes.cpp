#include <bits/stdc++.h>
using namespace std;
int t;
int n;
int a[1000100];
int main()
{
	freopen("snakes.in","r",stdin);
	freopen("snakes.out","w",stdout);
	cin>>t;
	cin>>n;
	int maxx,mid,minn;
	int k;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	if(a[1]<=a[2])
		{
			maxx=2;
			mid=1;
			if(a[2]<=a[3])
			{
				maxx=3;
				mid=2;
				minn=1;
			}
			else
			{
				maxx=2;
				if(a[1]<=a[3])
				{
					mid=3;
					minn=1;
				}
				else
				{
					mid=1;
					minn=3;
				}
			}
		}
		else if(a[1]>a[2])
		{
			maxx=1;
			mid=2;
			if(a[1]<=a[3])
			{
				maxx=3;
				mid=1;
				minn=2;
			}
			else
			{
				maxx=1;
				if(a[2]<=a[3])
				{
					mid=3;
					minn=2;
				}
				else 
				{
					mid=2;
					minn=3;
				}
			}
	}
	if(a[maxx]-a[minn]>a[mid]) cout<<1<<endl;
	else cout<<3<<endl;
	int x,y;
	t--;
	while(t--)
	{
		cin>>k;
		for(int i=1;i<=k;i++)
		{
			cin>>x>>y;
			a[x]=y;
		}
		if(a[1]<=a[2])
		{
			maxx=2;
			mid=1;
			if(a[2]<=a[3])
			{
				maxx=3;
				mid=2;
				minn=1;
			}
			else
			{
				maxx=2;
				if(a[1]<=a[3])
				{
					mid=3;
					minn=1;
				}
				else
				{
					mid=1;
					minn=3;
				}
			}
		}
		else if(a[1]>a[2])
		{
			maxx=1;
			mid=2;
			if(a[1]<=a[3])
			{
				maxx=3;
				mid=1;
				minn=2;
			}
			else
			{
				maxx=1;
				if(a[2]<=a[3])
				{
					mid=3;
					minn=2;
				}
				else 
				{
					mid=2;
					minn=3;
				}
			}
		}
		if(a[maxx]-a[minn]>a[mid]) cout<<1;
		else cout<<3;
		if(t!=0) cout<<endl;
	}
	return 0;
}
