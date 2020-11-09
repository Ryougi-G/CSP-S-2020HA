#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int mod=998244353;
inline int read()
{
	char ch=getchar();
	int x=0,f=1;
	while(ch>'9'||ch<'0')
	{
		if(ch=='-') f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9')
	{
		x=x*10+ch-'0';
		ch=getchar();
	}
	return x*f;
}
int n,blo;
int bl[100005];
vector<int> q[100005];
ll a[100005],tag[100005];
/*void add(int l,int r,int k)
{
	for(int i=l;i<=min(r,bl[l]*blo);i++)
	{
		a[i]=(a[i]+k)%mod;
	}
	if(bl[l]==bl[r]) return;
	for(int i=(bl[r]-1)*blo+1;i<=r;i++)
	{
		a[i]=(a[i]+k)%mod;
	}
	for(int i=bl[l]+1;i<bl[r];i++)
	{
		tag[i]=(k+tag[i])%mod;
	}
}*/
/*void cheng(int l,int r,int k)
{
   for(int i=l;i<=r;i++)
   {
   	a[i]=(a[i]+tag[i])%mod;
   	a[i]=a[i]*k%mod;
   	tag[bl[i]]=0;
   }	
}*/
int l[100005],r[100005],value[100005];
void dfs(int now)
{
	int s=q[now].size();
	if(s==1)
  {
	if(q[now][0]==-1)
	{
	    a[l[now]]+=value[now];
	}
	if(q[now][0]==-2)
	{
		for(int i=1;i<=n;i++)
        a[i]=a[i]*value[now]%mod;
	}
	return;
  }
	for(int i=0;i<s;i++)
	{
		dfs(q[now][i]);
	}
}
int main()
{
	freopen("call.in","r",stdin);
	freopen("call.out","w",stdout);
	n=read();
	/*blo=sqrt(n);
	for(int i=1;i<=n;i++)
	{
		bl[i]=(i-1)/blo+1;
	}*/
	for(int i=1;i<=n;i++)
	{
		a[i]=read();
	}
	int m=read();
	for(int i=1;i<=m;i++)//-1¼Ó-2³Ë 
	{
	 	int t=read();
	 	if(t==1) 
	 	{
	 		q[i].push_back(-1);
	 		l[i]=read();
	 		value[i]=read();
		}
		if(t==2)
		{
			q[i].push_back(-2);
			value[i]=read();
		}
		if(t==3)
		{
			int c=read();
			for(int j=1;j<=c;j++)
			{
				int x=read();
				q[i].push_back(x);
			}
		}
	} 
	int Q=read();
	for(int i=1;i<=Q;i++)
	{
		int x=read();
		dfs(x);
	}
	for(int i=1;i<=n;i++)
	{
		printf("%lld ",a[i]);
	}
	return 0;
}
