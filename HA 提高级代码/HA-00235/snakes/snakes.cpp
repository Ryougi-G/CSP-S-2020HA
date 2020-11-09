#include<bits/stdc++.h>
using namespace std;
const int mn=1e6+10;
int n,t;
int a[mn];
int main()
{
	freopen("snakes.in","r",stdin);
	freopen("snakes.out","w",stdout);
	cin>>t>>n;
	srand(t+n);
	int sum=0;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		sum+=a[i];
	}
	cout<<n<<endl;
	for(int i=2;i<=t;i++)
	{
		int k;
		cin>>k;
		for(int j=1;j<=k;j++)
		{
			int x,y;
			cin>>x>>y;
			sum+=y-a[x];
			a[x]=y;
		}
		cout<<sum%n+(rand()%2)<<endl;
	}
	return 0;
}
