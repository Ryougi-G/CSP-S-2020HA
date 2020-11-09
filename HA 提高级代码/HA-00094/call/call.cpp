#include<bits/stdc++.h>
using namespace std;
#define rint register int
const int maxn=100007,maxm=100007;
inline int read()
{
	int x=0,f=1;
	char c=getchar();
	while(!isdigit(c))
	{
		if(c=='-')
		f=-1;
		c=getchar();
	}
	while(isdigit(c))
	{
		x=(x<<3)+(x<<1)+c-'0';
		c=getchar();
	}
	return x*f;
}
struct node
{
	int to,lop;
}l[1000007];
long long moder=998244353,mx[maxm],ad[maxm],a[maxn];
int n,m,q,s[maxm],c,cnt,h[maxm],su;
long long mo;
inline void add(int x,int y)
{
	l[++cnt].to=y;
	l[cnt].lop=h[x];
	h[x]=cnt;
}
inline void work(int);
inline void div(int y)
{
	if(!y)
	return ;
	div(l[y].lop);
	work(l[y].to);
}
inline void work(int u)
{
	if(s[u]==3)
	div(h[u]);
	else if(s[u]==1)
	a[mx[u]]=(a[mx[u]]+ad[u])%moder;
	else if(s[u]==2)
	for(rint i=1;i<=n;i++)
	a[i]=a[i]*mx[u]%moder;
}
int main()
{
	freopen("call.in","r",stdin);
	freopen("call.out","w",stdout);
	n=read();
	for(rint i=1;i<=n;i++)
	a[i]=read();
	m=read();
	for(rint i=1;i<=m;i++)
	{
		s[i]=read();
		if(s[i]==1)
		mx[i]=read(),ad[i]=read();
		else if(s[i]==2)
		mx[i]=read();
		else if(s[i]==3)
		{
			c=read();
			for(rint j=1;j<=c;j++)
			{
				su=read();
				add(i,su);
			}
		}
	}
	q=read();
	for(rint i=1;i<=q;i++)
	{
		su=read();
		work(su);
	}
	for(rint i=1;i<=n;i++)
	printf("%lld ",a[i]);
	return 0;
}
