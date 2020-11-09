#include <bits/stdc++.h>
#define deb if(debug)
#define int long long
const int debug =0;
#define fo(i,x) for(int i=1;i<=(x);++i)
#define fo_(i,b,x) for(int i = b;i<=x;++i)
#define re(i,b,x) for(int i = b;i>=x;--i)
#define N 100010
#define ull unsigned long long
using namespace std;
vector<int > ok[N];
signed main(){
	freopen("zoo.in","r",stdin);
	freopen("zoo.out","w",stdout);
	int n,m,c,k;
	cin>>n>>m>>c>>k;
	ull an = 0;
	fo(i,n) {
		ull x;cin>>x;
		an |= x;
	}
	deb cout<<an<<endl;
	fo(i,m){
		int x,y;
		cin>>x>>y;
		ok[x].push_back(y);
	}
	ull ans = 1ULL;
	for(int i = k-1;i>=0;i--){
		deb cout<<((an>>i)&(1ULL))<<endl;
		int x = (an>>i)&(1ULL);
		if(x){
			ans*=2;
		}else{
			deb cout<<"sz"<<ok[i].size()<<endl;
			if(ok[i].size()==0) ans*=2;
			else ans*=1;
		}
	} 
	cout<<ans-n;
	return 0;
}
