#include<bits/stdc++.h>
using namespace std;

int n,m,c,k;
int ans=0;
int a[1002003];
bool a1[1002003];

struct edge
{
	int x,y;
}gz[1020020];

int main()
{
	freopen("zoo.in","r",stdin);
	freopen("zoo.out","w",stdout);
	cin>>n>>m>>c>>k;
	bool c1[c+1];
	memset(c1,0,sizeof(c1));
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		a1[i]=1;
	}
	for(int i=1;i<=m;i++)
		cin>>gz[i].x>>gz[i].y;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			int num1;
			for(int l=1;l<gz[j].x;l++)
				num1=a[i]/2;
			if(num1%2==1) c1[gz[j].y]=1; 
		}
	}
	int num=1;
	for(int i=1;i<=k;i++)
		num=2*num;
//		cout<<num<<endl;
	for(int i=1;i<=num;i++)
	{
		int num2,num3;
		num3=i;
//		cout<<num3<<endl;
//      cout<<k<<endl;
		for(int j=1;j<=k;j++)
		{ 
			num2=num3%2;
//			cout<<num2<<endl;
			for(int l=1;l<=m;l++)
			{
				if((num2==1)&&(j==gz[l].x)&&(a1[i]==0))
				{
					ans++;
				}
			}
			num3=i/2;
			if(num2==1) num3++;
		}
	}
	cout<<ans;
	return 0;
}
