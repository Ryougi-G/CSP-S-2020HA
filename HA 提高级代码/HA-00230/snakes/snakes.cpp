#include<bits/stdc++.h>
using namespace std;
int a[10000001],b[10000001];
int main()
{
	freopen("snakes.in","r",stdin);
	freopen("snakes.out","w",stdout);
	int T;
	cin>>T;
	for(int zppp = 1;zppp<=T;zppp++)
	{
		int n;cin>>n;
		int p = n;
		if(zppp==1)
		{
			for(int i = 1;i<=n;i++)
			cin>>a[i];
			while(n>1)
			{
				sort(a+1,a+n+1);
				if(a[n]-a[1]<a[n-1])
				{
					cout<<n;
					break;
				}
				else
				{
					a[n]-=a[1];
					n--;
				}
			}
			if(n==1)cout<<1;	
		}
		else
		{
			for(int i = 1;i<=2*n;i++)
			{
				cin>>b[i];
			}
			for(int i = 1;i<=2*n;i++)
			{
				if(i%2==1)
					a[b[i]] = b[i+1];
			}
			while(n>1)
			{
				sort(a+1,a+1+p);
				if(a[n]-a[1]<a[n-1])
				{
					cout<<n;
					break;
				}
				else
				{
					a[n]-=a[1];
					n--;
					a[1] = 999999;
				}
			}	
			if(n==1)cout<<1;
		}
		
	}
	return 0;
}
