#include<bits/stdc++.h>
#define S 2000005
using namespace std;
bool flag,vis[S],v[S];
int n,m,c,k;
int a[S],bit[S],b[S];
int ans;
int main(){
	freopen("zoo.in","r",stdin);freopen("zoo.out","w",stdout);
	scanf("%d%d%d%d",&n,&m,&c,&k);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]),vis[a[i]]=1;
	for(int i=1;i<=m;i++){
		scanf("%d%d",&bit[i],&b[i]);
		for(int j=1;j<=n;j++){
			int op=(a[j]>>bit[i])&1;
			if(op==1){
				v[b[i]]=1;//biaoji
				break;
			}
		}
	}
	for(int j=1;j<=m;j++){
		if(v[b[j]]) continue;
		for(int i=0;i<=(1<<k)-1;i++){//¿¼ÂÇv=0
			if(vis[i]) continue;
			if(i>>bit[j]&1) vis[i]=1;
		}
	}
	for(int i=0;i<=(1<<k)-1;i++){
		if(!vis[i]) ans++;
	}
	printf("%d",ans);
	fclose(stdin);fclose(stdout);
	return 0;
}
