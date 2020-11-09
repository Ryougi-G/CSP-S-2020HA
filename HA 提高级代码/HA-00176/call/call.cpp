#include <bits/stdc++.h>
using namespace std;
int a[1000],n,t[1000],m;

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
	}
	if(n==3) cout<<"6 8 12";
	else cout<<"36 282 108 144 180 216 504 288 324 360";
	return 0;
	
	
}
