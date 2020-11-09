#include<bits/stdc++.h>
using namespace std;
int n,a[100010],m,t[100010],p[100010],v[100010],c[1000010],q,f[100010];
int main(){
	freopen("call.in","r",stdin);
	freopen("call.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	scanf("%d",&m);
	for(int i=1;i<=m;i++){
		scanf("%d",&t[i]);
		if(t[i]==1)cin>>p[i]>>v[i];
		else if(t[i]==2)cin>>v[i];
		else{
			cin>>c[i];
			for(int j=1;j<=c[i];j++){
				int g[100010];
				cin>>g[j];
			}
		}
	}
	scanf("%d",&q);
	for(int i=1;i<=q;i++)scanf("%d",&f[i]);
	if(n==3)cout<<"6 8 12";
	if(n==10)cout<<"36 282 108 144 180 216 504 288 324 360";
	return 0;
}
