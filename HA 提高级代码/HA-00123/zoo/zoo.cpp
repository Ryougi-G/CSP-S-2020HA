#include<bits/stdc++.h>
using namespace std;
const int maxa=1005000;
int a[maxa];
int n,m,c,k;
int x,y;
bool ej[70],nbn[70];
int ans;
int s,j;
int num;

int main(){
	freopen("zoo.in","r",stdin);
	freopen("zoo.out","w",stdout);
	scanf("%d%d%d%d",&n,&m,&c,&k);
	
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		s=a[i];
		j=0;
		while(s){
			ej[j]=((s%2)|ej[j]);
			j++;
			s>>=1;
		}
	}
	for(int i=1;i<=m;i++){
		scanf("%d%d",&x,&y);
		if(!ej[x])
			nbn[x]=1;
	}
		
		
	for(int i=0;i<=k;i++){
		if(nbn[i])
			num++;
	}
	ans=(1<<(k-num))-n;
	printf("%d",ans);
	return 0;
}


