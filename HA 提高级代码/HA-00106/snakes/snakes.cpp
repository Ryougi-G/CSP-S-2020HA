#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,c,k;
int a[4];
signed main( )
{
	freopen("snakes.in","r",stdin);
	freopen("snakes.out","w",stdout);
	int t;
	cin>>t;
	cin>>n;
	cin>>a[1]>>a[2]>>a[3];
	if(a[3]-a[1]>=a[2])cout<<1<<endl;
	else cout<<3<<endl;
	t--;
	while(t--)
	{
		int k;
		cin>>k;
		int x,y;
		for(int i=1;i<=k;i++)cin>>x>>y,a[x]=y;
		if(a[3]-a[1]>=a[2])cout<<1<<endl;
		else cout<<3<<endl;
	}
	
}

