#include<bits/stdc++.h>
using namespace std;
int s[5];
int main()
{
	freopen("snakes.in","r",stdin);
	freopen("snakes.out","w",stdout);
	int T,n,k,max=-1,wz;
	int x,y;
	cin>>T;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>s[i];
	}
	for(int i=n;i>=1;i--)
	{
		if(s[i]>max)
		{
			max=s[i];
			wz=i;
		}
	}
	for(int i=1;i<=n;i++)
	{
		if(wz==1)
		{
			if(s[wz]-s[2]>s[3])
			{
				cout<<wz<<endl;
				cout<<1;
				return 0;
			}
		}
		if(wz==2)
		{
			if(s[wz]-s[1]>s[3])
			{
				cout<<wz<<endl;
				cout<<1;
				return 0;
			}
		}
		if(wz==3)
		{
			if(s[wz]-s[1]>s[2])
			{
				cout<<wz<<endl;
				cout<<1;
				return 0;
			}
		}
	}
	for(int j=1;j<=T-1;j++)
	{
	cin>>k;
	for(int i=1;i<=k;i++)
	{
		max=-1;
		cin>>x>>y;
		s[x]=y;
		for(int i=n;i>=1;i--)
	 {
		if(s[i]>max)
		{
			max=s[i];
			wz=i;
		}
	 }
	 for(int i=1;i<=n;i++)
	 {
		if(wz==1)
		{
			if(s[wz]-s[2]>s[3])
			{
				cout<<wz<<endl;
				cout<<1;
				return 0;
			}
		}
		if(wz==2)
		{
			if(s[wz]-s[1]>s[3])
			{
				cout<<wz<<endl;
				cout<<1;
				return 0;
			}
		}
		if(wz==3)
		{
			if(s[wz]-s[1]>s[2])
			{
				cout<<wz<<endl;
				cout<<1;
				return 0;
			}
		}
	 }
	}
   }
	if(n==1)
	{
		cout<<"1"<<endl;
		cout<<"1";
		return 0;
	}
	if(n==2)
	{
		cout<<wz<<endl;
		cout<<"1";
		return 0;
	}
	return 0;
}
