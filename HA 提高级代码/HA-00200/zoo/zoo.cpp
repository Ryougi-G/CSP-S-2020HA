#include<bits/stdc++.h>
#define fint register int
#define H 51
#define N 10001
using namespace std;
int a[N],p[N],q[N],st[N][H],siz[N],mp[N],buys[N];
bool vis[N];
inline void fj(int x,int num);
int main()
{
	freopen("zoo.in","r",stdin);
	freopen("zoo.out","w",stdout);
	int n,m,c,k;
	cin>>n>>m>>c>>k;
	int hig=(1<<k);
	for(fint i=1;i<=n;i++)
	cin>>a[i],fj(a[i],i),vis[a[i]]=1;
	for(fint i=1;i<=m;i++)
	{
		cin>>p[i]>>q[i];
		mp[p[i]]=q[i];
		for(fint j=1;j<=n;j++)
		{
			if(st[j][p[i]]==1)
			buys[q[i]]=1;
		}
	}
	int now=n+1;
	int ans=0;
	for(fint i=0;i<hig;i++)
	if(!vis[i])
	{
		fj(i,now);
		bool ff=0;
		for(fint j=0;j<siz[now];j++)
		if(st[now][j]==1&&mp[j]&&(!buys[mp[j]]))
		{
			ff=1;
			break;
		}
		if(!ff)
		ans++;
		now++;
	}
	cout<<ans;
	return 0;
}

inline void fj(int x,int num)
{
	int cnt=0;
	if(x==0)
	{
		siz[num]=1;
		return ;
	}
	while(x)
	{
		st[num][cnt++]=x%2;
		x/=2;
	}
	siz[num]=cnt;
	return ;
}
