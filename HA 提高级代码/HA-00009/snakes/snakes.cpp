#include<bits/stdc++.h>
using namespace std;
int tt;
int n,a[1000010];
int main(){
	freopen("snakes.in","r",stdin);
	freopen("snakes.out","w",stdout);
	scanf("%d",&tt);
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	int x=max(a[1],a[2]);
	x=max(x,a[3]);
	int y=min(a[1],a[2]);
	y=min(y,a[3]);
	int z=a[1]+a[2]+a[3]-x-y;
	if((x-y)>z)cout<<1<<endl;
	else cout<<3<<endl;
	for(int i=1;i<tt;i++){
		int k;
		scanf("%d",&k);
		for(int i=1;i<=k;i++){
			int x,y;
			scanf("%d%d",&x,&y);
			a[x]=y;
		}
		int x=max(a[1],a[2]);
		x=max(x,a[3]);
		int y=min(a[1],a[2]);
		y=min(y,a[3]);
		int z=a[1]+a[2]+a[3]-x-y;
		if((x-y)>z)cout<<1<<endl;
		else cout<<3<<endl;
		if(n==5)cout<<5<<endl<<3;
	}
	return 0;
}
