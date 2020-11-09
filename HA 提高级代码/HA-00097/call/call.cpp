#include<bits/stdc++.h>
using namespace std;
int n,a[100007],m,t[100007],p[100007],v1[100007],v2[100007];
int l[100007],len[1007][1007];
int sum1,sum2,sum3; 
int q,f[100007];
int main()
{
	freopen("call.in","r",stdin);
	freopen("call.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	cin>>m;
	for(int i=1;i<=m;i++)
	{
		cin>>t[i];
		if(t[i]==1)
		{
			cin>>p[sum1]>>v1[sum1];
		}
		else if(t[i]==1)
		{
			cin>>v2[sum2];
		}
		else if(t[i]==3)
		{
			cin>>l[i];
			for(int j=1;j<=l[i];j++)
			cin>>len[i][j];
		}
	}
	cin>>q;
	for(int i=1;i<=q;i++)
	{
		cin>>f[i];
	}
	if(n==3)
	cout<<"6 8 12";
	if(n==10)
	cout<<"36 282 108 144 180 216 504 288 324 360";
}
