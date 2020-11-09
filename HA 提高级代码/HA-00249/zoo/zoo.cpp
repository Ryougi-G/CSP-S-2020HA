#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e7+7;
ll sum;
int n,m,c,k,a[maxn],q[maxn],p[maxn],s[3][70],ss[3][70],f[maxn];
int main()
{
	freopen("zoo.in","r",stdin);
	freopen("zoo.out","w",stdout);
	scanf("%d%d%d%d",&n,&m,&c,&k);
	for(int i=1;i<=n;i++)	
	{
		scanf("%d",&a[i]);
	}
	for(int i=1;i<=m;i++)	scanf("%d%d",&p[i],&q[i]);
	for(int i=1;i<=pow(2,k);i++)
	{
		int t=0;
		int v=i;
		while(v!=0)
		{
			s[i][++t]=v%2;
			v=v/2;
		}
	}
	int h=pow(2,k)-n;
	for(int i=1;i<=m;i++)
	{
		for(int j=1;j<=n;j++)
		{
			if(s[a[j]][p[i]]=1)
			sum++;
		}
	}
	if(c%m==0)h=c-m;
	for(int i=1;i<=m;i++)
	{
		for(int j=1;j<=pow(2,k);j++)
		{
			if(s[j][p[i]]==1&&f[j]!=0)	f[j]=1;
			if(s[j][p[i]]!=0) f[j]=0;
		}
	}
	cout<<h;
	return 0;
}
