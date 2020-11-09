#include<bits/stdc++.h>
using namespace std;
#define N 1000005
#define C 100000005
#define LL long long
#define K 70
LL n,m,c,k,a[N],all,p[N],q[N],lsh[N];
bool al[N],cao[C],vis[K];
LL read(){
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
void work(LL x,LL c){
	if (!x) return;
	work(x/2,c+1);
	if (x%2) al[c]=1;
}
LL ksm(LL x,LL y){
	LL ans=1,cnt=x;
	while (y){
		if (y%2==1) ans*=cnt;
		y>>=1;
		cnt*=cnt;
	}
	return ans;
}
int main(){
	freopen("zoo.in","r",stdin);
	freopen("zoo.out","w",stdout);
	n=read(),m=read(),c=read(),k=read();
	for (int i=1;i<=n;i++) a[i]=read(),all|=a[i];
	work(all,0);
	for (int i=1;i<=m;i++){
		p[i]=read(),q[i]=lsh[i]=read();
	}
	for (int i=1;i<=m;i++){
		if (al[p[i]]) cao[q[i]]=1;
	}
	for (int i=1;i<=m;i++){
		if (!cao[q[i]]&&!vis[p[i]]) --k,vis[p[i]]=1;
	}
	printf("%lld\n",ksm(2,k)-n);
	return 0;
}
