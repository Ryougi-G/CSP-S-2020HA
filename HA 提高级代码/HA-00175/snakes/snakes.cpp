#include<bits/stdc++.h>
#define rint register int
#define N 1000005
#define UL  long long
inline int read(){
	int f=1,x=0;char c=getchar();
	while(c<'0'||c>'9'){
		if(c=='-') f=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		x=x*10+c-'0';
		c=getchar();
	}
	return x*f;
}
struct edge{
	int id,num;
}a[10];
int t,n,x1,x2,k,b[10],ans;
void pai(){
	int maxx=-1,minn=1e9,j1=0,j2=0;
	for(int i=1;i<=3;i++){
		if(a[i].num>maxx){
			maxx=a[i].num;j1=i;
		}
		if(a[i].num<minn){
			minn=a[i].num,j2=i;
		}
	}
	a[1].id=j1;
	a[2].id=6-j1-j2;
	a[3].id=j2;
	a[1].num=maxx;
	a[3].num=minn,a[2].num=b[6-j1-j2];
}
bool cmp(edge x,edge b){
	if(x.num==b.num){
	return x.id>b.id;}
	else{
		return x.num>b.num;
	}
}
void solve(){
	if(a[1].num>=a[2].num+a[3].num){
		ans=1;return ;
	}
	else if(a[1].num-a[3].num<a[2].num){
		ans=3; return ;
	}
}
int main(){
	freopen("snakes.in","r",stdin);
	freopen("snakes.out","w",stdout);
	t=read();
	n=read();
		for(int i=1;i<=n;i++){
			a[i].num=read();
			a[i].id=i;
			b[i]=a[i].num;
		}pai();
		solve();
		printf("%d\n",ans);
	for(int i=2;i<=t;i++){
		for(int i=1;i<=n;i++){
			a[i].num=b[i];
			a[i].id=i;
		}
		k=read();
		for(int j=1;j<=k;j++){
			x1=read();x2=read();
			a[x1].num=x2;
		}pai();
		solve();
		printf("%d\n",ans);
	}
	return 0;
}
