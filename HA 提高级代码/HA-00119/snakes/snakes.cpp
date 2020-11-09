#include<iostream>
#include<cstdio>
#include<queue>
#include<algorithm>
using namespace std;
long long int a[4];
int main()
{
	freopen("snakes.in","r",stdin);
	freopen("snakes.out","w",stdout);
	long long int T=0,n=0,x=0,y=0,m=0;
	cin>>T>>n;
	for(int i=1;i<=3;i++)
	{
		cin>>a[i];
	}
	if(a[3]-a[1]>=a[2])
	{
		cout<<"1"<<endl;
	}
	else
	{
		cout<<"3"<<endl;
	}
	for(int i=2;i<=T;i++)
	{
		cin>>m;
		for(int j=1;j<=m;j++)
		{
			cin>>x>>y;
			a[x]=y;
		}
		if(a[3]-a[1]>=a[2])
		{
			cout<<"1"<<endl;
		}
		else
		{
			cout<<"3"<<endl;
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
