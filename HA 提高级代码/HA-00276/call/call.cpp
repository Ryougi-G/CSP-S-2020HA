#include <bits/stdc++.h>
#define rint register int
#define ll long long
using namespace std;
const int maxn=1e5+10;
const int modo=998244353;
int n,m,a[maxn];
ll tag[maxn<<4];
ll tree[maxn<<4];
struct FUNCTION
{
	int type;
	int p,v;
	int c;
	vector<int> g;
}f[maxn];


void pushdown(int o,int l,int r)
{
	tag[o]%=modo;
	tag[o<<1]=((tag[o<<1]%modo)*tag[o])%modo;
	tag[o<<1|1]=((tag[o<<1|1]%modo)*tag[o])%modo;
	tag[o]=1;
}
void modify_add(int o,int l,int r,int s,int v)
{
	if(l==r)
	{
		tag[o]%=modo;
		tree[o]%=modo;
		tree[o]=(tree[o]*tag[o])%modo;
		tree[o]=(tree[o]+v)%modo;
		tag[o]=1;
		return;
	}
	int mid=(l+r)>>1;
	pushdown(o,l,r);
	if(s<=mid)
		modify_add(o<<1,l,mid,s,v);
	else
		modify_add(o<<1|1,mid+1,r,s,v);
}
void modify_mul(int v)
{
	tag[1]%=modo;
	tag[1]=(tag[1]*v)%modo;
}
void build(int o,int l,int r)
{
	if(l==r)
	{
		tree[o]=a[l]%modo;
		return;
	}
	int mid=(l+r)>>1;
	build(o<<1,l,mid);
	build(o<<1|1,mid+1,r);
}
ll query(int o,int l,int r,int q)
{
	if(l==r)
	{
		tree[o]%=modo;
		tag[o]%=modo;
		tree[o]=(tree[o]*tag[o])%modo;
		tag[o]=1;
		return tree[o]%modo;
	}
	pushdown(o,l,r);
	int mid=(l+r)>>1;
	if(q<=mid)
		return query(o<<1,l,mid,q);
	else
		return query(o<<1|1,mid+1,r,q);
}
void ccall(int x)
{
	if(f[x].type==1)
		modify_add(1,1,n,f[x].p,f[x].v%modo);
	if(f[x].type==2)
			modify_mul(f[x].v%modo);
	if(f[x].type==3)
		for(rint i=0;i<f[x].c;i++)
			ccall(f[x].g[i]);
}
int main()
{
//	freopen("D:\\csp lemon\\data\\call\\call3.in","r",stdin);
//	freopen("ans.txt","w",stdout);
	freopen("call.in","r",stdin);
	freopen("call.out","w",stdout);
	scanf("%d",&n);
	for(rint i=1;i<=n*16;i++)
		tag[i]=1;
	for(rint i=1;i<=n;i++)
		scanf("%d",&a[i]);
	scanf("%d",&m);
	for(rint i=1;i<=m;i++)
	{
		int t;
		scanf("%d",&t);
		if(t==1)
		{
			int pp,vv;
			scanf("%d%d",&pp,&vv);
			f[i].type=1;
			f[i].p=pp;
			f[i].v=vv;
		}
		if(t==2)
		{
			int vv;
			scanf("%d",&vv);
			f[i].type=2;
			f[i].v=vv;
		}
		if(t==3)
		{
			f[i].type=3;
			int c;
			scanf("%d",&c);
			f[i].c=c;
			while(c--)
			{
				int x;
				scanf("%d",&x);
				f[i].g.push_back(x);
			}
		}
	}
	build(1,1,n);
	int q;
	scanf("%d",&q);
	while(q--)
	{
		int x;
		scanf("%d",&x);
		ccall(x);
	}
	for(rint i=1;i<=n;i++)
		printf("%lld ",query(1,1,n,i)%modo);
	return 0;
}
