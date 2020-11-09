#include<bits/stdc++.h>
using namespace std;
int a[100],b[100];int t,n;
bool mycmp(int a,int b)
{
	return a>b;
}
void tcs()
{
	int ans1=n;
	sort(b+1,b+1+n,mycmp);
	//for(int i=1;i<=n;i++)
	//cout<<b[i]<<' ';
	while(b[1]-b[n]>b[n-1])
	{
		ans1--;
		b[1]-=b[n];
		b[n]=0;
		n--;
		sort(b+1,b+1+n,mycmp);
	}
	if(ans1==2) ans1=1;
	cout<<ans1<<endl;
}
int main()
{
	freopen("snakes.in","r",stdin);freopen("snakes.out","w",stdout);
	cin>>t>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		b[i]=a[i];
	}
	tcs();
	for(int i=1;i<t;i++)
	{
		int xx;
		cin>>xx;
		int aa,bb;
		for(int i=1;i<=xx;i++)
		{
			cin>>aa>>bb;
			a[aa]=bb;
		}
		for(int j=1;j<=n;j++)
		{
			b[j]=a[j];
		}
		tcs();
	}
	return 0;
}
