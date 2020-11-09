#include<bits/stdc++.h>
using namespace std;
#define N 100005
#define mod 998244353
#define LL long long
LL n,m,s[N];
struct cao{
	int t,a,b;
}hh[N];
struct node{
	LL l,r,sum,lz;
}t[N<<2];
LL read(){
	LL w=0,f=1;
	char c=getchar();
	while (c>'9'||c<'0'){
		if (c=='-') f=-1;
		c=getchar();
	}
	while (c>='0'&&c<='9'){
		w=(w<<3)+(w<<1)+(c^48);
		c=getchar();
	}
	return w*f;
}
void update(int i){
	t[i].sum=(t[i<<1].sum+t[i<<1|1].sum)%mod;
}
void build(int i,int l,int r){
	t[i].l=l,t[i].r=r,t[i].lz=1;
	if (l==r){
		t[i].sum=s[l];
		return;
	}
	int mid=l+r>>1;
	build(i<<1,l,mid);
	build(i<<1|1,mid+1,r);
	update(i);
}
void pushdown(int i){
	if (t[i].lz!=1){
		t[i<<1].sum=(t[i<<1].sum*t[i].lz)%mod;
		t[i<<1|1].sum=(t[i<<1|1].sum*t[i].lz)%mod;
		t[i<<1].lz=(t[i<<1].lz*t[i].lz)%mod;
		t[i<<1|1].lz=(t[i<<1|1].lz*t[i].lz)%mod;
		t[i].lz=1;
	}
}
void add(int i,int dis,LL w){
	if (t[i].l==t[i].r){
		t[i].sum+=w;
		return;
	}
	pushdown(i);
	if (t[i<<1].r>=dis) add(i<<1,dis,w);
	else add(i<<1|1,dis,w);
	update(i);
}
void acc(int i,int l,int r,LL k){
	if (t[i].l>=l&&t[i].r<=r){
		t[i].lz=t[i].lz*k%mod;
		t[i].sum=t[i].sum*k%mod;
		return;
	}
	pushdown(i);
	if (t[i<<1].r>=l) acc(i<<1,l,r,k);
	if (t[i<<1|1].l<=r) acc(i<<1|1,l,r,k);
	update(i);
}
LL search(int i,int dis){
	if (t[i].l==t[i].r){
		return t[i].sum;
	}
	pushdown(i);
	if (t[i<<1].r>=dis) return search(i<<1,dis);
	else return search(i<<1|1,dis);
}
int main(){
	freopen("call.in","r",stdin);
	freopen("call.out","w",stdout);
	n=read();
	for (int i=1;i<=n;i++) s[i]=read();
	build(1,1,n);
	m=read();
	for (int i=1;i<=m;i++){
		hh[i].t=read();
		if (hh[i].t==1){
			hh[i].a=read(),hh[i].b=read();	
		}else if (hh[i].t==2) hh[i].a=read();
	}
	int q=read();
	for (int i=1;i<=q;i++){
		int x=read();
		if (hh[x].t==1){
			add(1,hh[x].a,hh[x].b);
		}
		else if (hh[x].t==2){
			acc(1,1,n,hh[x].a);
		}
	}
	for (int i=1;i<=n;i++){
		printf("%lld ",search(1,i));
	}
	return 0;
}
