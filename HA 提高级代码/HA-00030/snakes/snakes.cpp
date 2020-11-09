#include <bits/stdc++.h>
using namespace std;
#define fo(i,a,b) for(register int i=a;i<=b;i++)
typedef long long ll;
const int maxn=1e6+5;
const int maxm=1e8+5;
ll n,m,c,k,a[maxn],q[maxn],p[maxn],f1[maxm],f2[maxm];
inline ll read(){
	bool f=0;char c=getchar();ll x=0;
	while(!isdigit(c)){
		if(c=='-') f=1;
		c=getchar();
	}
	while(isdigit(c)){
		x=(x<<1)+(x<<3)+(c^48);
		c=getchar();
	}
	return f==1?-x:x;
}
int main(){
	freopen("snakes.in","r",stdin);
	freopen("snakes.out","w",stdout);
	ll T;
	T=read();
	fo(t,1,T){
		n=read();
		ll ans=n;
		if(t==1)
		fo(i,1,n) a[i]=read();
		else 
		fo(i,1,n){
			ll x=read(),y=read();
			a[x]=y;
		} 
		int l=1,r=n;
		if(a[r]-a[l]>=a[l+1]){
			ans--;
			a[r]-=a[l];
			l++;
		}
		cout<<ans<<endl;
	}
	return 0;
}
