#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N=1e5+10,C=1e6+10,P=998244353;
ll n,m,q;
ll a[N];
ll typ[N],p[N],v[N];
int hd[N],nxt[C],to[C],cnt=0;
ll lzy[N<<2];
int t[C];
ll rd(){
	ll f=1,x=0;
	char c=getchar();
	for(;c<'0'||c>'9';c=getchar())if(c=='-')f=-1;
	for(;c>='0'&&c<='9';c=getchar())x=(x<<3)+(x<<1)+c-'0';
	return f*x;
}
void addfct(int u,int t){
	cnt++;
	to[cnt]=t;
	nxt[cnt]=hd[u];
	hd[u]=cnt;
	return;
}
void build(int i,int l,int r){
	lzy[i]=1;
	if(l==r)
		return;
	int mid=l+r>>1;
	build(i<<1,l,mid);
	build(i<<1|1,mid+1,r);
	return;
}
void pushdown(int i){
	lzy[i<<1]=lzy[i<<1]*lzy[i]%P;
	lzy[i<<1|1]=lzy[i<<1|1]*lzy[i]%P;
	lzy[i]=1;
	return;
}
void change(int i,int l,int r,int ic,ll vc){
	if(l==r){
		a[l]=(a[l]*lzy[i]%P+vc)%P;
		lzy[i]=1;
		return;
	}
	pushdown(i);
	int mid=l+r>>1;
	if(ic<=mid)
		change(i<<1,l,mid,ic,vc);
	else
		change(i<<1|1,mid+1,r,ic,vc);
	return;
}
void callfct(int fop){
	if(typ[fop]==1)
		change(1,1,n,p[fop],v[fop]);
	else if(typ[fop]==2)
		lzy[1]=lzy[1]*v[fop]%P;
	else
		for(int i=hd[fop];i;i=nxt[i])
			callfct(to[i]);
	return;
}
void query(int i,int l,int r){
	if(l==r){
		a[l]=a[l]*lzy[i]%P;
		printf("%d ",a[l]);
		return;
	}
	pushdown(i);
	int mid=l+r>>1;
	query(i<<1,l,mid);
	query(i<<1|1,mid+1,r);
	return;
}
int main(){
	freopen("call.in","r",stdin);
	freopen("call.out","w",stdout);
	n=rd();
	for(int i=1;i<=n;i++)
		a[i]=rd();
	m=rd();
	for(int i=1;i<=m;i++){
		typ[i]=rd();
		if(typ[i]==1)
			p[i]=rd(),v[i]=rd();
		else if(typ[i]==2)
			v[i]=rd();
		else{
			int tmp=rd();
			for(int j=tmp;j;j--)
				t[j]=rd();
			for(int j=1;j<=tmp;j++)
				addfct(i,t[j]);
		}
	}
	build(1,1,n);
	q=rd();
	while(q--){
		int fop=rd();
		callfct(fop);
	}
	query(1,1,n);
	return 0;
}
