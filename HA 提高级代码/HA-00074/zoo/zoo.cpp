#include<bits/stdc++.h>
#define maxn 1005
using namespace std;
struct Node{
	long long p[maxn];
	int tot;
} v[maxn];
long long a[maxn],c;
int n,m,k;
long long ans=1;
long long vis[1292140];
int Hash(long long num){
	return ((num%7291387)*7)%1292137;
}
int main()
{
	freopen("zoo.in","r",stdin);
	freopen("zoo.out","w",stdout);
	scanf("%d%d%lld%d",&n,&m,&c,&k);
	for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
	int x;long long y;
	for(int i=1;i<=m;i++){
		scanf("%d%lld",&x,&y);
		y=Hash(y);
		v[x].tot++;v[x].p[v[x].tot]=y;
	}
	for(int i=1;i<=n;i++){
		long long no=a[i];int j=0;
		while(no){
			if(no%2!=0){
				for(int k1=1;k1<=v[j].tot;k1++){
					vis[Hash(v[j].p[k1])]=1;
				}
			}
			no=no>>1;
			j++;
		}
	}
	for(int i=0;i<k;i++){
		int pd=1;
		for(int j=1;j<=v[i].tot;j++){
			if( !vis[ Hash(v[i].p[j]) ] ){
				pd=0;break;
			}
		}
		if(pd==1) ans*=2;
	}
	ans-=n;
	cout<<ans;
}
/*
3 3 5 4
1 4 6
0 3
2 4
2 5
---------------
2 2 4 3
1 2
1 3
2 4
*/
