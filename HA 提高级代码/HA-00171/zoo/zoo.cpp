#include<bits/stdc++.h>
using namespace std;
const int N=1000000+5,M=1000000+5;
int n,m,c,k,a[N],p[M],q[M];
int main()
{
	freopen("zoo.in","r",stdin);
	freopen("zoo.out","w",stdout);
	cin>>n>>m>>c>>k;
	int i,temp=1;
	for(i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(i=1;i<=m;i++)
	{
		cin>>p[i]>>q[i];
	}
	for(i=1;i<=k;i++)
	{
		temp*=2;
	}
	cout<<temp-n<<endl;
	return 0;
}
