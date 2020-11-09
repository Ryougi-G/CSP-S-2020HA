#include<bits/stdc++.h>
#define maxn 1000006
using namespace std;
int n,m,c,k,a[maxn],ol,cent,cnt;
unsigned long long mx,fx,ans=1;
struct node{
	int l,r;
}tr[maxn*20];

struct nod{
	int l,r;
}tr1[maxn*20];

template<typename type_of_scan>
void scan(type_of_scan &x){
	type_of_scan f=1;char s=getchar();x=0;
	while(s<'0'||s>'9'){if(s=='-')f=-1;s=getchar();}
	while(s>='0'&&s<='9'){x=x*10+s-'0';s=getchar();}
	x*=f;
}

int vis(int x){
	int root=0;
	for(int i=1;i<=28;i++){
		if(x&1){
			if(!tr[root].l) return 0;
			root=tr[root].l;
		}else {
			if(!tr[root].r) return 0;
			root=tr[root].r;
		}
		x>>=1;
	} 
	return 1;
}

int vis1(int x){
	int root=0;
	for(int i=1;i<=28;i++){
		if(x&1){
			if(!tr1[root].l) return 0;
			root=tr1[root].l;
		}else {
			if(!tr1[root].r) return 0;
			root=tr1[root].r;
		}
		x>>=1;
	} 
	return 1;
}

void add(int x){
	int root=0;
	for(int i=1;i<=28;i++){
		if(x&1){
			if(!tr[root].l) tr[root].l=++cent;
			root=tr[root].l;
		}else {
			if(!tr[root].r) tr[root].r=++cent;
			root=tr[root].r;
		}
		x>>=1;
	}
}

void add1(int x){
	int root=0;
	for(int i=1;i<=28;i++){
		if(x&1){
			if(!tr1[root].l) tr1[root].l=++cnt;
			root=tr1[root].l;
		}else {
			if(!tr1[root].r) tr1[root].r=++cnt;
			root=tr1[root].r;
		}
		x>>=1;
	}
}

int main(){
	freopen("zoo.in","r",stdin);
	freopen("zoo.out","w",stdout);
	scan(n),scan(m),scan(c),scan(k);
	for(int i=1;i<=n;i++){
		scan(a[i]);mx|=a[i];
	}
	for(int i=1,p,q;i<=m;i++){
		scan(p),scan(q);fx=0;
		fx=(1<<p);
		if((fx&mx)||vis(q)){
			add(q);continue;
		}
		if(!vis1(p)) ol++,add1(p);
	}
	ol=k-ol;ans<<=ol;
	if(ans<=n) printf("0\n");
	else printf("%u\n",ans-n);
}
