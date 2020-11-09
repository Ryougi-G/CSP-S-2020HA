#include<bits/stdc++.h>
using namespace std;
int a[10005],b[10005];
int T,n,k;
int main(){
	freopen("snakes.in","r",stdin);freopen("snakes.out","w",stdout);
	scanf("%d",&T);scanf("%d",&n);
	int TT=T;
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	while(T--){
		if(T!=TT){
			scanf("%d",&k);
			for(int i=1,x,y;i<=k;i++){
				scanf("%d%d",&x,&y);
				a[x]=y;
			}
		}
		for(int i=1;i<=3;i++){
			b[i]=a[i];
		}
		if(b[3]-b[1]<b[2]) printf("3\n");
		else printf("1\n");
	}
	fclose(stdin);fclose(stdout);
	return 0;
}
