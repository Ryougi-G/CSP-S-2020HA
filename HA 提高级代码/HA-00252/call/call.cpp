#include <bits/stdc++.h>
#define deb if(debug)
#define int long long
const int debug =0;
#define fo(i,x) for(int i=1;i<=(x);++i)
#define fo_(i,b,x) for(int i = b;i<=x;++i)
#define re(i,b,x) for(int i = b;i>=x;--i)
#define N 100010
#define mod 998244353
#define ull unsigned long long
int n,m,Q;
using namespace std;
int a[N];
int num[N];
struct Func{
	int type;
	int pj,vj;
	vector<int > fun;
}f[N];
void doit(Func fu){
	if(fu.type==1){
		deb printf("Add\n");
		a[fu.pj] = (a[fu.pj]%mod+fu.vj%mod)%mod;
	}else if(fu.type==2){
		deb printf("mul\n");
		for(int i = 1;i<=n;i++){
			a[i] = (a[i]%mod * fu.vj%mod ) %mod;
		}
	}else if(fu.type==3){
		deb printf("redo\n");
		int s = fu.fun.size();
		for(int i = 0;i<s;i++){
			doit(f[fu.fun[i]]);
		}
	}
}
signed main(){
	freopen("call.in","r",stdin);
	freopen("call.out","w",stdout);
	cin>>n;
	fo(i,n) cin>>a[i];
	cin>>m;
	fo(i,m){
		cin>>f[i].type;
		if(f[i].type==1){
			cin>>f[i].pj>>f[i].vj;
		}else if(f[i].type==2){
			cin>>f[i].vj;
		}else if(f[i].type==3){
			int cj;cin>>cj;
			fo(l,cj){
				int tm;cin>>tm;
				f[i].fun.push_back(tm);
			}
		}
	}
	cin>>Q;
	for(int i = 1;i<=Q;i++){
		cin>>num[i];
	}
	for(int i = 1;i<=Q;i++){
		deb printf("%lld\n",num[i]);
		doit(f[num[i]]);
	}
	for(int i = 1;i<=n;i++){
		cout<<a[i]%mod<<" ";
	}
	
	
	return 0;
}
