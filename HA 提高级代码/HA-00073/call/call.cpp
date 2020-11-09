#include<cmath>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
typedef long long ll;
const int MAXN=5005;
const ll mod=998244353;
int a[MAXN];
struct note{
	int num;
	int biao;
	ll add;
	ll che;
	int len;
	int xu[MAXN];
}in[MAXN];
int n,m,q;
inline void work(int now){
	if(in[now].num==1){
		a[in[now].biao]+=in[now].add;
	}else if(in[now].num==2){
		for(int i=1;i<=n;i++)a[i]=a[i]*in[now].che%mod;
	}
	else{
		for(int i=1;i<=in[now].len;i++)work(in[now].xu[i]);
	}
}
int main(){
	//freopen("call.in","r",stdin);
	//freopen("call.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%lld",&a[i]);
	scanf("%d",&m);
	for(int i=1;i<=m;i++){
		scanf("%d",&in[i].num);
		if(in[i].num==1){
			scanf("%d%lld",&in[i].biao,&in[i].add);
		}
		else if(in[i].num==2){
			scanf("%lld",&in[i].che);
		}
		else{
			scanf("%d",&in[i].len);
			for(int j=1;j<=in[i].len;j++)scanf("%d",&in[i].xu[j]);
		}
	}
	scanf("%d",&q);
	for(int i=1;i<=q;i++){
		int now;
		scanf("%d",&now);
		work(now);
	}
	for(int i=1;i<=n;i++)
		printf("%lld ",a[i]%mod);
	return 0;
}
