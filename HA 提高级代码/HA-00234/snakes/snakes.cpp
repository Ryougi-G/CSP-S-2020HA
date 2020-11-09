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
const int DMAX=100000+5;
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
ll T;
ll n;
ll a[DMAX];
struct node{
	ll val,pos;
	bool operator <(const node &p) const{
		if(val==p.val){
			return pos>p.pos;
		}
		return val>p.val;
	}
};
node g[DMAX];
ll kase=0;
ll pol;
int main(){
	freopen("snakes.in","r",stdin);
	freopen("snakes.out","w",stdout);
	read(T);
	while(T--){
		kase++;
		read(n);
		if(kase==1){
			pol=n;
		}
		if(kase==1){
			for(int i=1;i<=n;i++){
				read(a[i]);
			}
		}
		else{
			ll x,y;
			for(int i=1;i<=n;i++){
				read(x),read(y);
				a[x]=y;
			}
		}
		for(int i=1;i<=pol;i++){
			g[i].val=a[i];
			g[i].pos=i;
		}
		ll len=pol;
		ll ans=pol;
		while(len>=2){
			sort(g+1,g+len+1);
			node r;
			r.val=g[1].val-g[len].val;
			r.pos=g[1].pos;
			if(g[len-1]<r){
				if(len==2){
					ans--;
				}
				break;
			}
			else{
				g[1]=r;
				len--;
				ans--;
			}
		}
		printf("%lld\n",ans);
	}
	return 0;
}
