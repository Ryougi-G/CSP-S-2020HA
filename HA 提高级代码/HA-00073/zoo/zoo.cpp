// 1&(n>>i):判断n(2)的第i位是不是1 
#include<cmath>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
const int MAXN=25;
int n,m,c,k;
long long ans;
bool can[1<<MAXN+1];
bool have[MAXN];
int old[MAXN],p[MAXN],q[MAXN];
int main(){
	freopen("zoo.in","r",stdin);
	freopen("zoo.out","w",stdout);
	scanf("%d%d%d%d",&n,&m,&c,&k);
	for(int i=1;i<=n;i++){
		scanf("%d",&old[i]);
	}
	for(int i=1;i<=m;i++){
		scanf("%d%d",&p[i],&q[i]);
		for(int j=1;j<=n;j++){
			if(1&(old[j]>>p[i])){
				have[i]=1;
			}
		}
	}
	for(int i=1;i<=m;i++){
		if(!have[i])continue;
		for(int j=0;j<(1<<k);j++){
			if(1&(j>>p[i]))can[j]=1;
		}
	}
	for(int i=0;i<(1<<k);i++){
		ans+=can[i];
	}
	printf("%lld",ans-n);
	return 0;
}
/*
位运算：
	&运算：
       0&0=0
       0&1=0
       1&0=0
       1&1=1
	|运算：
       0|0=0
       0|1=1
       1|0=1
       1|1=1
	^运算：
       0^0=0
       0^1=1
       1^0=1
       1^1=0
	!运算：
       !0=1
       !1=0
*/
