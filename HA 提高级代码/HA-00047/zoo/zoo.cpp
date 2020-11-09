#include<bits/stdc++.h>
using namespace std;
int a[100];
string b[100];
int ans[100];
int main()
{
	freopen("zoo.in","r",stdin);freopen("zoo.out","w",stdout);
	int n,m,c,k;
	cin>>n>>m>>c>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		int t=1;
		while(t<=k)
		{
			b[i][t]=a[i]%2+'0';
			a[i]/=2;
			t++;
		}
	}
	//for(int i=1;i<=n;i++)
	//{
	//	for(int j=1;j<=k;j++)
	//	{
	//		cout<<b[i][j];
	//	}
	//	cout<<endl;
	//}
	int ans1=1;
	for(int i=1;i<=n+1;i++) ans[i]=2;
	int xx,yy;
	for(int i=1;i<=m;i++)
	{
		cin>>xx>>yy;
		bool flag=true;
		for(int j=1;j<=n;j++)
		{
			if(b[j][xx+1]=='1') ans[xx+1]=2,flag=false;
		}
		if(flag==true) ans[xx+1]=1;
	}
	//for(int i=1;i<=k;i++)
	//cout<<ans[i]<<' ';
	for(int i=1;i<=k;i++)
	{
		ans1*=ans[i];
	}
	//cout<<endl;
	cout<<ans1-n<<endl;
	return 0;
}
