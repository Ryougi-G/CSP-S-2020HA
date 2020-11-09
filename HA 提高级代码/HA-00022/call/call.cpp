#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;
const int N=100001,M=101,mod=998244353;
struct SegMent{
	int mul,sum;
	#define mul(p) tree[p].mul
	#define sum(p) tree[p].sum
	#define le(p) p<<1
	#define re(p) p<<1|1
}tree[N<<2];
struct need{
	int num;
	int p,val;
	int len,c[M];
}t[N];
int n,m,q,a[N],f[N],cnt[N];
inline void pushup(int p)
{
	sum(p)=sum(le(p))+sum(re(p));
}
inline void pushdown(int l,int r,int p)
{
	if(mul(p)==1)	return ;
	register int mid=(l+r)>>1;
	sum(le(p))=1ll*sum(le(p))%mod*mul(p)%mod;
	sum(re(p))=1ll*sum(re(p))%mod*mul(p)%mod;
	mul(le(p))=(mul(le(p))*mul(p))%mod;
	mul(re(p))=(mul(re(p))*mul(p))%mod;
	mul(p)=1;
}
inline void build(int l,int r,int p)
{
	mul(p)=1;
	if(l==r)
	{
		cnt[l]=p;
		sum(p)=a[l];
		return ;
	}
	register int mid=(l+r)>>1;
	build(l,mid,le(p)),build(mid+1,r,re(p));
	pushup(p);
}
inline void update(int l,int r,int p,int np,int val)
{
	if(l==np && r==np)
	{
		sum(p)+=(r-l+1)*val;
		return ;
	}
	pushdown(l,r,p);
	register int mid=(l+r)>>1;
	if(np<=mid)
		update(l,mid,le(p),np,val);
	else if(np>mid)
		update(mid+1,r,re(p),np,val);
	pushup(p);
}
inline void work(int p)
{
	if(t[p].num==1)
	{
		update(1,n,1,t[p].p,t[p].val);
		return ;
	}	
	if(t[p].num==2)
	{
		sum(1)=sum(1)*t[p].val%mod,mul(1)=mul(1)*t[p].val%mod;
		return ;
	}
	for(register int i=1;i<=t[p].len;i++)
		work(t[p].c[i]);
}
inline void check(int l,int r,int p)
{
	if(l==r)
		return ;
	pushdown(l,r,p);
	register int mid=(l+r)>>1;
	check(l,mid,le(p)),check(mid+1,r,re(p));
	pushup(p);
}
inline int read()
{
	register int x=0,m=1;register char ch=getchar();
	while(ch<'0' || ch>'9'){if(ch=='-') m=-1;ch=getchar();}
	while(ch>='0' && ch<='9'){x=(x<<3)+(x<<1)+ch-'0';ch=getchar();}
	return x*m;
}
int main()
{
	freopen("call.in","r",stdin);
	freopen("call.out","w",stdout);
	n=read();
	for(register int i=1;i<=n;i++)
		a[i]=read();
	build(1,n,1);
	m=read();
	for(register int i=1;i<=m;i++)
	{
		t[i].num=read();
		if(t[i].num==1)	t[i].p=read(),t[i].val=read();
		if(t[i].num==2)	t[i].val=read();
		if(t[i].num==3)
		{
			t[i].len=read();
			for(register int j=1;j<=t[i].len;j++)
				t[i].c[j]=read();
		}
	}
	q=read();
	for(register int i=1;i<=q;i++)
	{
		register int x=read();
		work(x);
	}
	check(1,n,1);
	for(register int i=1;i<=n;i++)
		printf("%d ",sum(cnt[i]));
	return 0;
} 
/*
3
1 2 3
3
1 1 1
2 2
3 2 1 2
2
2 3
*/
