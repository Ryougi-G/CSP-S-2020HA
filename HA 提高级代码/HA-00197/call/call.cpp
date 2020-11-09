#include<bits/stdc++.h>
using namespace std;
const long long maxn=1100;
const long long mod=998244353;
long long n,m,q,x;
long long a[maxn]={};
struct segtree{
	long long tl[maxn<<2],tr[maxn<<2],w[maxn<<2],add[maxn<<2],mul[maxn<<2];
	void pushup(long long p){
		w[p]=w[p<<1]+w[p<<1|1];
	}
	void build(long long p,long long l,long long r){
		tl[p]=l,tr[p]=r;
		if(l==r){
			w[p]=a[l];
			return;
		}
		long long mid=(l+r)>>1;
		build(p<<1,l,mid);
		build(p<<1|1,mid+1,r);
		pushup(p);
	}
	void spread(long long p){
		if(add[p]){
			add[p<<1]+=add[p];
			add[p<<1|1]+=add[p];
			w[p<<1]+=(tr[p<<1]-tl[p<<1]+1)*add[p];
			w[p<<1|1]=(tr[p<<1|1]-tl[p<<1|1]+1)*add[p];
			add[p]=0;
		}
	}
	void change(long long p,long long l,long long r,long long v){
		if(l<=tl[p]&&tr[p]<=r){
			w[p]+=(tr[p]-tl[p]+1)*v;
			add[p]+=v;
		}
		spread(p);long long mid=(tl[p]+tr[p])>>1;
		if(l<=mid)change(p<<1,l,r,v);
		if(r>mid)change(p<<1|1,l,r,v);
		pushup(p);
	}
	long long ask(long long p,long long l,long long r){
		if(l<=tl[p]&&tr[p]<=r)return w[p];
		spread(p);long long mid=(tl[p]+tr[p])>>1,val=0;
		if(l<=mid)val+=ask(p<<1,l,r);
		if(r>mid)val+=ask(p<<1|1,l,r);
		return val;
	}
}tr;
struct segtr{
	long long tl[maxn<<2],tr[maxn<<2],w[maxn<<2],add[maxn<<2],mul[maxn<<2];
	void pushup(long long p){
		w[p]=w[p<<1]+w[p<<1|1];
	}
	void build(long long p,long long l,long long r){
		tl[p]=l,tr[p]=r;
		if(l==r){
			w[p]=a[l];
			return;
		}
		long long mid=(l+r)>>1;
		build(p<<1,l,mid);
		build(p<<1|1,mid+1,r);
		pushup(p);
	}
	void spread(long long p){
		if(mul[p]){
			mul[p<<1]+=mul[p];
			mul[p<<1|1]+=mul[p];
			w[p<<1]=w[p<<1]*mul[p];
			w[p<<1|1]=w[p<<1|1]*mul[p];
			mul[p]=0;
		}
		if(add[p]){
			add[p<<1]+=add[p];
			add[p<<1|1]+=add[p];
			w[p<<1]+=(tr[p<<1]-tl[p<<1]+1)*add[p];
			w[p<<1|1]=(tr[p<<1|1]-tl[p<<1|1]+1)*add[p];
			add[p]=0;
		}
	}
	void change(long long p,long long l,long long r,long long v){
		if(l<=tl[p]&&tr[p]<=r){
			w[p]+=(tr[p]-tl[p]+1)*v;
			add[p]+=v;
		}
		spread(p);long long mid=(tl[p]+tr[p])>>1;
		if(l<=mid)change(p<<1,l,r,v);
		if(r>mid)change(p<<1|1,l,r,v);
		pushup(p);
	}
	void mulseg(long long p,long long l,long long r,long long v){
		if(l<=tl[p]&&tr[p]<=r){
			w[p]=w[p]*v;
			mul[p]+=v;
		}
		spread(p);long long mid=(tl[p]+tr[p])>>1;
		if(l<=mid)mulseg(p<<1,l,r,v);
		if(r>mid)mulseg(p<<1|1,l,r,v);
		pushup(p);
	}
	long long ask(long long p,long long l,long long r){
		if(l<=tl[p]&&tr[p]<=r)return w[p];
		spread(p);long long mid=(tl[p]+tr[p])>>1,val=0;
		if(l<=mid)val+=ask(p<<1,l,r);
		if(r>mid)val+=ask(p<<1|1,l,r);
		return val;
	}
}tt;
struct cmd{
	long long op,n,p,v;
	long long a[maxn];
}c[maxn];
void work(long long p){
	if(c[p].op==3)for(long long i=1;i<=c[p].n;i++)work(c[p].a[i]);
	if(c[p].op==2)for(long long i=1;i<=n;i++)a[i]=(a[i]*c[p].v)%mod;
	if(c[p].op==1)a[c[p].p]=(a[c[p].p]+c[p].v)%mod;
}
int main(){
	freopen("call.in","r",stdin);freopen("call.out","w",stdout);
	scanf("%lld",&n);
	for(long long i=1;i<=n;i++)scanf("%lld",&a[i]);
	scanf("%lld",&m);
	for(long long i=1;i<=m;i++){
		scanf("%lld",&c[i].op);
		if(c[i].op==1)scanf("%lld%lld",&c[i].p,&c[i].v);
		if(c[i].op==2)scanf("%lld",&c[i].v);
		if(c[i].op==3){
			scanf("%lld",&c[i].n);
			for(long long j=1;j<=c[i].n;j++)scanf("%d",&c[i].a[j]);
		}
	}
	scanf("%lld",&q);
	for(long long i=1;i<=q;i++)scanf("%lld",&x),work(x);
	for(long long i=1;i<=n;i++)printf("%lld ",a[i]);
	return 0;
}
/*
10
1 2 3 4 5 6 7 8 9 10
8
3 2 2 3
3 2 4 5
3 2 5 8
2 2
3 2 6 7
1 2 5
1 7 6
2 3
3
1 2 3

*/
