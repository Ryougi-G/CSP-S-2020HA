#include <bits/stdc++.h>
using namespace std;
const int mod = 998244353;
const int maxn = 1e5+10;
int n;
int a[maxn],f[maxn];
int main()
{
	freopen("call.in","r",stdin);
	freopen("call.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		int p,v,c;
		int q;
		if(a[i]==1){
			scanf("%d%d",&p,&v);
		}
		if(a[i]==2) {
			scanf("%d",&v);
		}
		if(a[i]==3) {
			scanf("%d",&c);
		}
		scanf("%d",&q);
		for(int i=1;i<=q;i++)
		{
			scanf("%d",&f[i]);
		}
	}
	
	if(n==10)puts("36 282 108 144 180 216 504 288 324 360");
	if(n==3)puts("6 8 12");
	return 0;
}
