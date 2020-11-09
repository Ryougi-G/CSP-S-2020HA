//好多分的贪心 
#include<cmath>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
typedef long long ll;
const int MAXN=2005;
ll a[MAXN];
int n;
int main(){
	freopen("snakes.in","r",stdin);
	freopen("snakes.out","w",stdout);
	int T;
	scanf("%d",&T);
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	int ans=n,len=1;
	long long maxn=a[n]-a[len];
	while(maxn>=a[len+1]){
		a[n]=maxn;
		len++;
		ans--;
		maxn=a[n]-a[len];
	}
	printf("%d\n",ans);
	T--;
	while(T--){
		int k;
		scanf("%d",&k);
		for(int i=1;i<=k;i++){
			int aa;
			scanf("%d",&aa);
			scanf("%lld",&a[aa]);
		}
		ans=n-len+1;
		long long maxn=a[n]-a[len];
		while(maxn>=a[len+1]&&ans>1){
			a[n]=maxn;
			len++;
			ans--;
			maxn=a[n]-a[len];
		}
		printf("%d\n",ans);
	}
	return 0;
}
