#include<bits/stdc++.h>
#define ull unsigned long long
using namespace std;
const int N=1e6+10;
ull a[N],ans=1,pow2[70],now;
int n,m,c,k;
int vis[N],cnt=0;
int main()
{
	freopen("zoo.in","r",stdin);
	freopen("zoo.out","w",stdout);
	pow2[0]=1;
	for(int i=1;i<=63;i++)
		pow2[i]=pow2[i-1]*2;
	memset(vis,0,sizeof(vis));
	scanf("%d%d%d%d",&n,&m,&c,&k);
	for(int i=1;i<=n;i++)
	{
		scanf("%llu",&a[i]);
		now=(now|a[i]);
	}	
	for(int i=1;i<=m;i++)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		vis[x]=1;
	}
	for(int i=0;i<=k-1;i++)
	{
		int f1=0,f2=0;
		if((now>>i)&1) f1=1;
		if(vis[i]) f2=1;
		if(f1==1||(f1==0&&vis[i]==0)) 
		{
			ans=ans+pow2[cnt];
			cnt++;
		}
	}
	ans=ans-n;
	printf("%llu\n",ans);
	return 0;
}
