#include<bits/stdc++.h>
using namespace std;
int a[100001],b[100001];
int main()
{
	freopen("snakes.in","r",stdin);
	freopen("snakes.out","w",stdout);
	int t,n,i,j,k,x,y;
	cin>>t;
	cin>>n;
	for(i=1;i<=n;i++)
	{
		cin>>a[i];
		b[i]=a[i];
	}
	if(b[3]-b[1]>=b[2])
		cout<<1<<endl;
	else
		cout<<3<<endl;
	for(j=2;j<=t;j++)
	{
		cin>>k;
		for(i=1;i<=k;i++)
		{
			cin>>x>>y;
			a[x]=y;
		}
		for(i=1;i<=n;i++)
			b[i]=a[i];
		if(b[3]-b[1]>=b[2])
			cout<<1<<endl;
		else
			cout<<3<<endl;
	}
}
