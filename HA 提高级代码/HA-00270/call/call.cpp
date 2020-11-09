#include<cstdio>
#include<iostream>
using namespace std;

struct fun{
	int n,p,v;
	int ff[2000];
}f[200000];

unsigned long long a[200000];
int n,m;
int t1,t2;


void doin(int x){
	for(int i = 1;i<=f[x].p;i++){
		if(f[f[x].ff[i]].n==1){
			a[f[f[x].ff[i]].p]+=f[f[x].ff[i]].v;
		}
		else if(f[f[x].ff[i]].n==2){
			for(int j =1;j<=n;j++){
				a[j]*=f[f[x].ff[i]].v;
			}
		}
		else{
			doin(f[x].ff[i]);
		}
	}
}

int main(){
	freopen("call.in","r",stdin);
	freopen("call.out","w",stdout);
	scanf("%d",&n);
	for(int i = 1;i<=n;i++){
		scanf("%lld",&a[i]);
	}
	scanf("%d",&m);
	for(int i = 1;i<=m;i++){
		scanf("%d",&t1);
		if(t1==1){
			f[i].n=1;
			scanf("%d%d",&f[i].p,&f[i].v);
		}
		else if(t1==2){
			f[i].n=2;
			scanf("%d",&f[i].v);
		}
		else if(t1==3){
			f[i].n=3;
			scanf("%d",&f[i].p);
			for(int j = 1;j<=f[i].p;j++){
				scanf("%d",&f[i].ff[j]);
			}
		}
	}
	scanf("%d",&f[0].p);
	for(int i = 1;i<=f[0].p;i++){
		scanf("%d",&f[0].ff[i]);
	}
	doin(0);
	for(int i = 1;i<=n;i++){
		printf("%lld ",a[i]%998244353);
	}
}
