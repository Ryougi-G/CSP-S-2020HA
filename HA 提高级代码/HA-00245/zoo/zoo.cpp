#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,m,c,k,all,a[10000005],en,ans;
bool vis[10000005];
struct node{
	ll p,q;
}sl[10000005];
ll read(){
	ll w=0,f=1;
	char c=getchar();
	while(c<'0'||c>'9'){
		if(c=='-')f=-f;
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		w=(w<<3)+(w<<1)+(c^48);
		c=getchar();
	}
	return w*f;
}
ll ksm(ll n,ll q){
	ll ans=1,t=n;
	while(q){
		if(q&1)ans=ans*t;
		t=t*t;
		q>>=1;
	}
	return ans;
}
bool find(ll n,ll ws){
	ll t=-1;
	char s[1000005];
	while(n>0){
		while(ksm(2,t+1)<=n)t++;
		n-=ksm(2,t);
		s[t+1]='1';
	}
	if(s[ws]=='1')return 1;
	return 0;
}
int main(){
	freopen("zoo.in","r",stdin);
	freopen("zoo.out","w",stdout);
	n=read();
	m=read();
	c=read();
	k=read();
	for(int i=1;i<=n;i++){
		a[i]=read();
		vis[a[i]]=1;
	}
	for(int i=1;i<=m;i++){
		sl[i].p=read();
		sl[i].q=read();
	}
	for(int i=1;i<=c;i++){
		for(int j=1;j<=n;j++){
		    if(find(a[j],sl[i].p)){
		    	sl[i].q=1;
		    }
    	}
	}
	en=ksm(2,k);
	for(int i=0;i<en;i++){
		if(vis[i]==1)continue;
		for(int j=1;j<=m;j++){
			if(find(i,sl[j].p)==1){
			    if(sl[j].q)ans++;
			}
		}
	}
	printf("%lld\n",ans);
	return 0;
}
