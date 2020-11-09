#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[10005];
int cz[10005][3];
int dy[1005][1005],top=0;
int q;
int jcq=1;
void zx(int x){
	if(cz[x][0]==1){
		if(jcq!=1){
			for(int i=1;i<=m;i++){
				a[i]*=jcq;
			}
			jcq=1;
		}
		 a[cz[x][1]]+=cz[x][2];
	}
	else if(cz[x][0]==2){
		jcq*=cz[x][1];
	}
	else {
		int i=1;
		while(dy[cz[x][2]][i]!=0){
			zx(dy[cz[x][2]][i]);i++;
		}
	}
}
int main(){
	freopen("call.in","r",stdin);
	freopen("call.out","w",stdout);
	int aa;
	memset(dy,0,sizeof(dy));
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	scanf("%d",&m);
	for(int i=1;i<=m;i++){
		scanf("%d",&cz[i][0]);
		if(cz[i][0]==1){
			scanf("%d%d",&cz[i][1],&cz[i][2]);
		}
		else {
			scanf("%d",&cz[i][1]);
			if(cz[i][0]==3){
			//scanf("%d",cz[i][2]);
			top++;
			for(int j=1;j<=cz[i][1];j++){
				scanf("%d",&dy[top][j]);
			}
			cz[i][2]=top;}
		}
	}
	scanf("%d",&q);
	for(int i=1;i<=q;i++){
		scanf("%d",&aa);
		zx(aa);
	}
	for(int i=1;i<=n;i++){
		printf("%d ",a[i]*jcq);
	}
	cout<<endl;
}
