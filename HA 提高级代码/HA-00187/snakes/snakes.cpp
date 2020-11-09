#include<bits/stdc++.h>
using namespace std;
int a[10000];
int n[10000];
int work(int k)
{	
	if(k==3) {
		if(a[3]>a[1]+a[2]) cout<<1;
		if(a[3]==a[1]+a[2]) cout<<2;
		if(a[1]==a[2]==a[3]) cout<<3;
		if(a[3]<a[1]+a[2]) cout<<3;
	}
}
int main()
{
	freopen("snakes.in","r",stdin);
	freopen("snakes.out","w",stdout);
	int t;
	cin>>t;
	for(int i=1;i<=t;i++)
	{
		cin>>n[i];
		for(int j=1;j<=n[i];j++)
			cin>>j>>a[j];
			work(n[i]);
	}
	return 0;
}
