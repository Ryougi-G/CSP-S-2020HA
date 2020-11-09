#include<bits/stdc++.h>
#define fint register int
#define H 1001
#define N 1000001
using namespace std;
const int mods=998244353;
long long a[N],t[N],xx[N],yy[N],cheng[N],num[N],diao[H][H];
long long n;
inline long long read();
inline void dfs(long long x);
int main()
{
	freopen("call.in","r",stdin);
	freopen("call.out","w",stdout);
	cin>>n;
	for(fint i=1;i<=n;i++)
	cin>>a[i];
	long long m;
	cin>>m;
	for(fint i=1;i<=m;i++)
	{
		cin>>t[i];
		if(t[i]==1)
		xx[i]=read(),yy[i]=read();
		if(t[i]==2)
		cheng[i]=read();
		if(t[i]==3)
		{
			num[i]=read();
			for(fint j=1;j<=num[i];j++)
			diao[i][j]=read();
		}
	}
	long long q;
	q=read();
	for(fint i=1;i<=q;i++)
	{
		long long op;
		op=read();
		if(t[op]==1)
		a[xx[op]]+=yy[op],a[xx[op]]%=mods;
		if(t[op]==2)
		for(fint j=1;j<=n;j++)
		a[j]*=cheng[op],a[j]%=mods;
		if(t[op]==3)
		for(fint j=1;j<=num[op];j++)
		dfs(diao[op][j]);
	}
	for(fint i=1;i<=n;i++)
	cout<<a[i]<<" ";
	return 0;
}

inline void dfs(long long x)
{
	if(t[x]==1)
	{
		a[xx[x]]+=yy[x],a[xx[x]]%=mods;
		return ;
	}
	if(t[x]==2)
	{
		for(fint i=1;i<=n;i++)
		a[i]*=cheng[x],a[i]%=mods;
		return ;
	}
	for(fint i=1;i<=num[x];i++)
	dfs(diao[x][i]);
	return ;
}

inline long long read()
{
	long long x=0,f=1;
	char ch=getchar();
	while(ch<'0'||ch>'9')
	{
		if(ch=='-')
		f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9')
	{
		x=(x<<1)+(x<<3)+(ch^48);
		ch=getchar();
	}
	return x*f;
}
