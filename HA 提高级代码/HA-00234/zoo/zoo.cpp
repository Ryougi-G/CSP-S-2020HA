#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <map>
#include <queue>
#include <vector>
#include <string>
#define pb push_back
#define mp make_pair
#define pll pair<long long,long long>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef double db;
const int DMAX=1000000+5;
const int INF=1000000007;
const int MOD=998244353;
inline void read(ll &x){
	x=0;
	ll f=1;
	char ch=getchar();
	while(ch<'0' || ch>'9'){
		if(ch=='-'){
			f=-1;
		}
		ch=getchar();
	}
	while(ch>='0' && ch<='9'){
		x=x*10+int(ch-'0');
		ch=getchar();
	}
	x*=f;
}
ll n,m,c,k;
ll a[DMAX];
ll ans;
bool val[DMAX];
ll p[DMAX],q[DMAX];
ll qpow(ll x,ll y){
	if(y==0){
		return 1;
	}
	ll tot=1;
	while(y){
		if(y&1){
			tot=tot*x;
		}
		x=x*x;
		y>>=1;
	}
	return tot;
}
int main(){
	freopen("zoo.in","r",stdin);
	freopen("zoo.out","w",stdout);
	read(n),read(m),read(c),read(k);
	for(int i=1;i<=n;i++){
		read(a[i]);
		if(i==1){
			ans=a[i];
		}
		else{
			ans=(ans|a[i]);
		}
	}
	for(int i=1;i<=m;i++){
		read(p[i]),read(q[i]);
		val[p[i]]=1;
	}
	ll cnt=0;
	ll res=1;
	for(int i=0;i<=k-1;i++){
		if(((ans>>i)&1)==0 && val[i]){
			continue;
		}
		else{
			res*=2;
		}
	}
	printf("%lld\n",res-n);
	return 0;
}
