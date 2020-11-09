#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e6+10;
int n,m,c,k;
ll ans;
int tot,cnt;
int a[maxn];
int myhead[maxn],mynext[maxn],myver[maxn];
int p[maxn],q[maxn],hsh[maxn];
bool vis[65];
bitset<65> bbit;
inline int readint()
{
	int x=0,f=1; char c=getchar();
	while(c<'0'||c>'9')
	{
		if(c=='-') f=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9')
	{
		x=(x<<1)+(x<<3)+(c^48);
		c=getchar();
	}
	return f*x;
}
inline void add(int u,int v)
{
	mynext[++cnt]=myhead[u];
	myver[cnt]=v;
	myhead[u]=cnt;
}
inline ll mypower(int x)
{
	ll ans=1;
	while(x)
	{
		ans*=2;
		--x;
	}
	return ans;
}
int main()
{
	freopen("zoo.in","r",stdin);
	freopen("zoo.out","w",stdout);
	n=readint(); m=readint(); c=readint(); k=readint();
	for(int i=1;i<=n;++i) a[i]=readint();
	for(int i=1;i<=m;++i)
	{
		p[i]=readint();
		q[i]=readint();
		add(p[i],q[i]);
	}
	for(int i=1;i<=n;++i)
	{
		tot=0;
		while(a[i])
		{
			int x=a[i]%2;
			for(int i=myhead[tot];i;i=mynext[i])
			{
				int y=myver[i];
				if(x) vis[y]=1;
			}
			++tot;
			a[i]/=2;
		}
	}
	for(int i=0;i<mypower(k);++i)
	{
		int t=i; tot=0;
		bool flag=1;
		do
		{
			int x=t%2;
			if(x)
			for(int j=myhead[tot];j;j=mynext[j])
			{
				int y=myver[j];
				if(!vis[y]) flag=0;
			}
			t/=2;
			++tot;
		}
		while(t);
		if(flag) ++ans;
	}
	printf("%lld\n",ans-n);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
