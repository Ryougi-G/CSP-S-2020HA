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
const int DMAX=10000+5;
const int INF=1000000007;
const ll MOD=998244353;
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
struct node{
	ll ope,x,y;
	ll c[1000+5];
};
node g[DMAX];
ll n,m;
ll a[DMAX];
ll f[DMAX];
ll q;
void doit(ll pos){
	if(g[pos].ope==1){
		a[g[pos].x]+=g[pos].y;
		a[g[pos].x]%=MOD;
	}
	if(g[pos].ope==2){
		ll val=g[pos].x;
		for(int i=1;i<=n;i++){
			a[i]=a[i]*val%MOD;
		}
	}
	if(g[pos].ope==3){
		for(int i=1;i<=g[pos].x;i++){
			doit(g[pos].c[i]);
		}
	}
}
int main(){
	freopen("call.in","r",stdin);
	freopen("call.out","w",stdout);
	read(n);
	for(int i=1;i<=n;i++){
		read(a[i]);
	}
	read(m);
	for(int i=1;i<=m;i++){
		read(g[i].ope);
		if(g[i].ope==1){
			read(g[i].x),read(g[i].y);
		}
		if(g[i].ope==2){
			read(g[i].x);
		}
		if(g[i].ope==3){
			read(g[i].x);
			for(int j=1;j<=g[i].x;j++){
				read(g[i].c[j]);
			}
		}
	}
	read(q);
	for(int i=1;i<=q;i++){
		read(f[i]);
	}
	if(n<=1000){
		for(int i=1;i<=q;i++){
			doit(f[i]);
		}
		for(int i=1;i<=n;i++){
			printf("%lld ",a[i]);
		}
	}
	return 0;
}
