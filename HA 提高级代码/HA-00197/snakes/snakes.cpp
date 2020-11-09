#include<bits/stdc++.h>
using namespace std;
int n,k,t;
int x,y; 
int a[10]={};
int b[10]={};
int work(){
//	printf("[%d %d %d]\n",b[1],b[2],b[3]);
	if(b[3]>=b[1]+b[2])return 1;
	if(b[3]-b[1]<b[2])return 3;
}
int main(){
	freopen("snakes.in","r",stdin);freopen("snakes.out","w",stdout);
	scanf("%d%d",&t,&n);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	for(int tt=1;tt<=t;tt++){
		if(tt==1){
			for(int i=1;i<=n;i++)b[i]=a[i];sort(b+1,b+1+n);
		}
		else{
			scanf("%d",&k);
			for(int i=1;i<=k;i++)scanf("%d%d",&x,&y),a[x]=y;
			for(int i=1;i<=n;i++)b[i]=a[i];sort(b+1,b+1+n);		
		}
		printf("%d\n",work());
	}
	return 0;
}
