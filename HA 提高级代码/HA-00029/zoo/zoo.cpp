#include <bits/stdc++.h>
using namespace std;
int n,m,c,k,a[1000001],b[1000001],x,y;
int gcd(int x,int y)
{
	return y^=x^=y^=x%=y;
}
int work(int n)
{
	
}
int main()
{
	freopen("zoo.in","r",stdin);
	freopen("zoo.out","w",stdout);
	cin>>n>>m>>c>>k;
	for(int i=1;i<=n;++i)
		scanf("%d",&a[i]);
	for(int i=1;i<=m;==i)
	{
		scanf("%d,%d",&x,&y);
		b[x]+=y;
	}
	for(int i=1;i<=n;++i)
	{
		work(a[i]);
	}
	return 0;
}
