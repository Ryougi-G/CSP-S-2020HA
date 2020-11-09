#include<bits/stdc++.h>
using namespace std;
#define N 100005
#define LL long long
LL n,now=-4713,nowd,day[13]={0,31,59,90,120,151,181,212,243,273,304,334,365};
struct node{
	LL d,m,y;
	bool f;
	node (LL y=0,LL m=0,LL d=0,bool f=0)
		:y(y),m(m),d(d),f(f){}
}ans[N];
struct node1{
	LL id,w;
	node1 (LL id=0,LL w=0)
		:id(id),w(w){}
	bool operator <(const node1 &a) const {
		return w<a.w;
	}
}r[N];
inline LL read(){
	LL w=0,f=1;
	char c=getchar();
	while (c>'9'||c<'0'){
		if (c=='-') f=-1;
		c=getchar();
	}
	while (c>='0'&&c<='9'){
		w=(w<<3)+(w<<1)+(c^48);
		c=getchar();
	}
	return w*f;
}
inline cl1(LL x){
	if (x==1582) return 355;
	if (x<0) return abs(x)%4==1?366:365;
	else if (x>0&&x<=1582) return x%4==0?366:365;
	return x%4==0?(x%100!=0||x%400==0?366:365):365; 
}
inline int cl2(LL id,LL x){
	if (id>=2){
		if (now<0&&abs(now)%4==1) ++x;
		else if (now>0&&now<=1582&&now%4==0) ++x; 
		else if (now>1582&&(now%4==0&&now%100!=0||now%400==0)) ++x;
	}
	if (id>=10&&now==1582){
		x-=10;
	}
	return x;
}
inline int cl3(LL y,LL w){
	if (now==1582&&y>=9&&w>4) return w+10;
	return w;
}
int main(){
	freopen("julian.in","r",stdin);
	freopen("julian.out","w",stdout);
	n=read();
	for (int i=1;i<=n;i++) r[i]=node1(i,read());
	sort(r+1,r+1+n);
	for (int i=1;i<=n;i++){
		while (r[i].w>=cl1(now)+nowd){
			nowd+=cl1(now),++now;
			if (now==0) ++now;
		}
		for (int j=11;j>=0;j--){
			if (r[i].w>=nowd+cl2(j,day[j])){
				ans[r[i].id]=node(abs(now),j+1,cl3(j,r[i].w-nowd-cl2(j,day[j])+1),now<0?1:0);
				break;
			}
		}
	}
	for (int i=1;i<=n;i++){
		printf("%lld %lld %lld ",ans[i].d,ans[i].m,ans[i].y);
		if (ans[i].f) puts("BC");
		else puts("");
	}
	return 0;
}
