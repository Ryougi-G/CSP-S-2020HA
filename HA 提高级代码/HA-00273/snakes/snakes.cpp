#include<bits/stdc++.h>
using namespace std;
int n,t;
int s[10];
int main()
{
	
	freopen("snakes.in","r",stdin);
	freopen("snakes.out","w",stdout);
	cin>>t>>n;
	if(n==3)
	for(int i=1;i<=t;i++)
	{
		if(i==1)
		{
			for(int i=1;i<=n;i++)
			cin>>s[i];
		}
		else
		{
			int a,b,c;
			cin>>a;
			for(int i=1;i<=a;i++)
			{
				cin>>b>>c;
				s[b]=c;
			}			
		}
		sort(s+1,s+n+1);
		if(s[3]-s[1]>s[2])
		cout<<1<<'\n';
		else
		cout<<3<<'\n';
	}
	
	return 0;
}

//R.I.P.
