#include <bits/stdc++.h>
using namespace std;
int T,n,k,xx,yy,cnt,temp;
struct Node{
	int x,y;
};
Node a[100005],b[100005];
bool cmp(Node aa,Node bb){
	if(aa.x<bb.x||(aa.x==bb.x&&aa.y<bb.y)) return true;
	else return false;
}
void start(){
	for(int i=1;i<=n;i++){
		a[i].x=b[i].x;a[i].y=b[i].y;
	}
	while(!temp){
		sort(a+cnt,a+n+1,cmp);
		if((a[n].x-a[cnt].x>a[cnt+1].x&&n-cnt>1)||(a[n].x-a[cnt].x==a[cnt+1].x&&n-cnt>1&&a[n].y>a[cnt+1].y)
	    ||(n-cnt==1&&a[n].x>a[cnt].x)||(n-cnt==1&&a[n].x==a[cnt].x&&a[n].y>a[cnt].y)){
			a[n].x-=a[cnt].x;cnt++;
		} 
		else temp=1;
		if(n==cnt) temp=1;
	}
	printf("%d\n",n-cnt+1);
}
int main(){
	freopen("snakes.in","r",stdin);
	freopen("snakes.out","w",stdout);
	scanf("%d",&T);T--;
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&b[i].x);b[i].y=i;
	} 
	temp=0;cnt=1;
	start();
	while(T--){
		scanf("%d",&k);
		for(int i=1;i<=k;i++){
			scanf("%d%d",&xx,&yy);b[xx].x=yy;
		}
		temp=0;cnt=1;
		start();
	}
	return 0;
}

